#ifndef __FinancialSamples__CorrelationCalculator__
#define __FinancialSamples__CorrelationCalculator__

class TimeSeries;

class CorrelationCalculator
{
public:
  CorrelationCalculator(TimeSeries &a, TimeSeries &b);
  ~CorrelationCalculator();
  CorrelationCalculator(const CorrelationCalculator &);
  CorrelationCalculator &operator=(const CorrelationCalculator &);
  double correlation();

private:
  TimeSeries &m_tsA;
  TimeSeries &m_tsB;
};

#endif /* defined(__FinancialSamples__CorrelationCalculator__) */