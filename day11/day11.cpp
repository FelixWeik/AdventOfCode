#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <numeric>
#include <assert.h>

using namespace std;

const int SPLIT_FACTOR = 2024;

unordered_map<int, pair<int, int>> SPLITS;

unordered_map<int, int> blink(const unordered_map<int, int>& stones) {
    unordered_map<int, int> new_stones;

    if (stones.count(0)) {
        new_stones[1] += stones.at(0);
    }

    for (const auto& [stone, count] : stones) {
        if (SPLITS.count(stone)) {
            new_stones[SPLITS[stone].first] += count;
            new_stones[SPLITS[stone].second] += count;
        } else {
            int length = floor(log10(stone)) + 1;
            if (length % 2 == 0) {
                int left = stoi(to_string(stone).substr(0, length / 2));
                int right = stoi(to_string(stone).substr(length / 2));
                new_stones[left] += count;
                new_stones[right] += count;
                SPLITS[stone] = {left, right};
            } else {
                new_stones[stone * SPLIT_FACTOR] += count;
            }
        }
    }

    return new_stones;
}

int main() {
    unordered_map<int, int> stones;

    ifstream input("input11.txt");
    assert(input);

    for (int v; input >> v;) {
        stones[v]++;
    }

    int part1_count = 0;
    for (int i = 0; i < 75; ++i) {
        if (i == 25) {
            part1_count = accumulate(stones.begin(), stones.end(), 0,
                                      [](int sum, const auto& p) { return sum + p.second; });
        }
        stones = blink(stones);
    }

    cout << "Part 1: " << part1_count << endl;
    cout << "Part 2: " << accumulate(stones.begin(), stones.end(), 0,
                                      [](int sum, const auto& p) { return sum + p.second; })
         << endl;

    return 0;
}