#include "MovingAverage.hpp"
#include <iostream>

MovingAverageCalculator::MovingAverageCalculator(int numPeriods)
    : m_numPeriods(numPeriods)
{
}

MovingAverageCalculator::~MovingAverageCalculator()
{
}

MovingAverageCalculator::MovingAverageCalculator(const MovingAverageCalculator &ma)
    : m_numPeriods(ma.m_numPeriods)
{
}

MovingAverageCalculator &MovingAverageCalculator::operator=(const MovingAverageCalculator &ma)
{
  if (this != &ma)
  {
    m_numPeriods = ma.m_numPeriods;
    m_prices = ma.m_prices;
  }
  return *this;
}

std::vector<double> MovingAverageCalculator::calculateMovingAverage()
{
  std::vector<double> ma;
  double sum = 0;
  for (int i = 0; i < m_prices.size(); ++i)
  {
    sum += m_prices[i];
    if (i >= m_numPeriods)
    {
      ma.push_back(sum / m_numPeriods);
      sum -= m_prices[i - m_numPeriods];
    }
  }
  return ma;
}

std::vector<double> MovingAverageCalculator::calculateEMovingAverage()
{
  std::vector<double> ema;
  double sum = 0;
  double multiplier = 2.0 / (m_numPeriods + 1);
  for (int i = 0; i < m_prices.size(); ++i)
  {
    sum += m_prices[i];
    if (i == m_numPeriods)
    {
      ema.push_back(sum / m_numPeriods);
      sum -= m_prices[i - m_numPeriods];
    }
    else if (i > m_numPeriods)
    {
      double val = (1 - multiplier) * ema.back() + multiplier * m_prices[i];
      ema.push_back(val);
    }
  }
  return ema;
}

void MovingAverageCalculator::addPriceQuote(double close)
{
  m_prices.push_back(close);
}