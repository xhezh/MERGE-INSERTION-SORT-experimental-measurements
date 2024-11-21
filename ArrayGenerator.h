#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class ArrayGenerator {
public:
  // √енераци€ случайного массива
  static std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(minValue, maxValue);
    for (int& x : arr) {
      x = dis(gen);
    }
    return arr;
  }

  // √енераци€ массива, отсортированного в обратном пор€дке
  static std::vector<int> generateReversedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
      arr[i] = size - i;
    }
    return arr;
  }

  // √енераци€ "почти отсортированного" массива
  static std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
      arr[i] = i;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, size - 1);
    for (int i = 0; i < swaps; i++) {
      int idx1 = dis(gen);
      int idx2 = dis(gen);
      std::swap(arr[idx1], arr[idx2]);
    }
    return arr;
  }
};