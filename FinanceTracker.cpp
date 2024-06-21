#include "FinanceTracker.h"

void loadFromFile(vector<Transaction>& transactions, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Transaction transaction;
        while (file >> transaction.id >> ws && getline(file, transaction.date, '|') && getline(file, transaction.category, '|') && file >> transaction.amount) {
            transactions.push_back(transaction);
        }
        file.close();
    }
}

void saveToFile(const vector<Transaction>& transactions, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& transaction : transactions) {
            file << transaction.id << '\n' << transaction.date << '|' << transaction.category << '|' << transaction.amount << '\n';
        }
        file.close();
    }
}

void addTransaction(vector<Transaction>& transactions) {
    Transaction transaction;
    cout << "Enter Transaction ID: ";
    cin >> transaction.id;
    cin.ignore();
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, transaction.date);
    cout << "Enter Category: ";
    getline(cin, transaction.category);
    cout << "Enter Amount: ";
    cin >> transaction.amount;
    transactions.push_back(transaction);
    cout << "Transaction added successfully.\n";
}

void deleteTransaction(vector<Transaction>& transactions) {
    int id;
    cout << "Enter Transaction ID to Delete: ";
    cin >> id;

    auto it = remove_if(transactions.begin(), transactions.end(), [&](const Transaction& transaction) {
        return transaction.id == id;
    });

    if (it != transactions.end()) {
        transactions.erase(it, transactions.end());
        cout << "Transaction deleted successfully.\n";
    } else {
        cout << "Transaction not found.\n";
    }
}

void viewTransactions(const vector<Transaction>& transactions) {
    if (transactions.empty()) {
        cout << "No transactions available.\n";
    } else {
        cout << left << setw(5) << "ID" << setw(12) << "Date" << setw(15) << "Category" << setw(10) << "Amount" << '\n';
        cout << "----------------------------------------------------\n";
        for (const auto& transaction : transactions) {
            cout << left << setw(5) << transaction.id << setw(12) << transaction.date << setw(15) << transaction.category << setw(10) << transaction.amount << '\n';
        }
    }
}

void generateReport(const vector<Transaction>& transactions) {
    double totalIncome = 0.0, totalExpense = 0.0;

    for (const auto& transaction : transactions) {
        if (transaction.amount > 0) {
            totalIncome += transaction.amount;
        } else {
            totalExpense += transaction.amount;
        }
    }

    cout << "Total Income: " << totalIncome << '\n';
    cout << "Total Expense: " << totalExpense << '\n';
    cout << "Net Balance: " << totalIncome + totalExpense << '\n';
}