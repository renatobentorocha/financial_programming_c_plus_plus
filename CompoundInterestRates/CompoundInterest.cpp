#include "CompoundInterest.hpp"
#include "CompoundInterestRateCalculator.hpp"

double multiplePeriod(double rate, double value, int numPeriods)
{
  CompoundInterestRateCalculator calculator(rate);
  return calculator.multiplePeriod(value, numPeriods);
}

double continuousCompounding(double rate, double value, int numPeriods)
{
  CompoundInterestRateCalculator calculator(rate);
  return calculator.continuousCompounding(value, numPeriods);
}