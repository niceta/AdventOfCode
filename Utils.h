#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

std::vector<int> read_measurements_from_file(const std::string& path) {
    std::ifstream input(path);
    std::vector<int> res;
    if (input.is_open()) {
        int val;
        while (input >> val) {
            res.push_back(val);
        }
    }
    return res;
}

std::vector<std::pair<std::string, int>> read_movements_from_file(const std::string& path) {
    std::ifstream input(path);
    std::vector<std::pair<std::string, int>> res;
    if (input.is_open()) {
        std::string direction;
        int val;

        while (input >> direction >> val) {
            res.push_back( {direction, val} );
        }
    }
    return res;
}