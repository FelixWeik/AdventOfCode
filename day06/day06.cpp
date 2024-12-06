#include "day06.hpp"

int main() {
    ifstream input_file("input06.txt");
    assert(input_file);

    vector<vector<char>> map;
    pair<int, int> cur_pos;
    set<pair<int, int>> vst_pos;

    string line;
    int i = 0;
    while (getline(input_file, line)) {
        vector<char> row;
        for (int j = 0; j < static_cast<int>(line.size()); ++j) {
            row.push_back(line[j]);
            if (line[j] == 'v' || line[j] == '<' || line[j] == '>' || line[j] == '^') {
                cur_pos = {i, j};
            }
        }
        map.push_back(row);
        i++;
    }

    vst_pos.insert(cur_pos);
    int res = 1;

    while (true) {
        pair<int, int> next_pos = complete_move(cur_pos, map);

        if (next_pos == cur_pos) {
            continue;
        }
        if (next_pos == pair(-1, -1)) {
            break;
        }

        if (vst_pos.insert(next_pos).second) {
            res++;
        }
        cur_pos = next_pos;
    }

    cout << "res: " << res << endl;

    return 0;
}
