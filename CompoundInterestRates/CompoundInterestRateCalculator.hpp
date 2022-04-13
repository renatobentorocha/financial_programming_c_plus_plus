#ifndef __FinancialSamples__CompoundInterestRateCalculator__
#define __FinancialSamples__CompoundInterestRateCalculator__

class CompoundInterestRateCalculator
{
public:
  CompoundInterestRateCalculator(double rate);
  CompoundInterestRateCalculator(const CompoundInterestRateCalculator &v);
  CompoundInterestRateCalculator &operator=(const CompoundInterestRateCalculator &v);
  ~CompoundInterestRateCalculator();
  double multiplePeriod(double value, int numPeriods);
  double continuousCompounding(double value, int numPeriods);

private:
  double m_rate;
};

#endif /* defined(__FinancialSamples__CompoundInterestRateCalculator__) */