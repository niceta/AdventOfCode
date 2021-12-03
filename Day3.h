#pragma once
#include "Utils.h"

struct Day3 {
    std::vector<std::string> numbers = read_binary_from_file("data/binary_numbers.txt");

    int problem1() {
        int size = numbers[0].length();
        std::vector<int> digit_sums(size, 0);
        for (const auto& number : numbers) {
            for (int i = 0; i < number.length(); ++i) {
                int val = number[i] - '0';
                digit_sums[i] += val;
            }
        }

        std::vector<int> gamma, epsilon;
        for (const auto sum : digit_sums) {
            if (sum > numbers.size() / 2) {
                gamma.push_back(1);
                epsilon.push_back(0);
            } else {
                gamma.push_back(0);
                epsilon.push_back(1);
            }
        }

        return get_decimal(gamma) * get_decimal(epsilon);
    }

    int problem2() {

    }
};