#include "day05.hpp"

using namespace std;

unordered_map<int, unordered_set<int>> getRules(const vector<string>& rules) {
    unordered_map<int, unordered_set<int>> precedence_map;
    for (const string& rule : rules) {
        int x, y;
        char delim;
        stringstream ss(rule);
        ss >> x >> delim >> y;
        precedence_map[x].insert(y);
    }
    return precedence_map;
}

bool isValidUpdate(const vector<int>& update, const unordered_map<int, unordered_set<int>>& precedence_map) {
    unordered_map<int, int> position_map;
    for (size_t i = 0; i < update.size(); ++i) {
        position_map[update[i]] = i;
    }

    for (const auto& [x, y_set] : precedence_map) {
        if (position_map.find(x) != position_map.end()) {
            for (int y : y_set) {
                if (position_map.find(y) != position_map.end() &&
                    position_map[x] > position_map[y]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int getMiddle(const vector<int>& update) {
    return update[update.size() / 2];
}

vector<int> getUpdate(const string& line) {
    vector<int> result;
    stringstream ss(line);
    string page;
    while (getline(ss, page, ',')) {
        result.push_back(stoi(page));
    }
    return result;
}

int main() {
    string filename = "input05.txt";
    ifstream input_file(filename);
    assert(input_file);

    vector<string> rules;
    vector<vector<int>> updates;
    string line;
    bool reading_updates = false;

    while (getline(input_file, line)) {
        if (line.empty()) {
            reading_updates = true;
            continue;
        }

        if (reading_updates) {
            updates.push_back(getUpdate(line));
        } else {
            rules.push_back(line);
        }
    }

    input_file.close();

    unordered_map<int, unordered_set<int>> precedence_map = getRules(rules);

    int res = 0;

    for (const auto& update : updates) {
        if (isValidUpdate(update, precedence_map)) {
            res += getMiddle(update);
        }
    }

    cout << "res: " << res << endl;

    return 0;
}
