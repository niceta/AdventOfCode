#include "Day6.h"
#include <chrono>

int main() {
    Day6 d;
    auto start_time = std::chrono::high_resolution_clock::now();
    cout << d.problem2() << endl;
    auto current_time = std::chrono::high_resolution_clock::now();

    std::cout << "Program has been running for " << std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
    return 0;
}