#ifndef __DAY07HPP__
#define __DAY07HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <assert.h>

bool canEvaluateToTarget(const vector<long long>& numbers, int index, long long currentResult, long long target);
bool processLine(const string& line, long long& target);

#endif