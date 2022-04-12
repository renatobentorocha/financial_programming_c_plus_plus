#include <iostream>
#include "SimpleInterestRateCalculator.hpp"

double calculateSimpleInterestRate(double value, double rate)
{
  SimpleInterestRateCalculator irCalculator(rate);
  double res = irCalculator.singlePeriod(value);

  return res;
}