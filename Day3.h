#pragma once
#include "Utils.h"

struct Day3 {
    vector<string> numbers = read_values<string>("data/binary_numbers.txt");

    int problem1() {
        unsigned size = numbers[0].length();
        vector<unsigned> digit_sums(size, 0);
        for (const auto& number : numbers) {
            for (size_t i = 0; i < number.length(); ++i) {
                int val = number[i] - '0';
                digit_sums[i] += val;
            }
        }

        vector<int> gamma, epsilon;
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

    char get_the_most_common_bit(const vector<string>& nums, int bit) {
        unsigned sum = 0;
        for (const auto& num : nums) {
            sum += num[bit] - '0';
        }

        if (sum > nums.size() - sum) {
            return '1';
        } else if (sum < nums.size() - sum) {
            return '0';
        }
        return '\0';
    }

    char get_the_least_common_bit(const vector<string>& nums, int bit) {
        char the_most_common = get_the_most_common_bit(nums, bit);
        if (the_most_common == '1') {
            return '0';
        } else if (the_most_common == '0') {
            return '1';
        } 
        return '\0';
    }

    typedef char(Day3::*most_least_func_type)(const vector<string>&, int);

    vector<int> get_rate(vector<string> data, most_least_func_type most_least_func, char if_equal_bit) {
        int bit = 0;
        while (data.size() > 1) {
            char common_bit = (this->*most_least_func)(data, bit);
            vector<string> temp;
            if (common_bit == '\0') {
                for (const auto& number : data) {
                    if (number[bit] == if_equal_bit) {
                        temp.push_back(number);
                    }
                }
            } else {
                for (const auto& number : data) {
                    if (number[bit] == common_bit) {
                        temp.push_back(number);
                    }
                }
            }
            data = temp;
            ++bit;
        }
        vector<int> res;
        for (const char ch : data[0]) {
            res.push_back(ch - '0');
        }
        return res;
    }

    int problem2() {
        vector<int> oxygen_rate = get_rate(numbers, &Day3::get_the_most_common_bit, '1');
        vector<int> co2_rate = get_rate(numbers, &Day3::get_the_least_common_bit, '0');

        return get_decimal(oxygen_rate) * get_decimal(co2_rate);
    }
};