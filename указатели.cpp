#include <iostream>
#include <string>

int main()
{
    int a = 10;
    int b = 20;
    int* ptr = &a;
    std::cout << "a=" << a << std::endl;
    std::cout << "&a=" << &a << std::endl;
    std::cout << "ptr=" << ptr << std::endl;
    std::cout << "*ptr=" << *ptr << std::endl;
    *ptr = 15;
    std::cout << "posle izmeneniya a=" << a << std::endl;
    int* ptr2 = &b;
    std::cout << "b=" << *ptr2 << std::endl;
    int arr[5] = {1,2,3,4,5};
    int* arrPtr = arr;
    std::cout << "arr[0]=" << arr[0] << std::endl;
    std::cout << "*(arrPtr+2)=" << *(arrPtr + 2) << std::endl;
    return 0;
}
