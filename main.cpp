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


// Завдання 2: сортування імен за довжиною
bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

void task2() {
    std::cout << "\n=== Task 2: sort by length + function pointer ===" << std::endl;

    std::vector<std::string> names = {
        "Alice", "Bob", "Catherine", "Dan", "Elizabeth", "Fu", "George"
    };

    std::cout << "Before: ";
    for (auto it = names.begin(); it != names.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // compareByLength — вказівник на функцію порівняння
    std::sort(names.begin(), names.end(), compareByLength);

    std::cout << "After (sorted by length): ";
    for (auto it = names.begin(); it != names.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


// Завдання 3: застосувати знижку через фанктор
struct Applicator {
    double rate;

    explicit Applicator(double r) : rate(r) {}

    void operator()(double& price) {
        price = price * (1.0 - rate);  // ціна мінус знижка
    }
};

void task3() {
    std::cout << "\n=== Task 3: for_each + functor ===" << std::endl;

    std::deque<double> prices = { 100.0, 250.0, 89.99, 420.0, 15.50 };

    std::cout << "Before: ";
    for (auto it = prices.begin(); it != prices.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Applicator(0.1) — створюємо фанктор зі знижкою 10%
    std::for_each(prices.begin(), prices.end(), Applicator(0.1));

    std::cout << "After 10% discount: ";
    for (auto it = prices.begin(); it != prices.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


int main() {
    task1();
    task2();
    task3();
    std::cin.get();
    return 0;
}
