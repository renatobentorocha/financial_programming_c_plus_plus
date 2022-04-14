#ifndef __FinancialSamples__BondCalculator__
#define __FinancialSamples__BondCalculator__

#include <string>

class BondCalculator
{
public:
  BondCalculator(const std::string institution, int numPeriods, double principal, double couponValue);
  BondCalculator(const BondCalculator &v);
  BondCalculator &operator=(const BondCalculator &v);
  ~BondCalculator();
  double interestRate();

private:
  std::string m_institution;
  double m_principal;
  double m_coupon;
  int m_numPeriods;
};

#endif /* defined(__FinancialSamples__BondCalculator__) */