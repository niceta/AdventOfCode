#include <iostream>
#include "Utils.h"
using namespace std;

vector<int> measurement = read_from_file("measurements.txt");

int problem1() {
    int res = 0;
    for (size_t i = 1; i < measurement.size(); ++i) {
        if (measurement[i] > measurement[i - 1]) {
            ++res;
        }
    }
    return res;
}

int problem2() {
    int res = 0;
    int first = measurement[0] + measurement[1] + measurement[2];
    int second = measurement[1] + measurement[2] + measurement[3];
    int counter = 0;
    for (size_t i = 1; i < measurement.size() - 1; ++i) {
        if (second > first) {
            ++res;
        }
        first = second;
        second = measurement[i - 1] + measurement[i] + measurement[i + 1];
    }
    return res;
}

int main() {
    cout << problem2();
    return 0;
}