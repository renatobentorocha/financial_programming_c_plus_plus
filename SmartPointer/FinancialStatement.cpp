#include "FinancialStatement.hpp"

FinancialStatement::FinancialStatement()
    : m_return(0)
{
}

FinancialStatement::~FinancialStatement()
{
}

FinancialStatement::FinancialStatement(const FinancialStatement &v)
    : m_return(v.m_return),
      m_transactions(v.m_transactions)
{
}

FinancialStatement &FinancialStatement::operator=(FinancialStatement &v)
{
  if (this != &v)
  {
    m_return = v.m_return;
    m_transactions = v.m_transactions;
  }
  return *this;
}

double FinancialStatement::getReturn()
{
  return m_return + 10;
}

void FinancialStatement::addTransaction(const std::string &security, double val)
{
  m_transactions.push_back(std::make_pair(security, val));
}

// returns a sample statement that includes a few common stocks
std::unique_ptr<FinancialStatement> getSampleStatement()
{
  std::unique_ptr<FinancialStatement> fs(new FinancialStatement);
  fs->addTransaction("IBM", 102.2);
  fs->addTransaction("AAPL", 523.0);
  return fs;
}

void transferFinancialStatement(std::unique_ptr<FinancialStatement> &statement)
{
  // perform transfer here
  // ...
  std::unique_ptr<FinancialStatement> _statement;
  _statement = std::move(statement);

  // statement is still valid
  std::cout << "Financial Statement return: " << _statement->getReturn() << std::endl;
}