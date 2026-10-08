#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::string choice;
    std::unordered_map<std::string,std::unordered_map<std::string, std::string>> user=
    {
        {"user1", {
            {"name","nagi"},
            {"age","19"},
            {"programming_language","python,javascript"},
            {"development_directions","backend"},
            {"Developer_levels","junior"}
        }},
        {"user2",{
            {"name","isagi"},
            {"age","23"},
            {"programming_language","html,css,TypeScript"},
            {"development_directions","frontend"},
            {"Developer_levels","meddle"}
        }},
        {"user3",{
            {"name","rin"},
            {"age","23"},
            {"programming_language","c++,python,sql"},
            {"development_directions","cyber_securety"},
            {"Developer_levels","meddle"}
        }}
    };
    std::cout << "user1: \nuser2: \nuser3: " << std::endl;
    while (true)
    {
        std::cout << "Выбор: ";
        std::cin >> choice;
        if (choice == "user1")
        {
            std::cout << "name:" << user["user1"]["name"] << std::endl;
            std::cout << "age: "<< user["user1"]["age"] << std::endl;
            std::cout << "programming laguage: " << user["user1"]["programming_language"] << std::endl;
            std::cout << "development directions: " << user["user1"]["development_directions"] << std::endl;
            std::cout << "developer levels: " << user["user1"]["Developer_levels"] << std::endl;
        }
        else if (choice == "user2")
        {
            std::cout << "name: " << user["user2"]["name"] << std::endl;
            std::cout << "age:" << user["user2"]["age"] << std::endl;
            std::cout << "programming laguage: " << user["user2"]["programming_language"] << std::endl;
            std::cout << "development directions: " << user["user2"]["development_directions"] <<std::endl;
            std::cout << "developer levels" << user["user2"]["Developer_levels"] << std::endl;
        }
        else if (choice == "user3")
        {
            std::cout << "name: " << user["user3"]["name"] << std::endl;
            std::cout << "age: " << user["user3"]["age"] << std::endl;
            std::cout << "programming laguage: " << user["user3"]["programming_language"] << std::endl;
            std::cout << "development directions: " << user["user3"]["development_directions"] << std::endl;
            std::cout << "developer levels: " << user["user3"]["Developer_levels"] << std::endl;
        }
        else
        {
            std::cout << "нету " << choice;
            continue;
        }
    }
}
