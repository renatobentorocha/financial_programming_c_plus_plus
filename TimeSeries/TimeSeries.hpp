#ifndef __FinancialSamples__TimeSeries__
#define __FinancialSamples__TimeSeries__

#include <vector>

class TimeSeries
{
public:
  TimeSeries();
  TimeSeries(const TimeSeries &);
  TimeSeries &operator=(const TimeSeries &);
  ~TimeSeries();
  void addValue(double val);
  double stdDev();
  double mean();
  size_t size();
  double elem(int i);

private:
  std::vector<double> m_values;
};

#endif /* defined(__FinancialSamples__TimeSeries__) */