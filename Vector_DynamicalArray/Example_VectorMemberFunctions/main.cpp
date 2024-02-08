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
                    //int because our vector has type int
bool is_negative(const int value)
{
    return value < 0;
}

int main(void)
{
    const auto init_length = 10u;
    const auto init_value = 0;
    //std::vector<int> my_vector(10, 0);
    auto my_vector = std::vector<int>(init_length, init_value);
    print_vector_info(my_vector);

    my_vector.push_back(23);
    print_vector_info(my_vector);
                                        //Brace initial list for direct initialization with values
    auto my_vector2 = std::vector<int>{1, 2, 3, 4, 5};
    print_vector(my_vector2);
    print_vector_info(my_vector2);

    auto p = my_vector2.data();  //data() returns a pointer at the first element of the vector
    std::cout << *p << '\n';
    p += 2;
    std::cout << *p << '\n';
    std::cout << std::endl;

    auto& f = my_vector2.front();  //reference of the first element
    std::cout << f << '\n';
    f = -1;
    std::cout << f << '\n';
    std::cout << my_vector2[0] << '\n';
    std::cout << std::endl;

    auto& b = my_vector2.back();  //reference of the last element
    std::cout << b << '\n';
    b = 22;
    std::cout << b << '\n';
    std::cout << my_vector2[my_vector2.size() - 1] << '\n';
    std::cout << std::endl;

    print_vector(my_vector2);

    //Iterators: acts like pointer that iterates through the vector
    auto begin = my_vector2.begin();    //pointer on the first element
    auto end = my_vector2.end();    //pointer on the first element that lies out of range
    std::cout << *begin << '\n';
    std::cout << *end << '\n';

    auto i = std::size_t{0};
    for(auto iter = my_vector2.begin(); iter != my_vector2.end(); ++iter)
    {

        std::cout << "Vector[" << i << "]: " << *iter << '\n';
        ++i;
    }
    std::cout << std::endl;

    auto my_vector3 = std::vector<int>{-1, -20, -1, 3, 2, -1, 83, -2};
    print_vector(my_vector3);
    print_vector_info(my_vector3);

    //For deleting certain elements, we can use remove() and erase().
    //Firstly we have to (re)move the element we want at the end of the vector.
    //For erase must define a ragne: first element to be deleted - to last element to be deleted
    auto remove_it = std::remove(my_vector3.begin(), my_vector3.end(), -1); //returns the first iterator
                                                    //that points at the first elemenet of the value to be deleted
    my_vector3.erase(remove_it, my_vector3.end());
    print_vector(my_vector3);
    print_vector_info(my_vector3);
    /*
    //We can also modify the std::remove, e.g. to delete all negative values
    auto remove_neg_it = std::remove(my_vector3.begin(), my_vector3.end(), is_negative);
    my_vector3.erase(remove_neg_it, my_vector3.end());
    print_vector(my_vector3);
    print_vector_info(my_vector3);
    */

    return 0;
}
