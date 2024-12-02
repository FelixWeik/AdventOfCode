#include "day02.hpp"

using namespace std;

// Function to check if a report is safe
int main() {
    ifstream inputStream("input02.txt");
    assert(inputStream);

    vector<vector<int>> rawInput;
    string line;
    while (getline(inputStream, line)) {
        istringstream lineStream(line);
        vector<int> row;
        int number;

        while (lineStream >> number) {
            row.push_back(number);
        }

        rawInput.push_back(row);
    }

    int safeCount = 0;
    for (const auto& report : rawInput) {
        if (isSafeReport(report)) {
            ++safeCount;
        }
    }
    cout << safeCount << endl;

    return 0;
}
