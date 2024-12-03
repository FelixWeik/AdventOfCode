#include "day01.hpp"

int main(int argc, char* argv[]) {
    assert(argc > 1);
    std::ifstream Input(argv[1]);
    assert(Input);

    std::vector<int> leftList;
    std::vector<int> rightlist;

    std::string line;
    while (std::getline(Input, line)) {
        std::istringstream lineStream(line);
        int left, right;
        lineStream >> left >> right;
        leftList.push_back(left);
        rightlist.push_back(right);
    }

    assert(leftList.size() == rightlist.size());
    std::vector<int> distances(leftList.size());

    sort(leftList.begin(), leftList.end(), comp);
    sort(rightlist.begin(), rightlist.end(), comp);

    std::transform(leftList.begin(), leftList.end(), rightlist.begin(), distances.begin(), dist);

    int res = std::accumulate(distances.begin(), distances.end(), 0);

    std::cout << res << std::endl;

    return 0;
}