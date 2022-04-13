#include <iostream>
#include "SimpleInterestRates/SimpleInterestRates.hpp"
#include "CompoundInterestRates/CompoundInterest.hpp"

enum class Choice
{
    SimpleInterestRates = 0,
    Go_Out = 1,
    CompoundInterest = 2,
};

const char *ChoiceTypes[3] = {"SimpleInterestRates", "Go_Out", "CompoundInterest"};

int main(int argc, char **arg)
{
    Choice choice = Choice::SimpleInterestRates;
    int from;

    while (true)
    {
        std::cout << "Enter the choice: \n\t"
                  << ChoiceTypes[(int)Choice::SimpleInterestRates] << ": " << (int)Choice::SimpleInterestRates << "\n\t"
                  << ChoiceTypes[(int)Choice::CompoundInterest] << ": " << (int)Choice::CompoundInterest << "\n\t"
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
        case Choice::CompoundInterest:
            std::cout << "CompoundInterestRates - multiplePeriod: " << multiplePeriod(0.06, 10000, 10) << "\n";
            std::cout << "CompoundInterestRates - continuousCompounding: " << continuousCompounding(0.06, 10000, 10) << "\n";
            break;
        default:
            std::cout << "Invalid Selection\n";
            break;
        }
    }

    return 0;
}
