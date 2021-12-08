#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <chrono>
#include <limits> 

using namespace std;

template<typename T>
vector<T> read_values(const string& path) {
    ifstream input(path);
    vector<T> res;
    if (input.is_open()) {
        T val;
        while (input >> val) {
            res.push_back(val);
        }
    }
    return res;
}

template<typename T, typename S>
vector<pair<T, S>> read_paires(const string& path) {
    ifstream input(path);
    vector<pair<T, S>> res;
    if (input.is_open()) {
        T first;
        S second;

        while (input >> first >> second) {
            res.push_back( {first, second} );
        }
    }
    return res;
}

int fast_pow(int val, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp % 2 == 0) {
        return fast_pow(val * val, exp / 2);
    } else {
        return val * fast_pow(val, exp - 1);
    }
}

int get_decimal(const vector<int>& binary) {
    int res = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        res += binary[i] * fast_pow(2, binary.size() - 1 - i);
    }
    return res;
}
