#include <list>
#include <iostream>

using namespace std;

// Function to print the spreadsheet (list of lists)
void printSpreadsheet(const list<list<int>>& spreadsheet) {
    for (const auto& row : spreadsheet) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// Function to add a new row to the spreadsheet
void addRow(list<list<int>>& spreadsheet, const list<int>& newRow) {
    spreadsheet.push_back(newRow);
}

// Function to delete a row from the spreadsheet
void deleteRow(list<list<int>>& spreadsheet, int rowIndex) {
    auto it = spreadsheet.begin();
    advance(it, rowIndex);
    spreadsheet.erase(it);
}

int main() {
    list<list<int>> spreadsheet = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Initial spreadsheet:" << endl;
    printSpreadsheet(spreadsheet);

    // Add a new row to the spreadsheet
    list<int> newRow1 = {10, 11, 12};
    addRow(spreadsheet, newRow1);

    cout << "\nSpreadsheet after adding a new row:" << endl;
    printSpreadsheet(spreadsheet);

    // Delete a row from the spreadsheet
    int rowIndexToDelete = 0;
    deleteRow(spreadsheet, rowIndexToDelete);

    cout << "\nSpreadsheet after deleting row " << rowIndexToDelete << ":" << endl;
    printSpreadsheet(spreadsheet);

    return 0;
}
