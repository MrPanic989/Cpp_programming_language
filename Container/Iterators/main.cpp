#include <iostream>
#include <vector>
#include <iterator>
#include <list>

int main(void)
{
    auto my_vector = std::vector{0, 1, 2, 3, 4, 5};
    auto my_list = std::list{0, 1, 2, 3, 4, 5};

    auto vec_it = my_vector.begin();
    std::advance(vec_it, 2); // it += 2;    vec_it actually points now at the value two, but doesn't return value
    auto list_it = my_list.begin();
    std::advance(list_it, 2); // it += 2;

    std::cout << "Vector[2] = " << *vec_it << '\n';
    std::cout << "List[2] = " << *list_it << '\n';

    auto dist1 = std::distance(vec_it, my_vector.end());    //from current pointer of vec_it to the end
    auto dist2 = std::distance(my_vector.begin(), vec_it);
    std::cout << dist1 << " " << dist2 << '\n';

    auto prev = std::prev(vec_it);  //in contrast to std::advance, std::prev and std::next returns
    std::cout << *prev << '\n';     //a value, that's why we need a variable for them
    auto next = std::next(vec_it);
    std::cout << *next << '\n';

    //ForwardIterator
    auto it1 = my_vector.begin();
    auto it2 = my_vector.end();

    for(; it1 != it2; ++it1)
    {
        *it1 = 1;
    }

    //BidirectionalIterator
    auto it3 = my_vector.rbegin();
    auto it4 = my_vector.rend();

    for(; it3 != it4; ++it3)
    {
        *it3 = 2;
    }

    // Const ForwardIterator
    auto it5 = my_vector.cbegin();
    auto it6 = my_vector.cend();

    for(; it5 != it6; ++it5)
    {
        //*it5 = 1;     const means read-only, can't be modified
        std::cout << *it5 << '\n';
    }

    // Const BidirectionalIterator
    auto it7 = my_vector.crbegin();
    auto it8 = my_vector.crend();

    for (; it7 != it8; ++it7)
    {
        //*it7 = 2;
        std::cout << *it7 << '\n';
    }

    return 0;
}
