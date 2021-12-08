#pragma once
#include "Utils.h"

struct Day8 {
    struct SegmentData {
        SegmentData() {
            const size_t patterns_size = 10;
            const size_t outputs_size = 4;
            patterns.assign(patterns_size, "");
            outputs.assign(outputs_size, "");
        }

        size_t decode() const {
            map<size_t, set<char>> decode_map;
            vector<string> patterns_5, patterns_6;
            for (const auto& pattern : patterns) {
                if (pattern.length() == 2) {
                    for (const auto letter : pattern) {
                        decode_map[1].insert(letter);
                    }
                } else if (pattern.length() == 3) {
                    for (const auto letter : pattern) {
                        decode_map[7].insert(letter);
                    }
                }else if (pattern.length() == 4) {
                    for (const auto letter : pattern) {
                        decode_map[4].insert(letter);
                    }
                } else if (pattern.length() == 7) {
                    for (const auto letter : pattern) {
                        decode_map[8].insert(letter);
                    }
                } else if (pattern.length() == 5) {
                    patterns_5.push_back(pattern);
                } else {
                    patterns_6.push_back(pattern);
                }
            }

            for (const auto& pattern : patterns_5) {
                set<char> temp, res;
                for (const auto letter : pattern) {
                    temp.insert(letter);
                }
                res = temp;
                temp.insert(decode_map[1].begin(), decode_map[1].end());
                
                if (temp.size() == pattern.length()) {
                    decode_map[3] = res;
                } else {
                    size_t cur_temp_size = temp.size();
                    temp.insert(decode_map[4].begin(), decode_map[4].end());
                    if (temp.size() == cur_temp_size) {
                        decode_map[5] = res;
                    } else {
                        decode_map[2] = res;
                    }
                }
            }

            for (const auto& pattern : patterns_6) {
                set<char> temp, res;
                for (const auto letter : pattern) {
                    temp.insert(letter);
                }
                res = temp;
                temp.insert(decode_map[5].begin(), decode_map[5].end());
                if (temp.size() != pattern.length()) {
                    decode_map[0] = res;
                } else {
                    temp.insert(decode_map[1].begin(), decode_map[1].end());
                    if (temp.size() != pattern.length()) {
                        decode_map[6] = res;
                    } else {
                        decode_map[9] = res;
                    }
                }
            }

            vector<size_t> res;
            for (const auto output : outputs) {
                set<char> temp;
                for (const auto letter : output) {
                    temp.insert(letter);
                }
                for (const auto& decode : decode_map) {
                    if (decode.second == temp) {
                        res.push_back(decode.first);
                        break;
                    }
                }
            }

            return res[0] * 1000 + res[1] * 100 + res[2] * 10 + res[3];
        }

        vector<string> patterns;
        vector<string> outputs;
        
        friend istream& operator>> (istream& in, SegmentData& segment_data) {
            for (auto& pattern : segment_data.patterns) {
                in >> pattern;
            }
            char delimeter;
            in >> delimeter;
            for (auto& output : segment_data.outputs) {
                in >> output;
            }
            return in;
        }
    };

    vector<SegmentData> data = read_values<SegmentData>("data/day8.txt");

    size_t problem1() {
        size_t res = 0;
        for (const auto& segment_data : data) {
            for (const auto& output : segment_data.outputs) {
                if (output.length() == 2 || output.length() == 4 || output.length() == 3 || output.length() == 7) {
                    ++res;
                }
            }
        }
        return res;
    }

    size_t problem2() {
        size_t res = 0;
        for (const auto& segment_data : data) {
            size_t decode_res = segment_data.decode();
            res += decode_res;
            // cout << decode_res << endl;
        }
        return res;
    }
};