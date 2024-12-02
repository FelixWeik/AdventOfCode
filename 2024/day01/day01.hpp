#ifndef __DAY01HPP__
#define __DAY01HPP__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <assert.h>
#include <bits/stdc++.h>

int main(int argc, char* argv[]);

bool comp(int a, int b) {
    return a <= b;
}

int dist(int a, int b) {
    return std::abs(a-b);
}

#endif