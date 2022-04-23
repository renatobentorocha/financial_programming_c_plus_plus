cmake_minimum_required(VERSION 3.0.0)
project(FinancialProgramming VERSION 0.1.0)

# Use C++11
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(SimpleInterestRates)
add_subdirectory(CompoundInterestRates)
add_subdirectory(CashFlow)
add_subdirectory(ModelingBonds)
add_subdirectory(MovingAverage)
add_subdirectory(CalculatingVolatility)
add_subdirectory(InstrumentCorrelation)
add_subdirectory(TimeSeries)

include(CTest)
enable_testing()

add_executable(FinancialProgramming 
  main.cpp 
  SimpleInterestRates/SimpleInterestRates.cpp 
  SimpleInterestRates/SimpleInterestRateCalculator.cpp
  CompoundInterestRates/CompoundInterest.cpp
  CompoundInterestRates/CompoundInterestRateCalculator.cpp
  CashFlow/CashFlowCalculator.cpp
  ModelingBonds/BondCalculator.cpp
  MovingAverage/MovingAverage.cpp
  CalculatingVolatility/VolatilityCalculator.cpp
  InstrumentCorrelation/CorrelationCalculator.cpp
  TimeSeries/TimeSeries.cpp
  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
