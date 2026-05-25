#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <random>
#include <numeric>

// Завдання 1: видалити непарні з std::list

bool isOdd(int n) {
    return n % 2 != 0;
}

void task1() {
    std::cout << "=== Task 1: remove_if + function pointer ===" << std::endl;

    std::mt19937 rng(42);  // 42 — seed, фіксує послідовність чисел
    std::uniform_int_distribution<int> dist(1, 100);

    std::list<int> numbers;
    for (int i = 0; i < 20; i++) {
        numbers.push_back(dist(rng));
    }

    std::cout << "Before: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    auto newEnd = std::remove_if(numbers.begin(), numbers.end(), isOdd);

    numbers.erase(newEnd, numbers.end());

    std::cout << "After (only even): ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main() {
    task1();
    std::cin.get();
    return 0;
}
