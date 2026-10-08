#include <iostream>

int sum(int a, int b);
void printHello()
{
    std::cout << "Привет!\n";
}
int sum(int a, int b)
{
    return a + b;
}
void greet(std::string name = "мир")
{
    std::cout << "Привет, " << name << "!\n";
}
double sum(double a, double b)
{
    return a + b;
}
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    printHello();
    std::cout << sum(2,3) << '\n';
    std::cout << sum(2.5,3.5) << '\n';
    greet();
    greet("Аня");
    std::cout << factorial(5) << '\n';
    auto square = [](int n) {return n * n;};
    std::cout << square(4) << '\n';
}
