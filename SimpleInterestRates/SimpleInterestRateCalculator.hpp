#ifndef __FinancialSamples__SimpleInterestRateCalculator__
#define __FinancialSamples__SimpleInterestRateCalculator__

class SimpleInterestRateCalculator
{
public:
  SimpleInterestRateCalculator(double rate);
  SimpleInterestRateCalculator(const SimpleInterestRateCalculator &v);
  SimpleInterestRateCalculator &operator=(const SimpleInterestRateCalculator &v);
  ~SimpleInterestRateCalculator();
  double singlePeriod(double value);

private:
  double m_rate;
};

inline double SimpleInterestRateCalculator::singlePeriod(double value)
{
  double f = value * (1 + this->m_rate);
  return f;
}

#endif /* defined(__FinancialSamples__SimpleInterestRateCalculator__) */