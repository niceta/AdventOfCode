#pragma once
#include "Utils.h"

struct Day4 {
    struct Cell {
        size_t val;
        bool isChecked;
        friend istream& operator>> (std::istream& in, Cell& cell) {
            in >> cell.val;
            cell.isChecked = false;
            return in;
        }
    };
    
    struct Table {
        Table() {
            data.assign(size, vector<Cell>(size));
        }

        bool win_check() {
            for (size_t i = 0; i < size; ++i) {
                size_t res_row = 0;
                for (size_t j = 0; j < size; ++j) {
                    if (data[i][j].isChecked) {
                        ++res_row;
                    } else {
                        break;
                    }
                }
                if (res_row == size) {
                    return true;
                }
            }
            for (size_t j = 0; j < size; ++j) {
                size_t res_col = 0;
                for (size_t i = 0; i < size; ++i) {
                    if (data[i][j].isChecked) {
                        ++res_col;
                    } else {
                        break;
                    }
                }
                if (res_col == size) {
                    return true;
                }
            }
            return false;
        }

        bool is_in_the_table(size_t num) {
            for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                    if (data[i][j].val == num) {
                        data[i][j].isChecked = true;
                        return true;
                    }
                }
            }
            return false;
        }

        size_t get_amount_of_unchecked() {
            size_t res = 0;
            for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                    if (!data[i][j].isChecked) {
                        res += data[i][j].val;
                    }
                }
            }
            return res;
        }

        friend istream& operator>> (std::istream& in, Table& table) {
            for (size_t i = 0; i < table.size; ++i) {
                for (size_t j = 0; j < table.size; ++j) {
                    in >> table.data[i][j];
                }
            }
            return in;
        }

        friend ostream& operator<< (std::ostream& out, const Table& table) {
            for (size_t i = 0; i < table.size; ++i) {
                for (size_t j = 0; j < table.size; ++j) {
                    out << setw(2) << table.data[i][j].val << " ";
                }
                out << endl;
            }
            return out;
        }

        size_t size = 5;
        vector<vector<Cell>> data;
    };
   
    vector<size_t> bingo_nums = read_values<size_t>("data/bingo_nums.txt");
    vector<Table> bingo_tables = read_values<Table>("data/bingo_tables.txt");

    int problem1() {
        for (const auto num : bingo_nums) {
            for (auto& table : bingo_tables) {
                if (table.is_in_the_table(num)) {
                    if (table.win_check()) {
                        //cout << "num: " << num << " " << "res: " << table.get_amount_of_unchecked() * num << endl << table << endl;
                        cout << table;
                        return table.get_amount_of_unchecked() * num;
                    }
                }
            }
        }
        return 0;
    }

    int problem2() {
        return 0;
    }
};