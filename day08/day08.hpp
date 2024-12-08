#ifndef __DAY08HPP__
#define __DAY08HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <assert.h>

using namespace std;

void addAntinode(unordered_set<pair<int, int>, hash<pair<int, int>>>& antinodes, pair<int, int> pr1, pair<int, int> pr2, int N, int M);

#endif 