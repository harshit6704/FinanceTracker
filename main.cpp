#include "FinanceTracker.h"
void displayMenu() {
    cout << "Personal Finance Tracker\n";
    cout << "1. Add Transaction\n";
    cout << "2. Delete Transaction\n";
    cout << "3. View Transactions\n";
    cout << "4. Generate Report\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
int main() {
    vector<Transaction> transactions;
    const string filename = "transactions.txt";
    loadFromFile(transactions, filename);
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTransaction(transactions);
                break;
            case 2:
                deleteTransaction(transactions);
                break;
            case 3:
                viewTransactions(transactions);
                break;
            case 4:
                generateReport(transactions);
                break;
            case 5:
                cout << "Exiting...\n";
                saveToFile(transactions, filename);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}