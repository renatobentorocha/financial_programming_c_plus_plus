#include "CorrelationCalculator.hpp"
#include "../TimeSeries/TimeSeries.hpp"
#include <iostream>

CorrelationCalculator::CorrelationCalculator(TimeSeries &a, TimeSeries &b)
    : m_tsA(a),
      m_tsB(b)
{
}

CorrelationCalculator::~CorrelationCalculator()
{
}
CorrelationCalculator::CorrelationCalculator(const CorrelationCalculator &c)
    : m_tsA(c.m_tsA),
      m_tsB(c.m_tsB)
{
}

CorrelationCalculator &CorrelationCalculator::operator=(const CorrelationCalculator &c)
{
  if (this != &c)
  {
    m_tsA = c.m_tsA;
    m_tsB = c.m_tsB;
  }
  return *this;
}

double CorrelationCalculator::correlation()
{
  double sum = 0;
  double meanA = m_tsA.mean();
  double meanB = m_tsB.mean();

  if (m_tsA.size() != m_tsB.size())
  {
    std::cout << "error: number of observations is different" << std::endl;
    return -1;
  }

  for (int i = 0; i < m_tsA.size(); ++i)
  {
    auto val = (m_tsA.elem(i) - meanA) * (m_tsB.elem(i) - meanB);
    sum += val;
  }

  double stDevA = m_tsA.stdDev();
  double stDevB = m_tsB.stdDev();
  sum /= (stDevA * stDevB);

  return sum / (m_tsB.size() - 1);
}