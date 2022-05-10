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
  CreditRisk::RiskType risk = CreditRisk::RiskType::AAA;
  for (int i = 0; i < m_creditRisks.size(); ++i)
  {
    if (m_creditRisks[i]->getRating() < risk)
    {
      risk = m_creditRisks[i]->getRating();
    }
  }
  return risk;
}

CreditRisk::RiskType RiskCalculator::portfolioMinRisk()
{
  CreditRisk::RiskType risk = CreditRisk::RiskType::C;
  for (int i = 0; i < m_creditRisks.size(); ++i)
  {
    if (m_creditRisks[i]->getRating() > risk)
    {
      risk = m_creditRisks[i]->getRating();
    }
  }
  return risk;
}
