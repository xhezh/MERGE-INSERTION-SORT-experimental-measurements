#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <string>
#include "ArrayGenerator.h"

class SortTester {
public:
  // Замер времени работы функции
  static long long measureTime(std::vector<int> arr, std::function<void(std::vector<int>&)> sortFunc) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
  }

  // Тесы
  static void runTests(const std::vector<int>& sizes, int minValue, int maxValue, int swaps,
    std::function<void(std::vector<int>&)> sortFunc, const std::string& testName) {
    for (int size : sizes) {
      auto randomArray = ArrayGenerator::generateRandomArray(size, minValue, maxValue);
      auto reversedArray = ArrayGenerator::generateReversedArray(size);
      auto nearlySortedArray = ArrayGenerator::generateNearlySortedArray(size, swaps);
      std::cout << "Test: " << testName << ", Size: " << size << '\n';
      std::cout << "Random Array: " << measureTime(randomArray, sortFunc) << " ms" << '\n';
      std::cout << "Reversed Array: " << measureTime(reversedArray, sortFunc) << " ms" << '\n';
      std::cout << "Nearly Sorted Array: " << measureTime(nearlySortedArray, sortFunc) << " ms" << '\n';
    }
  }
};
