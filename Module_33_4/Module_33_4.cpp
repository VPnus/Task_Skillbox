#include <iostream>

template<typename T>
double calculateAverage(T array[8])
{
    double sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += static_cast<double>(array[i]);
    }
    return sum / 8;
}

template<typename T>
void input(T array[8])
{
    std::cout << "Fill the array (8): ";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

int main()
{
    double array[8];
    input(array);
    double average = calculateAverage(array);
    std::cout << "Average: " << average << std::endl;

    return 0;
}