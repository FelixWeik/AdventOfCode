#include "day04.hpp"

using namespace std;

int main() {
    ifstream file("input04.txt");
    assert(file);

    vector<string> rows;
    string line;

    while (getline(file, line)) {
        rows.push_back(line);
    }
    file.close();

    size_t numRows = rows.size();
    size_t numCols = rows[0].size();

    vector<string> column_lists(numCols, "");
    for (size_t col = 0; col < numCols; ++col) {
        for (size_t row = 0; row < numRows; ++row) {
            column_lists[col] += rows[row][col];
        }
    }

    vector<string> padded_grid1(numRows);
    vector<string> padded_grid2(numRows);

    for (size_t i = 0; i < numRows; ++i) {
        padded_grid1[i] = string(i, ' ') + rows[i] + string(numRows - i - 1, ' ');
        padded_grid2[i] = string(i, ' ') + rows[numRows - i - 1] + string(numRows - i - 1, ' ');
    }

    // Diagonalen extrahieren
    vector<string> diagonals1(numRows + numCols - 1, "");
    vector<string> diagonals2(numRows + numCols - 1, "");

    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < padded_grid1[i].size(); ++j) {
            if (j < diagonals1.size() && padded_grid1[i][j] != ' ') {
                diagonals1[j] += padded_grid1[i][j];
            }
            if (j < diagonals2.size() && padded_grid2[i][j] != ' ') {
                diagonals2[j] += padded_grid2[i][j];
            }
        }
    }

    vector<string> all_strings = rows;
    all_strings.insert(all_strings.end(), column_lists.begin(), column_lists.end());
    all_strings.insert(all_strings.end(), diagonals1.begin(), diagonals1.end());
    all_strings.insert(all_strings.end(), diagonals2.begin(), diagonals2.end());

    regex pattern("(?=(XMAS|SAMX))");
    int total = 0;

    for (const auto& str : all_strings) {
        auto words_begin = sregex_iterator(str.begin(), str.end(), pattern);
        auto words_end = sregex_iterator();
        total += distance(words_begin, words_end);
    }

    cout << total << endl;
    return 0;
}
