#ifndef FINANCETRACKER_H
#define FINANCETRACKER_H
#include <bits/stdc++.h>
using namespace std;
struct Transaction {
    int id;
    string date;
    string category;
    double amount;
};
void loadFromFile(vector<Transaction>& transactions, const string& filename);
void saveToFile(const vector<Transaction>& transactions, const string& filename);
void addTransaction(vector<Transaction>& transactions);
void deleteTransaction(vector<Transaction>& transactions);
void viewTransactions(const vector<Transaction>& transactions);
void generateReport(const vector<Transaction>& transactions);

#endif // FINANCETRACKER_H