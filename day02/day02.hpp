#ifndef __DAY02HPP__
#define __DAY02HPP__

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <cmath>

int main();

bool isSafeReport(const std::vector<int>& report) {
    bool increasing = true, decreasing = true;

    for (size_t i = 0; i < report.size() - 1; ++i) {
        int diff = std::abs(report[i] - report[i + 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
        if (report[i] < report[i + 1]) {
            decreasing = false;
        } else if (report[i] > report[i + 1]) {
            increasing = false;
        }
    }
    return increasing || decreasing;
}

#endif