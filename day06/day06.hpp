#ifndef __DAY06HPP__
#define __DAY06HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;

bool is_valid_pos(pair<int, int> pos, const vector<vector<char>> &map) {
    return pos.first >= 0 && pos.first < static_cast<int>(map.size()) &&
           pos.second >= 0 && pos.second < static_cast<int>(map[0].size());
}

pair<int, int> move(char direction, pair<int, int> cur_pos) {
    if (direction == 'v') return {cur_pos.first + 1, cur_pos.second};
    if (direction == '<') return {cur_pos.first, cur_pos.second - 1};
    if (direction == '>') return {cur_pos.first, cur_pos.second + 1};
    if (direction == '^') return {cur_pos.first - 1, cur_pos.second};
    return cur_pos; 
}

char rotate(char direction) {
    if (direction == 'v') return '<';
    if (direction == '<') return '^';
    if (direction == '>') return 'v';
    if (direction == '^') return '>';
    return direction;
}

pair<int, int> complete_move(pair<int, int> cur_pos, vector<vector<char>> &map) {
    char cur_dir = map[cur_pos.first][cur_pos.second];
    pair<int, int> nxt_pos = move(cur_dir, cur_pos);

    if (!is_valid_pos(nxt_pos, map)) return {-1, -1};

    if (map[nxt_pos.first][nxt_pos.second] == '#') {
        map[cur_pos.first][cur_pos.second] = rotate(cur_dir);
        return cur_pos;
    }

    map[cur_pos.first][cur_pos.second] = 'X';
    map[nxt_pos.first][nxt_pos.second] = cur_dir;
    return nxt_pos;
}

#endif
