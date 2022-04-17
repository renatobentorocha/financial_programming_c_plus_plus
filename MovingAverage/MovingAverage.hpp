#ifndef __FinancialSamples__MovingAverageCalculator__
#define __FinancialSamples__MovingAverageCalculator__

#include <vector>

class MovingAverageCalculator
{
public:
  MovingAverageCalculator(int period);
  MovingAverageCalculator(const MovingAverageCalculator &);
  MovingAverageCalculator &operator=(const MovingAverageCalculator &);
  ~MovingAverageCalculator();
  void addPriceQuote(double close);
  std::vector<double> calculateMovingAverage();
  std::vector<double> calculateEMovingAverage();

private:
  // number of periods used in the calculation
  int m_numPeriods;
  std::vector<double> m_prices;
};

#endif /* defined(__FinancialSamples__MovingAverageCalculator__) */
