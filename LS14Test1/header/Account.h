//
// Created by TJC on 9/16/2020.
//
#include <vector>
#include <string>
#include "Transaction.h"

#ifndef LS14TEST1_ACCOUNT_H
#define LS14TEST1_ACCOUNT_H
class Account
{
private:
    int balance;
    std::vector<Transaction> log;
public:
    Account();
    std::vector<std::string> Report();
    bool Deposit(int amount);
    bool Withdraw(int amount);
    bool GetBalance() {return balance;}
};
#endif //LS14TEST1_ACCOUNT_H
