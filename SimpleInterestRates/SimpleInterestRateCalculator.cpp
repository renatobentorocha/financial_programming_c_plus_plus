#include "SimpleInterestRateCalculator.hpp"

SimpleInterestRateCalculator::SimpleInterestRateCalculator(double rate)
    : m_rate(rate)
{
}

SimpleInterestRateCalculator::~SimpleInterestRateCalculator()
{
}

SimpleInterestRateCalculator::SimpleInterestRateCalculator(const SimpleInterestRateCalculator &v)
    : m_rate(v.m_rate)
{
}

SimpleInterestRateCalculator &SimpleInterestRateCalculator::operator=(const SimpleInterestRateCalculator &v)
{
  if (&v != this)
  {
    this->m_rate = v.m_rate;
  }
  return *this;
}