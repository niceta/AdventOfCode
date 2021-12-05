#pragma once
#include "Utils.h"

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

    size_t problem1() {
        for (const auto& vent : vents) {
            auto x_min_max = minmax(vent.x1, vent.x2);
            auto y_min_max = minmax(vent.y1, vent.y2);
            if (vent.x1 == vent.x2) {
                for (size_t y = y_min_max.first; y <= y_min_max.second; ++y) {
                    ++field[y][vent.x1];
                }
            } else if (vent.y1 == vent.y2) {
                for (size_t x = x_min_max.first; x <= x_min_max.second; ++x) {
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

    size_t problem2() {
        for (const auto& vent : vents) {
            auto x_min_max = minmax(vent.x1, vent.x2);
            auto y_min_max = minmax(vent.y1, vent.y2);
            if (vent.x1 == vent.x2) {
                for (size_t y = y_min_max.first; y <= y_min_max.second; ++y) {
                    ++field[y][vent.x1];
                }
            } else if (vent.y1 == vent.y2) {
                for (size_t x = x_min_max.first; x <= x_min_max.second; ++x) {
                    ++field[vent.y1][x];
                }
            } else {
                size_t x = vent.x1;
                size_t y = vent.y1;
                do {
                    ++field[y][x];
                    vent.x2 > vent.x1 ? ++x : --x;
                    vent.y2 > vent.y1 ? ++y : --y;
                } while (x != vent.x2 && y != vent.y2);
                ++field[vent.y2][vent.x2];
            }
        }
        return check_field(field);
    }
};
