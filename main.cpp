#include <iostream>
#include "SimpleInterestRates/SimpleInterestRates.hpp"
#include "CompoundInterestRates/CompoundInterest.hpp"
#include "CashFlow/CashFlowCalculator.hpp"
#include "ModelingBonds/BondCalculator.hpp"
#include "MovingAverage/MovingAverage.hpp"
#include "CalculatingVolatility/VolatilityCalculator.hpp"

enum class Choice
{
    Go_Out = 0,
    SimpleInterestRates = 1,
    CompoundInterest = 2,
    CashFlow = 3,
    ModelingBonds = 4,
    MovingAverage = 5,
    CalculatingVolatility = 6,
};

const char *ChoiceTypes[7] = {"Go_Out", "SimpleInterestRates", "CompoundInterest", "CashFlow", "ModelingBonds", "MovingAverage", "CalculatingVolatility"};

void simpleInterestRates()
{
    std::cout << "SimpleInterestRates: " << calculateSimpleInterestRate(100, 1) << "\n";
}

void compoundInterest()
{
    std::cout << "CompoundInterestRates - multiplePeriod: " << multiplePeriod(0.1, 100, 2) << "\n";
    std::cout << "CompoundInterestRates - continuousCompounding: " << continuousCompounding(0.1, 100, 2) << "\n";
}

void modelingBonds()
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
}

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

void movingAverage()
{
    int numberOfPeriods = 0;
    double price;

    std::cout << "Enter the number of periods: <periods>" << std::endl;
    std::cin >> numberOfPeriods;

    std::cout << "Enter the prices or -1 to break: <prices>" << std::endl;
    MovingAverageCalculator calculator(numberOfPeriods);

    for (;;)
    {
        std::cin >> price;

        if (price == -1)
            break;

        calculator.addPriceQuote(price);
    }

    std::vector<double> ma = calculator.calculateMovingAverage();
    for (int i = 0; i < ma.size(); ++i)
    {
        std::cout << "average value " << i << " = " << ma[i] << std::endl;
    }

    std::vector<double> ema = calculator.calculateEMovingAverage();
    for (int i = 0; i < ema.size(); ++i)
    {
        std::cout << "exponential average value " << i << " = " << ema[i] << std::endl;
    }
}

void volatilityCalculator()
{
    double price;
    VolatilityCalculator vc;
    while (true)
    {
        std::cout << "Enter a price quote" << std::endl;
        std::cin >> price;

        if (price == -1)
            break;

        vc.addPrice(price);
    }

    std::cout << "range volatility is " << vc.rangeVolatility() << std::endl;
    std::cout << "average daily range is " << vc.avgDailyRange() << std::endl;
    std::cout << "standard deviation is " << vc.stdDev() << std::endl;
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
                  << ChoiceTypes[(int)Choice::MovingAverage] << ": " << (int)Choice::MovingAverage << "\n\t"
                  << ChoiceTypes[(int)Choice::CalculatingVolatility] << ": " << (int)Choice::CalculatingVolatility << "\n\t"
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
        {
            simpleInterestRates();
            std::cout << std::endl;
            break;
        }
        case Choice::CompoundInterest:
        {
            compoundInterest();
            std::cout << std::endl;
            break;
        }
        case Choice::CashFlow:
        {
            cashFlow();
            std::cout << std::endl;
            break;
        }
        case Choice::ModelingBonds:
        {
            modelingBonds();
            std::cout << std::endl;

            break;
        }
        case Choice::MovingAverage:
        {
            movingAverage();
            std::cout << std::endl;
            break;
        }
        case Choice::CalculatingVolatility:
        {
            volatilityCalculator();
            std::cout << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid Selection\n";
            break;
        }
        }
    }

    return 0;
}
