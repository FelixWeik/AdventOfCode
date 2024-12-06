#ifndef __DAY05HPP__
#define __DAY05HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

unordered_map<int, unordered_set<int>> getRules(const vector<string>& rules);
bool isValidUpdate(const vector<int>& update, const unordered_map<int, unordered_set<int>>& precedence_map);
int getMiddle(const vector<int>& update);
vector<int> getUpdate(const string& line);
int main();

#endif