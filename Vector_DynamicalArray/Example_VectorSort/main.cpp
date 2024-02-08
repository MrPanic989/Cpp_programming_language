#include <iostream>
#include <vector>
#include <algorithm>

void print_vector_info(const std::vector<int> &vec)
{
                            //size <= capacity
    std::cout << "Vector size: " << vec.size() << '\n';     //Number of actual elements of the vector
    std::cout << "Vector capacity: " << vec.capacity() << '\n'; //Number of elements that can be held
                                                                //in current allocated sotorage
    std::cout << "Vector is empty: " << std::boolalpha << vec.empty() << '\n';  // true of false

    std::cout << '\n';
}

void print_vector(const std::vector<int> &vector)
{
    for(std::size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << "Vector[" << i << "] = " << vector[i] << '\n';
    }
    std::cout << '\n';
}
                    //int because our vector has integer values
bool sort_ascending(const int i, const int j)
{
    return i < j;
}

bool sort_descending(const int i, const int j)
{
    return i > j;
}

int main(void)
{
    auto my_vector = std::vector<int>{-1, 20, -22, -33, 42, 2};
    print_vector(my_vector);
    print_vector_info(my_vector);
                //We have to give the function a valid range
    std::sort(my_vector.begin(), my_vector.end());  //Per default it sorts ascending
    print_vector(my_vector);

    //If we want to decide ourselfs how the vector should be sorted, we can write our own
    //function (has to be bool) and give it to std::sort() as attribute
    std::sort(my_vector.begin(), my_vector.end(), sort_descending);  //Per default it sorts ascending
    print_vector(my_vector);


    return 0;
}
