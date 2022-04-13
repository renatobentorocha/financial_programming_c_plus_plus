#include "CompoundInterestRateCalculator.hpp"
#include <cmath>

CompoundInterestRateCalculator::CompoundInterestRateCalculator(double rate)
    : m_rate(rate)
{
}

CompoundInterestRateCalculator::~CompoundInterestRateCalculator()
{
}

CompoundInterestRateCalculator::CompoundInterestRateCalculator(const CompoundInterestRateCalculator &v)
    : m_rate(v.m_rate)
{
}

CompoundInterestRateCalculator &CompoundInterestRateCalculator::operator=(const CompoundInterestRateCalculator &v)
{
  if (this != &v)
  {
    this->m_rate = v.m_rate;
  }
  return *this;
}

double CompoundInterestRateCalculator::multiplePeriod(double value, int numPeriods)
{
  double f = value * pow(1 + m_rate, numPeriods);
  return f;
}

double CompoundInterestRateCalculator::continuousCompounding(double value, int numPeriods)
{
  double f = value * exp(m_rate * numPeriods);
  return f;
}