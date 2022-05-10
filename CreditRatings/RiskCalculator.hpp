#ifndef __FinancialSamples__RiskCalculator__
#define __FinancialSamples__RiskCalculator__

#include "CreditRisk.hpp"
#include <memory>
#include <vector>

// calculates the risk associated to a portfolio
class RiskCalculator
{
public:
  RiskCalculator();
  ~RiskCalculator();
  RiskCalculator(const RiskCalculator &v);
  RiskCalculator &operator=(const RiskCalculator &v);
  void addCreditRisk(std::shared_ptr<CreditRisk> risk);
  CreditRisk::RiskType portfolioMaxRisk();
  CreditRisk::RiskType portfolioMinRisk();

private:
  std::vector<std::shared_ptr<CreditRisk>> m_creditRisks;
};

#endif /* defined(__FinancialSamples__RiskCalculator__) */