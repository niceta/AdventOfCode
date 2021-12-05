#pragma once
#include "Utils.h"
#include <algorithm>

struct Day5 {
    Day5() {
        size_t max_x = 0;
        size_t max_y = 0;
        for (const auto& vent : vents) {
            max_x = max(max(max_x, vent.x1), max(max_x, vent.x2));
            max_y = max(max(max_y, vent.y1), max(max_y, vent.y2));
        }
        field.assign(max_x + 1, vector<size_t>(max_y + 1, 0));
    }

    struct Vent {
        size_t x1, y1, x2, y2;
        friend istream& operator>> (istream& in, Vent& vent) {
            in >> vent.x1 >> vent.y1 >> vent.x2 >> vent.y2;
            return in;
        }
    };

    vector<Vent> vents = read_values<Vent>("data/day5.txt");
    vector<vector<size_t>> field;


    size_t check_field(const vector<vector<size_t>>& field) {
        size_t res = 0;
        for (const auto& line : field) {
            for (auto elem : line) {
                if (elem > 1) {
                    ++res;
                }
            }
        }
        return res;
    }

    int problem1() {
        for (const auto& vent : vents) {
            if (vent.x1 == vent.x2) {
                for (size_t y = min(vent.y1, vent.y2); y <= max(vent.y1, vent.y2); ++y) {
                    ++field[y][vent.x1];
                }
            } else if (vent.y1 == vent.y2) {
                for (size_t x = min(vent.x1, vent.x2); x <= max(vent.x1, vent.x2); ++x) {
                    ++field[vent.y1][x];
                }
            }
        }

        /*for (const auto& line : field) {
            for (auto elem : line) {
                cout << elem << " ";
            }
            cout << endl;
        }*/
        return check_field(field);
    }

    int problem2() {
        return 0;
    }
};
