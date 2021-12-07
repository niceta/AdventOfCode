#pragma once
#include "Utils.h"

struct Day7 {
    vector<size_t> positions = read_values<size_t>("data/day7.txt");
    size_t min = numeric_limits<size_t>::max();

    size_t get_cost(size_t val, const vector<size_t>& positions, size_t cur_cost) {
        size_t cost = 0;
        for (auto pos : positions) {
            val > pos ? cost += val - pos : cost += pos - val;
            if (cost > cur_cost) {
                break;
            }
        }
        return cost;
    }

    size_t get_cost_2(size_t val, const vector<size_t>& positions, size_t cur_cost) {
        size_t cost = 0;
        for (auto pos : positions) {
            size_t n;
            val > pos ? n = val - pos : n = pos - val;
            cost += n * (n + 1) / 2;
            if (cost > cur_cost) {
                break;
            }
        }
        return cost;
    }
    
    size_t problem1() {
        auto minmax = minmax_element(positions.begin(), positions.end());
        for (auto pos = *minmax.first; pos <= *minmax.second; ++pos) {
            auto cost = get_cost(pos, positions, min);
            if (cost < min) {
                min = cost;
            }
        }
        return min;
    }

    size_t problem2() {
        auto minmax = minmax_element(positions.begin(), positions.end());
        for (auto pos = *minmax.first; pos <= *minmax.second; ++pos) {
            auto cost = get_cost_2(pos, positions, min);
            if (cost < min) {
                min = cost;
            }
        }
        return min;
    }
};