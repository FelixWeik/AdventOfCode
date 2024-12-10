#ifndef DAY10_HPP
#define DAY10_HPP

#include <vector>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <utility> 
#include <string>

using namespace std;

using pos_t = std::pair<int, int>;
using top_map = std::vector<std::vector<int>>;

enum direction { Up, Down, Left, Right, STOP };

const int TARGET_HEIGHT = 9;

pos_t move(pos_t &cur_pos, direction dir) {
    int first = cur_pos.first;
    int second = cur_pos.second;
    switch(dir) {
        case Up:
            return std::make_pair(first - 1, second);
        case Down:
            return std::make_pair(first + 1, second);
        case Left:
            return std::make_pair(first, second - 1);
        case Right:
            return std::make_pair(first, second + 1);
        default:
            return cur_pos;
    }
}

std::vector<pos_t> next_moves(top_map &map, pos_t cur_pos);
int solve(top_map &map, pos_t cur_pos, int res);
bool check_move(pos_t cur_pos, direction dir, top_map &map);
std::vector<pos_t> get_trailheads(top_map map);
top_map parse_file(std::ifstream &input);


#endif 
