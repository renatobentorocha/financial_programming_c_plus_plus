#include "CreditRisk.hpp"

CreditRisk::CreditRisk() {}

CreditRisk::~CreditRisk() {}

CreditRisk::CreditRisk(const CreditRisk &v) : _risk(v._risk) {}

CreditRisk &CreditRisk::operator=(const CreditRisk &v)
{
  if (this != &v)
  {
    _risk = v._risk;
  }

  return *this;
}

CreditRisk::RiskType CreditRisk::getRating()
{
  return _risk;
}