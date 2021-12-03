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

std::vector<std::string> read_binary_from_file(const std::string& path) {
    std::ifstream input(path);
    std::vector<std::string> res;
    if (input.is_open()) {
        std::string val;
        while (input >> val) {
            res.push_back(val);
        }
    }
    return res;
}

int pow(int val, int exp) {
    int res = 1;
    for (int i = 1; i <= exp; ++i) {
        res *= val;
    }
    return val;
}

int get_decimal(const std::vector<int>& binary) {
    int res = 0;
    for (int i = 0; i < binary.size(); ++i) {
        res += binary[i] * pow(2, binary.size() - 1 - i);
    }
    return res;
}