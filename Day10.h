#pragma once
#include "Utils.h"

struct Day10 {
    vector<string> bracers = read_values<string>("data/day10.txt");

    bool is_opened_brace(char brace) {
        if (brace == '(' || brace == '[' || brace == '{' || brace == '<') {
            return true;
        }
        return false;
    }

    bool is_paired_brace(char brace1, char brace2) {
        if ((brace1 == ')' && brace2 == '(')
            || (brace1 == ']' && brace2 == '[')
            || (brace1 == '}' && brace2 == '{')
            || (brace1 == '>' && brace2 == '<')) {
            return true;
        }
        return false;
    }

    size_t get_wrong_brace_score(const string& braces) {
        vector<char> stack;
        char wrong_brace = '?';
        for (auto brace : braces) {
            if (is_opened_brace(brace)) {
                stack.push_back(brace);
            } else {
                if (stack.empty()) {
                    wrong_brace = brace;
                    break;
                }
                char last_brace = stack[stack.size() - 1];
                if (is_paired_brace(brace, last_brace)) {
                    stack.pop_back();
                } else {
                    wrong_brace = brace;
                    break;
                }
            }
        }
        
        if (wrong_brace == '?') {
            return 0;
        } else if (wrong_brace == ')') {
            return 3;
        } else if (wrong_brace == ']') {
            return 57;
        } else if (wrong_brace == '}') {
            return 1197;
        } else {
            return 25137;
        }
    }

    uint64_t get_incomplete_score(const string& braces) {
        vector<char> stack;
        for (auto brace : braces) {
            if (is_opened_brace(brace)) {
                stack.push_back(brace);
            } else {
                if (stack.empty()) {
                    return 0;
                }
                char last_brace = stack[stack.size() - 1];
                if (is_paired_brace(brace, last_brace)) {
                    stack.pop_back();
                } else {
                    return 0;
                }
            }
        }
        if (stack.empty()) {
            return 0;
        }

        uint64_t res = 0;
        reverse(stack.begin(), stack.end());
        for (auto brace : stack) {
            res *= 5;
            if (brace == '(') {
                res += 1;
            } else if (brace == '[') {
                res += 2;
            } else if (brace == '{') {
                res += 3;
            } else {
                res += 4;
            }
        }
        return res;
    } 

    size_t problem1() {
        size_t res = 0;
        for (const auto& s : bracers) {
            res += get_wrong_brace_score(s);
        }
        return res;
    }

    uint64_t problem2() {
        vector<uint64_t> res;
        for (const auto& s : bracers) {
            uint64_t score = get_incomplete_score(s);
            if (score > 0) {
                res.push_back(score);
            }
        }
        sort(res.begin(), res.end());
        return res[res.size() / 2];
    }
};