#include "day09.hpp"

int main() {
    FILE* f = fopen("input09.txt", "r");

    char str[30000];
    std::string line;
    
    fscanf(f, "%s ", &str);

    int mem[200000];
    int memSize = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            int run = str[i] - '0';
            for (int j = 0; j < run; j++) {
                mem[memSize] = i/2;
                memSize ++;
            }
        }
        else {
            int run = str[i] - '0';
            for (int j = 0; j < run; j++) {
                mem[memSize] = -1;
                memSize ++;
            }
        }
    }
    
    for (int i = 0; i < memSize; i++) {
        if (mem[i] == -1) {
            mem[i] = mem[memSize-1];
            memSize --;
            while (mem[memSize-1] == -1) {
                memSize --;
            }
        }
    }

    long res = 0;
    for (int i = 0; i < memSize; i++) {
        res += mem[i] * i;
    }


    std::cout << "res" << res << std::endl;
}