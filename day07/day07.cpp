#include "day07.hpp"

using namespace std;

bool processLine(const string& line, long long& target) {
    stringstream ss(line);
    string token;

    getline(ss, token, ':');
    target = stoll(token);

    vector<long long> numbers;
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            numbers.push_back(stoll(token));
        }
    }
    return canEvaluateToTarget(numbers, 1, numbers[0], target);
}

bool canEvaluateToTarget(const vector<long long>& numbers, int index, long long currentResult, long long target) {
    if (index == numbers.size()) {
        return currentResult == target;
    }

    return canEvaluateToTarget(numbers, index + 1, currentResult + numbers[index], target) ||
           canEvaluateToTarget(numbers, index + 1, currentResult * numbers[index], target);
}

int main() {
    ifstream inputFile("input07.txt");
    assert(inputFile);
    if (!inputFile) {
        cerr << "Fehler beim Öffnen der Datei input07.txt" << endl;
        return 1;
    }

    string line;
    long long res = 0;

    while (getline(inputFile, line)) {
        long long target;
        if (processLine(line, target)) {
            res += target;
        }
    }

    inputFile.close();

    cout << "res: " << res << endl;

    return 0;
}
