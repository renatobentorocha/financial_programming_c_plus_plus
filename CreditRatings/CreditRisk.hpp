#ifndef __FinancialSamples__CreditRisk__
#define __FinancialSamples__CreditRisk__
// A simple class representing a credit risk assessment
class CreditRisk
{
public:
  // these are risk grades, as determined by rating agencies
  enum RiskType
  {
    AAA,
    AAPlus,
    AA,
    APlus,
    A,
    BPlus,
    B,
    CPlus,
    C
  };

  CreditRisk();
  ~CreditRisk();
  CreditRisk(const CreditRisk &);
  CreditRisk &operator=(const CreditRisk &);
  RiskType getRating();

private:
  RiskType _risk;
};

#endif /* defined(__FinancialSamples__CreditRisk__) */