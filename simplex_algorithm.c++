#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to print the simplex table
void printTable(const vector<vector<double>>& table) {
    cout << fixed << setprecision(2);
    for (const auto& row : table) {
        for (double value : row) {
            cout << setw(10) << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to find the pivot column (most negative in last row)
int findPivotColumn(const vector<vector<double>>& table) {
    int pivotColumn = -1;
    double minValue = 0;
    for (int j = 1; j < table[0].size(); j++) {
        if (table.back()[j] < minValue) {
            minValue = table.back()[j];
            pivotColumn = j;
        }
    }
    return pivotColumn;
}

// Function to find the pivot row (minimum ratio test)
int findPivotRow(const vector<vector<double>>& table, int pivotColumn) {
    int pivotRow = -1;
    double minRatio = 1e9; // Large value for comparison
    for (int i = 0; i < table.size() - 1; i++) {
        if (table[i][pivotColumn] > 0) {
            double ratio = table[i][0] / table[i][pivotColumn];
            if (ratio < minRatio) {
                minRatio = ratio;
                pivotRow = i;
            }
        }
    }
    return pivotRow;
}


// Function to perform pivoting
void performPivoting(vector<vector<double>>& table, int pivotRow, int pivotColumn) {
    double pivotValue = table[pivotRow][pivotColumn];
    for (double& value : table[pivotRow]) {
        value /= pivotValue;
    }

    for (int i = 0; i < table.size(); i++) {
        if (i != pivotRow) {
            double factor = table[i][pivotColumn];
            for (int j = 0; j < table[i].size(); j++) {
                table[i][j] -= factor * table[pivotRow][j];
            }
        }
    }
}

// Function to run the Simplex Algorithm
void simplex(vector<vector<double>>& table) {
    while (true) {
        int pivotColumn = findPivotColumn(table);
        if (pivotColumn == -1) {
            break; // Optimal solution found
        }

        int pivotRow = findPivotRow(table, pivotColumn);
        if (pivotRow == -1) {
            cout << "Unbounded solution." << endl;
            return;
        }

        performPivoting(table, pivotRow, pivotColumn);

        cout << "Table after pivoting (Row: " << pivotRow << ", Column: " << pivotColumn << "):\n";
        printTable(table);
    }

    cout << "Optimal solution found:\n";
    for (int i = 1; i < table[0].size(); i++) {
        cout << "x" << i << " = ";
        bool found = false;
        for (int j = 0; j < table.size() - 1; j++) {
            if (table[j][i] == 1) {
                cout << table[j][0] << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "0 ";
        }
    }
    cout << endl;
    cout << "Maximum value: " << table.back()[0] << endl;
}

// Main function
int main() {
    int numVariables, numConstraints;
    cout << "Enter the number of variables: ";
    cin >> numVariables;
    cout << "Enter the number of constraints: ";
    cin >> numConstraints;

    vector<vector<double>> table(numConstraints + 1, vector<double>(numVariables + numConstraints + 1, 0));

    cout << "Enter the coefficients of the constraints (including RHS):\n";
    for (int i = 0; i < numConstraints; i++) {
        for (int j = 0; j <= numVariables; j++) {
            cin >> table[i][j];
        }
        table[i][numVariables + i + 1] = 1; // Slack variable
    }

    cout << "Enter the coefficients of the objective function (maximize):\n";
    for (int j = 1; j <= numVariables; j++) {
        cin >> table.back()[j];
        table.back()[j] *= -1; // Convert to standard form (maximize)
    }

    cout << "Initial simplex table:\n";
    printTable(table);

    simplex(table);

    return 0;
}
