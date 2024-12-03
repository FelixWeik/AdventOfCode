#include "day03.hpp"

using namespace std;

int main() {
    ifstream inputStream("input03.txt");
    assert(inputStream);

    std::string input((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());

    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::vector<std::pair<int, int>> results;

    std::sregex_iterator begin(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        int x = std::stoi((*it)[1]);
        int y = std::stoi((*it)[2]);
        results.emplace_back(x, y);
    }

    int res = 0;

    for (auto it = begin; it != end; ++it) {
        int x = std::stoi((*it)[1]);
        int y = std::stoi((*it)[2]);
        int product = x * y;
        res += product;
    }

    cout << "Total Sum: " << res << endl;
    
    return 0;
}