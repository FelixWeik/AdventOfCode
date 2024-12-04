#include "day03.hpp"

using namespace std;

int main() {
    ifstream inputStream("input03.txt");
    assert(inputStream);

    string input((istreambuf_iterator<char>(inputStream)), istreambuf_iterator<char>());

    regex pattern(R"(mul\((\d+),(\d+)\))");

    sregex_iterator begin(input.begin(), input.end(), pattern);
    sregex_iterator end;
    
    int res = 0;

    for (auto it = begin; it != end; ++it) {
        int x = stoi((*it)[1]);
        int y = stoi((*it)[2]);
        int product = x * y;
        res += product;
    }

    cout << "Total Sum: " << res << endl;
    
    return 0;
}
