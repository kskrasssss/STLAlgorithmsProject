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


// Завдання 4: count_if + фанктор WithinRange
struct WithinRange {
    int minVal;
    int maxVal;

    WithinRange(int mn, int mx) : minVal(mn), maxVal(mx) {}

    // Повертає true якщо n між minVal і maxVal включно
    bool operator()(int n) const {
        return n >= minVal && n <= maxVal;
    }
};

void task4() {
    std::cout << "\n=== Task 4: count_if + functor ===" << std::endl;

    std::set<int> numbers = { 3, 7, 12, 25, 38, 41, 55, 67, 80, 95 };

    std::cout << "Set: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // WithinRange(20, 70) — фанктор для діапазону [20, 70]
    int count = std::count_if(numbers.begin(), numbers.end(), WithinRange(20, 70));

    std::cout << "Count in [20, 70]: " << count << std::endl;
}

// Завдання 5: map складу, показати кількість > 100
void task5() {
    std::cout << "\n=== Task 5: for_each + lambda ===" << std::endl;

    std::map<std::string, int> warehouse = {
        {"apples",  150},
        {"bananas",  80},
        {"oranges", 200},
        {"grapes",   45},
        {"lemons",  110}
    };

    std::cout << "Items with quantity > 100:" << std::endl;

    // Лямбда приймає пару {key, value} з map
    // auto& pair — щоб не копіювати
    std::for_each(warehouse.begin(), warehouse.end(),
        [](const std::pair<std::string, int>& item) {
            if (item.second > 100) {
                std::cout << "  " << item.first
                    << ": " << item.second << std::endl;
            }
        });
}



// Завдання 6: замінити від'ємні числа на 0
void task6() {
    std::cout << "\n=== Task 6: replace_if + lambda ===" << std::endl;

    std::vector<int> nums = { 3, -1, 4, -1, 5, -9, 2, 6, -5, 3 };

    std::cout << "Before: ";
    for (auto it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::replace_if(nums.begin(), nums.end(),
        [](int n) { return n < 0; },
        0);

    std::cout << "After (negatives ? 0): ";
    for (auto it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main() {
    task1();
    task2();
    task3();
	task4();
	task5();
	task6();
    std::cin.get();
    return 0;
}
