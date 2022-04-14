#include <iostream>
#include "SimpleInterestRates/SimpleInterestRates.hpp"
#include "CompoundInterestRates/CompoundInterest.hpp"
#include "CashFlow/CashFlowCalculator.hpp"
#include "ModelingBonds/BondCalculator.hpp"

enum class Choice
{
    Go_Out = 0,
    SimpleInterestRates = 1,
    CompoundInterest = 2,
    CashFlow = 3,
    ModelingBonds = 4,
};

const char *ChoiceTypes[5] = {"Go_Out", "SimpleInterestRates", "CompoundInterest", "CashFlow", "ModelingBonds"};

void cashFlow()
{
    double rate = 1.0;
    double value = 1.0;
    unsigned period = 1;

    std::cout << "Enter <interest rate> or -1" << std::endl;
    std::cin >> rate;

    if (rate == -1)
        return;

    CashFlowCalculator cfc(rate);

    while (true)
    {

        std::cout << "Enter <period> or -1" << std::endl;
        std::cin >> period;

        if (period == -1)
            break;

        std::cout << "Enter <value> or -1" << std::endl;
        std::cin >> value;

        if (value == -1)
            break;

        cfc.addCashPayment(value, period);
    }

    double result = cfc.presentValue();
    std::cout << " The present value is " << result << std::endl;
}

int main(int argc, char **arg)
{
    Choice choice = Choice::SimpleInterestRates;
    int from;

    while (true)
    {
        std::cout << "Enter the choice: \n\t"
                  << ChoiceTypes[(int)Choice::SimpleInterestRates] << ": " << (int)Choice::SimpleInterestRates << "\n\t"
                  << ChoiceTypes[(int)Choice::CompoundInterest] << ": " << (int)Choice::CompoundInterest << "\n\t"
                  << ChoiceTypes[(int)Choice::CashFlow] << ": " << (int)Choice::CashFlow << "\n\t"
                  << ChoiceTypes[(int)Choice::ModelingBonds] << ": " << (int)Choice::ModelingBonds << "\n\t"
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
            std::cout << "CompoundInterestRates - multiplePeriod: " << multiplePeriod(0.1, 100, 2) << "\n";
            std::cout << "CompoundInterestRates - continuousCompounding: " << continuousCompounding(0.1, 100, 2) << "\n";
            break;
        case Choice::CashFlow:
        {
            cashFlow();
            break;
        }
        case Choice::ModelingBonds:
        {
            std::cout << "usage: progName <institution> <principal> <coupon> <num periods>"
                      << std::endl;

            std::string issuer = "";
            double principal = 0;
            double coupon = 0;
            int num_periods = 0;

            std::cin >> issuer;
            std::cin >> principal;
            std::cin >> coupon;
            std::cin >> num_periods;

            BondCalculator bc(issuer, principal, coupon, num_periods);

            std::cout << "reading information for bond issued by " << issuer << std::endl;
            std::cout << "the internal rate of return is " << bc.interestRate() << std::endl;

            break;
        }
        default:
            std::cout << "Invalid Selection\n";
            break;
        }
    }

    return 0;
}
