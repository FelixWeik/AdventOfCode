#include "day10.hpp"

using namespace std;

vector<pos_t> next_moves(top_map &map, pos_t cur_pos) {
    vector<pos_t> moves;
    for (direction dir : {Up, Down, Left, Right}) {
        if (check_move(cur_pos, dir, map)) {
            moves.push_back(move(cur_pos, dir));
        }
    }
    return moves;
}

int solve(top_map &map, pos_t cur_pos, int res) {
    int cur_top = map[cur_pos.first][cur_pos.second];
    if (cur_top == TARGET_HEIGHT) {
        return 1;
    }
    int count = 0;
    for (auto &new_pos : next_moves(map, cur_pos)) {
        count += solve(map, new_pos, 0);
    }
    return count;
}

bool check_move(pos_t cur_pos, direction dir, top_map &map) {
    pos_t new_pos = move(cur_pos, dir);
    return new_pos.first >= 0 && new_pos.first < map.size() && 
           new_pos.second >= 0 && new_pos.second < map[0].size() && 
           map[new_pos.first][new_pos.second] == map[cur_pos.first][cur_pos.second] + 1;
}

vector<pos_t> get_trailheads(top_map map) {
    vector<pos_t> res;
    if (map.empty()) return res;
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 0) {
                res.push_back(pos_t(i, j));
            }
        }
    }
    return res;
}

top_map parse_file(ifstream &input) {
    top_map map;
    string line;
    while (getline(input, line)) {
        vector<int> row;
        for (char c : line) {
            if (isdigit(c)) {
                row.push_back(c - '0');
            }
        }
        map.push_back(row);
    }
    return map;
}

int main() {
    ifstream input("input10.txt");
    assert(input);

    top_map map = parse_file(input);
    vector<pos_t> trailheads = get_trailheads(map);

    int total_score = 0;
    for (auto &trailhead : trailheads) {
        total_score += solve(map, trailhead, 0);
    }

    cout << "res: " << total_score << endl;
    return 0;
}
