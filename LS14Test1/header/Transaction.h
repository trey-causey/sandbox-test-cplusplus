//
// Created by TJC on 9/16/2020.
//
#include <string>
#ifndef LS14TEST1_TRANSACTION_H
#define LS14TEST1_TRANSACTION_H
class Transaction
{
private:
    int amount;
    std::string type;
public:
    Transaction(int amt, std::string kind);
    std::string Report();
};
#endif //LS14TEST1_TRANSACTION_H
