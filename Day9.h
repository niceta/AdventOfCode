#pragma once
#include "Utils.h"

struct Day9 {
    vector<string> input_data = read_values<string>("data/day9.txt");
    vector<vector<size_t>> table;
    size_t n, m;
    
    Day9() {
        m = input_data[0].length();
        n = input_data.size();
        fill_table();
    }
    
    void fill_table() {
        table.assign(n + 2, vector<size_t>(m + 2, 9));
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                table[i][j] = input_data[i - 1][j - 1] - '0';
            }
        }
    }

    bool check_min(size_t i, size_t j) {
        size_t cur_elem = table[i][j];
        if (cur_elem < table[i][j - 1] && cur_elem < table[i][j + 1]
            && cur_elem < table[i - 1][j] && cur_elem < table[i + 1][j]) {
            return true;
        }
        return false;
    }

    size_t problem1() {
        size_t res = 0;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (check_min(i, j)) {
                    res += table[i][j] + 1;
                }
            }
        }
        return res;
    }

    void calc_basin_size(size_t i, size_t j, size_t& size) {
        if (table[i][j] == 10) {
            return;
        }
        table[i][j] = 10;
        auto left = [&](vector<vector<size_t>> table, size_t i, size_t j) { 
            return table[i][j - 1];
        };
        auto right = [&](vector<vector<size_t>> table, size_t i, size_t j) { 
            return table[i][j + 1];
        };
        auto up = [&](vector<vector<size_t>> table, size_t i, size_t j) { 
            return table[i - 1][j];
        };
        auto down = [&](vector<vector<size_t>> table, size_t i, size_t j) { 
            return table[i + 1][j];
        };
        
        if (left(table, i, j) < 9) {
            calc_basin_size(i, j - 1, ++size);
        }
        if (right(table, i, j) < 9) {
            calc_basin_size(i, j + 1, ++size);
        }
        if (up(table, i, j) < 9) {
            calc_basin_size(i - 1, j, ++size);
        }
        if (down(table, i, j) < 9) {
            calc_basin_size(i + 1, j, ++size);
        }
    }

    size_t problem2() {
        vector<size_t> sizes;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (check_min(i, j)) {
                    size_t size = 1;
                    calc_basin_size(i, j, size);
                    sizes.push_back(size);
                }
            }
        }
        sort(sizes.begin(), sizes.end(), [](size_t x, size_t y) { return x > y; });
        return sizes[0] * sizes[1] * sizes[2];
    }
};