/*We will use an Alias Type in this exercise:
#include <utility>
#include <map>
#include <string>
#include <cstdint>

using Friends = std::map<std::string, std::pair<std::int32_t, std::int32_t>>;

- Task 1:
Create a map of the type Friends in your main function. The map saves a pair with the attributes
"age" (int) and "weight" (int) for the respective name of a person (key).
Add at least 2 people to this map.

- Task 2;
Create the functions
    std::string_view get_oldest_friend(const Friends &friends);
    std::string_view get_heaviest_friend(const Friends &friends);
To display the oldest person or the heaviest person from your map. Apply both functions to your friends'
map and output the data. That is, determine who is the oldest and who is the heaviest person.
*/
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>

#include "exercise.hpp"

int main()
{
    // Exercise 1
    auto friends = Friends{};

    //With array or vector this would result an error, because we want to access something
    //that doesn't exist jet. For a map this isn't a problem at all, we just create a new one instead
    friends["Jan"] = std::make_pair(23, 68);
    friends["Dennis"] = std::make_pair(27, 75);
    friends["Peter"] = std::make_pair(54, 70);
    friends["Kathrin"] = std::make_pair(30, 60);
    friends["Lisa"] = std::make_pair(26, 65);

    // Exercise 2
    const auto oldest_friend = get_oldest_friend(friends);
    const auto heaviest_friend = get_heaviest_friend(friends);

    std::cout << "My oldest friend: " << oldest_friend << '\n';
    std::cout << "My heaviest friend: " << heaviest_friend << '\n';

    return 0;
}
