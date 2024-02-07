#include <iostream>
#include <cstdint>
#include <string>

/*An enum is a list of different categories,
where exactly one category can later be assigned to a variable
int STUDENT = 1;
int TUTOR = 2;
int INSTRUCTOR = 3;
int ADMIN = 4;
*/
/*Should be in caps lock, because they act like constant global variables and it is
best practice to put infront of the variable the name of the enum to avoid declarations conflicts!
enum PermissionLevel
{
    PermissionLevel_STUDENT,
    PermissionLevel_TUTOR,
    PermissionLevel_INSTRUCTOR,
    PermissionLevel_ADMIN,
};
This was the C style approach.
*/
//With the keyword 'class' we transform the variables from a global to a local scope
enum class PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4,
};

enum class ServerGroup
{
    ADMIN,
    USER,
};

/*A struct is a data structure where we can combine
 multiple attributes from different data types into one coherent data type and we can
 then create variables for this data structure, or struct for short
*/
struct UserData
{
    std::string name;
    std::uint32_t id;
    PermissionLevel permission_level;
};
            //const = read only
void print_user(const UserData &user)
{
    std::cout << user.name << " has the id " << user.id << " and is a ";

    switch(user.permission_level)
    {
        case PermissionLevel::STUDENT:
        {
            std::cout << "STUDENT!\n";
            break;
        }
        case PermissionLevel::TUTOR:
        {
            std::cout << "TUTOR!\n";
            break;
        }
        case PermissionLevel::INSTRUCTOR:
        {
            std::cout << "INSTRUCTOR!\n";
            break;
        }
        case PermissionLevel::ADMIN:
        {
            std::cout << "ADMIN!\n";
            break;
        }
        default:
        {
            std::cout << "UNKNOWN STATE!\n";
            break;
        }
    }
}


int main(void)
{
    auto permission_level_me = PermissionLevel::STUDENT;

    //Version 1 of a initialization
    UserData mr_huber = {"Michael", 10034284, PermissionLevel::INSTRUCTOR};

    //Version 2, and certainly the better way, of initialization
    auto peter = UserData{.name = "Peter", .id = 10388484, .permission_level = PermissionLevel::TUTOR};

    //Verson 3, the data is unknown at the time of declaration
    UserData new_entity;
    //.. at a leter moment in our code
    new_entity.name = "William";
    new_entity.id = 109392;
    new_entity.permission_level = PermissionLevel::STUDENT;

    //If you want to check only one condition, then use the if-else statements
    if(permission_level_me == PermissionLevel::STUDENT)
    {
        std::cout << "Hello! I'm a student at the University of Applied Science!" << '\n';
    }

    //If you want to check multiple conditions at once, then use the switch() statement
    switch(mr_huber.permission_level)
    {
        case PermissionLevel::STUDENT:
        {
            std::cout << "Hello STUDENT!\n";
            break;
        }
        case PermissionLevel::TUTOR:
        {
            std::cout << "Hello TUTOR!\n";
            break;
        }
        case PermissionLevel::INSTRUCTOR:
        {
            std::cout << "Hello INSTRUCTOR!\n";
            break;
        }
        case PermissionLevel::ADMIN:
        {
            std::cout << "Hello ADMIN!\n";
            break;
        }
        default:
        {
            std::cout << "UNKNOWN STATE!\n";
            break;
        }
    }

    print_user(peter);
    print_user(new_entity);

    return 0;
}
