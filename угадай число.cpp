#include <iostream>
#include <limits>
#include <random>
#include <string>

int main()
{
    std::string hard;
    int upper_bound = 0;
    int attempts = 3;
    int guess = 0;
    std::cout << "Угадай число\n";
    std::cout << "Легкий || Средний || Сложный\n";
    while (true)
    {
        std::cout << "Выбор: ";
        std::cin >> hard;
        if (hard == "легкий")
        {
            upper_bound = 10;
        }
        else if (hard == "средний")
        {
            upper_bound = 50;
        }
        else if (hard == "сложный")
        {
            upper_bound = 100;
        }
        else
        {
            std::cout << "Только три варианта\n";
            continue;
        }
        break;
    }
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> range(1, upper_bound);
    const int secret_number = range(generator);
    while (attempts > 0)
    {
        std::cout << "Осталось попыток: " << attempts << '\n';
        std::cout << "Введи число от 1 до " << upper_bound;
        if (!(std::cin >> guess))
        {
            std::cout << "Введи целое число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        if (guess < 1 || guess > upper_bound)
        {
            std::cout << "Число должно быть от 1 до " << upper_bound << "\n";
            continue;
        }
        if (guess == secret_number)
        {
            std::cout << "Победа\n";
            return 0;
        }
        --attempts;
        if (guess < secret_number)
        {
            std::cout << "больше\n";
        }
        else
        {
            std::cout << "меньше.\n";
        }
    }
    std::cout << "Попытки закончились загаданое число " << secret_number << "\n";
}
