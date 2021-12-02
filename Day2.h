#pragma once
#include "Utils.h"

struct Day2 {
    std::vector<std::pair<std::string, int>> movements = read_movements_from_file("data/movements.txt");

    int problem1() {
        int horizontal_pos = 0;
        int depth = 0;
        for (const auto& move : movements) {
            if (move.first == "forward") {
                horizontal_pos += move.second;
            } else if (move.first == "down") {
                depth += move.second;
            } else {
                depth -= move.second;
            }
        }
        return horizontal_pos * depth;
    }

    int64_t problem2() {
        int64_t horizontal_pos = 0;
        int64_t depth = 0;
        int64_t aim = 0;
        for (const auto& move : movements) {
            if (move.first == "forward") {
                horizontal_pos += move.second;
                depth += aim * move.second;
            } else if (move.first == "down") {
                aim += move.second;
            } else {
                aim -= move.second;
            }
        }
        return horizontal_pos * depth;
    }
};