#include "day08.hpp"

using namespace std;

void addAntinode(unordered_set<pair<int, int>, hash<pair<int, int>>>& antinodes, pair<int, int> pr1, pair<int, int> pr2, int N, int M) {
    int x1 = pr1.first, y1 = pr1.second;
    int x2 = pr2.first, y2 = pr2.second;
    int newx = x2 + (x2 - x1);
    int newy = y2 + (y2 - y1);
    if (newx >= 0 && newx < N && newy >= 0 && newy < M) {
        antinodes.insert({newx, newy});
    }
}

int main() {
    ifstream inputStream("input08.txt");
    assert(inputStream);

    vector<string> grid;
    string line;

    // Zeilen der Datei einlesen
    while (getline(inputStream, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }
    inputStream.close();

    int N = grid.size();
    int M = grid[0].size();

    unordered_map<char, vector<pair<int, int>>> nodes;

    // Sammeln der Positionen aller Antennen
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c = grid[i][j];
            if (c != '.') {
                nodes[c].push_back({i, j});
            }
        }
    }

    unordered_set<pair<int, int>, hash<pair<int, int>>> antinodes;

    for (auto& entry : nodes) {
        vector<pair<int, int>>& node_list = entry.second;
        int L = node_list.size();
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < i; ++j) {
                addAntinode(antinodes, node_list[i], node_list[j], N, M);
                addAntinode(antinodes, node_list[j], node_list[i], N, M);
            }
        }
    }

    cout << "res: " << antinodes.size() << endl;
    return 0;
}
