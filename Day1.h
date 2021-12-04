#pragma once
#include "Utils.h"

struct Day1 {
    vector<int> measurement = read_values<int>("data/measurements.txt");

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
        for (size_t i = 1; i < measurement.size() - 1; ++i) {
            if (second > first) {
                ++res;
            }
            first = second;
            second = measurement[i - 1] + measurement[i] + measurement[i + 1];
        }
        return res;
    }
};