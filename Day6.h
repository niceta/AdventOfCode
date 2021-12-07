#pragma once
#include "Utils.h"

struct Day6 {
    vector<size_t> lanternfishes = read_values<size_t>("data/day6.txt");

    size_t problem1() {
        size_t max_days = 35;
        for (size_t day = 1; day <= max_days; ++day) {
            vector<size_t> new_lanternfishes(lanternfishes.size());
            cout << day << " day fishes count: " << lanternfishes.size() << ". Fishes: ";
            for (auto fish : lanternfishes) {
                cout << fish << " ";
            }
            cout << endl;
            for (size_t i = 0; i < lanternfishes.size(); ++i) {
                if (lanternfishes[i] == 0) {
                    new_lanternfishes[i] = 6;
                    new_lanternfishes.push_back(8);
                } else {
                    new_lanternfishes[i] = lanternfishes[i] - 1;
                }
            }
            lanternfishes = new_lanternfishes;
        }
        return lanternfishes.size();
    }

    uint64_t problem2() {
        auto start_time = std::chrono::high_resolution_clock::now();
        size_t max_days = 463;
        map<size_t, uint64_t> fishes;
        for (size_t i = 0; i <= 8; ++i) {
            fishes[i] = 0;
        }

        for (auto fish : lanternfishes) {
            ++fishes[fish];
        }

        for (size_t day = 1; day <= max_days; ++day) {
            uint64_t new_borns = fishes[0];
            for (size_t fish = 1; fish <= 8; ++fish) {
                fishes[fish - 1] = fishes[fish];
            }
            fishes[6] += new_borns;
            fishes[8] = new_borns;
        }
        uint64_t res = 0;
        for (auto elem : fishes) {
            res += elem.second;
        }
        auto current_time = std::chrono::high_resolution_clock::now();
        std::cout << "Program has been running for " << std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time).count() << endl;
        return res;
    }
};
