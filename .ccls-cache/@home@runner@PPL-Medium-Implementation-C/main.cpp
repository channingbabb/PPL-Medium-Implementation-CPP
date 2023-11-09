#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template<typename T>
void quick_sort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    T pivot = arr[0];
    std::vector<T> left;
    std::vector<T> right;
    for (auto it = arr.begin() + 1; it != arr.end(); ++it) {
        if (*it <= pivot) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
    }
    quick_sort(left);
    quick_sort(right);
    arr.clear();
    arr.insert(arr.end(), left.begin(), left.end());
    arr.push_back(pivot);
    arr.insert(arr.end(), right.begin(), right.end());
}

const size_t MAX_SIZE = 100000000;

int main() {
    std::vector<uint32_t> arr(MAX_SIZE, 0);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<uint32_t> dist(1, MAX_SIZE);
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = dist(rng);
    }
auto now = std::chrono::steady_clock::now();
quick_sort(arr);
auto elapsed = std::chrono::steady_clock::now() - now;
std::cout << "Sorted " << arr.size() << " numbers in:" << std::endl;
std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << " ms" << std::endl;
std::cout << std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() << " seconds" << std::endl;
return 0;
}
