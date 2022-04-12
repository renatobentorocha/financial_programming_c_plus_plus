#include <iostream>
#include "SimpleInterestRates/SimpleInterestRates.hpp"

enum class Choice
{
    SimpleInterestRates = 0,
    Go_Out = 1,
};

const char *ChoiceTypes[2] = {"SimpleInterestRates", "Go_Out"};

int main(int argc, char **arg)
{
    Choice choice = Choice::SimpleInterestRates;
    int from;

    while (true)
    {
        std::cout << "Enter the choice: \n\t"
                  << ChoiceTypes[(int)Choice::SimpleInterestRates] << ": " << (int)Choice::SimpleInterestRates << "\n\t"
                  << ChoiceTypes[(int)Choice::Go_Out] << ": " << (int)Choice::Go_Out;

        std::cout << "\n\n";

        std::cin >> from;

        choice = (Choice)from;

        if (choice == Choice::Go_Out)
        {
            std::cout << "Go_Out\n";
            break;
        }

        switch (choice)
        {
        case Choice::SimpleInterestRates:
            std::cout << "SimpleInterestRates: " << calculateSimpleInterestRate(100, 1) << "\n";
            break;
        default:
            std::cout << "Invalid Selection\n";
            break;
        }
    }

    return 0;
}
