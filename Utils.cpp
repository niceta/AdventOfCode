#include "Utils.h"

std::vector<int> read_from_file(const std::string& path) {
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