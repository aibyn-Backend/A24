#include <string>
#include <iostream>
using namespace std;
class Animal
{
private:
    string type;
    int age;
    string name;
public:
    Animal(const string& animalType,int animalAge,const string& animalName):type(animalType),age(animalAge),name(animalName){}
    void animal_info() const
    {
        cout << type << ":" << endl << "Имя: " << name << endl << "Лет: " << age << endl;
    }
};
int main()
{
    Animal cat("кошка",3,"Барсик");
    cat.animal_info();
    return 0;
}
