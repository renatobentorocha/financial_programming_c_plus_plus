#include "RiskCalculator.hpp"

RiskCalculator::RiskCalculator()
{
}

RiskCalculator::~RiskCalculator()
{
}

RiskCalculator::RiskCalculator(const RiskCalculator &v)
    : m_creditRisks(v.m_creditRisks)
{
}

RiskCalculator &RiskCalculator::operator=(const RiskCalculator &v)
{
  if (this != &v)
  {
    m_creditRisks = v.m_creditRisks;
  }
  return *this;
}

void RiskCalculator::addCreditRisk(std::shared_ptr<CreditRisk> risk)
{
  m_creditRisks.push_back(risk);
}

CreditRisk::RiskType RiskCalculator::portfolioMaxRisk()
{
  auto risk = CreditRisk::RiskType::AAA;

  for (auto p = m_creditRisks.begin(); p != m_creditRisks.end(); ++p)
  {
    if ((*p)->getRating() > risk)
    {
      risk = (*p)->getRating();
    }
  }

  return risk;
}

CreditRisk::RiskType RiskCalculator::portfolioMinRisk()
{
  auto risk = CreditRisk::RiskType::C;

  for (auto p = m_creditRisks.begin(); p != m_creditRisks.end(); ++p)
  {
    if ((*p)->getRating() < risk)
    {
      risk = (*p)->getRating();
    }
  }

  return risk;
}
