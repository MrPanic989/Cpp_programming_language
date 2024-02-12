#include <iostream>
#include <string>
                                                //Must be a const reference
void print_found_index(const std::size_t idx, const std::string &func_name)
{
    std::cout << "Function: " << func_name << '\n';
    if(idx != std::string::npos)
        std::cout << "Found at index: " << idx << '\n';
    else
        std::cout << "Not found!" << idx << '\n';
}

int main(void)
{
    const auto text = std::string{"Eins, Zwei, Drei"};

    const auto search_str1 = "i";
    const auto idx1 = text.find(search_str1);    //find() returns just the index of the first matching
    print_found_index(idx1, "find");        //element of the string

    const auto search_str2 = "i";
    const auto idx2 = text.rfind(search_str2);  //rfind() returns just the index of the last matching
    print_found_index(idx2, "rfind");        //element of the string (reverse)

    //It is not a substrign, rather two values which the find_fist_of() sholud look up
    //It returns the index of the fist element of the string it finds, either Z or D
    const auto search_str3 = "DZ";
    const auto idx3 = text.find_first_of(search_str3);
    print_found_index(idx3, "find_first_of");

    //Works just like find_fist_of() but returns the last index of those elements
    const auto search_str4 = "DZ";
    const auto idx4 = text.find_last_of(search_str4);
    print_found_index(idx4, "find_last_of");
    //Note: if you don't want to start an index 0, just ad a index number at the end as attribute
    //E.g.: const auto indx1 = text.find(search_str1, 7);

    auto text2 = text;  //And this is how easy it is to copy a string into another string in C++
    std::cout << "text2: " << text2 << '\n';
    text2.clear();  //deletes the content and gives memory on the heap free
    std::cout << "text2: " << text2 << '\n';

    auto text3 = text + ", Vier, Fünf"; //This is how you concate two strings. It must be a const
    std::cout << "text3: " << text3 << '\n';    //char array or a string object

    auto text4 = text3; //Similar to the method above, but in this was you can concatenate a single char
    text4.append({' ', ',', 'S', 'e', 'c', 'h', 's'});  //or an initializer list
    std::cout << "text4: " << text4 << '\n';

    auto s1 = std::string{"Michael"};
    auto s2 = std::string{"Mikael"};
    std::cout << "s1 == s2: " << std::boolalpha << (s1 == s2) << '\n';
    const auto compared = s1.compare(s2);   //Returns 0 for true, a negative number if the values of
                                        //s1 are lesser than s2 (ASCII table), and a positive number
                                        //vice versa
    std::cout << "s1.compare(s2): " << compared << '\n';

    const auto search_str = "ch";
    const auto idx = s1.find(search_str);
    if(idx != std::string::npos)
        s1.replace(idx, 2, "k");    //from where, how many, with what

    const auto sub_str = s1.substr(2, 3);   //from where, how many. Considerate the range!!
    std::cout << sub_str << '\n';

    //Iterators are Pointers:
    const auto first_char_of_text = text[0];
    std::cout << first_char_of_text << '\n';

    for(auto iter = text.rbegin(); iter != text.rend(); ++iter) //reverse
    {
        std::cout << *iter;
    }
    std::cout << '\n';
    for(const auto &c : text)
    {
        std::cout << c;
    }
    std::cout << '\n';

    const auto value = 10.3f;
    const auto val_str = std::to_string(value);     //converts to strign. In contrast to atoi()
    std::cout << val_str << '\n';

    return 0;
}
