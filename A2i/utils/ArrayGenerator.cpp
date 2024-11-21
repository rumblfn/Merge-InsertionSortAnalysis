#include "ArrayGenerator.h"

std::vector<int> ArrayGenerator::GenerateRandomArray(int size, int min_value, int max_value) {
  std::vector<int> array(size);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min_value, max_value);

  for (int i = 0; i < size; ++i) {
    array[i] = dis(gen);
  }

  return array;
}

std::vector<int> ArrayGenerator::GenerateReverseSortedArray(int size, int min_value, int max_value) {
  std::vector<int> array = GenerateRandomArray(size, min_value, max_value);
  std::sort(array.begin(), array.end(), std::greater<>());
  return array;
}

std::vector<int> ArrayGenerator::GenerateAlmostSortedArray(int size, int min_value, int max_value, int swap_count) {
  std::vector<int> array = GenerateRandomArray(size, min_value, max_value);
  std::sort(array.begin(), array.end());

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, size - 1);

  for (int i = 0; i < swap_count; ++i) {
    int idx1 = dis(gen);
    int idx2 = dis(gen);
    std::swap(array[idx1], array[idx2]);
  }

  return array;
}

std::vector<int> ArrayGenerator::GetSubArray(const std::vector<int>& array, int sub_size) {
  if (sub_size > array.size()) {
    throw std::invalid_argument("Invalid sub size.");
  }

  std::vector<int> subArray(array.begin(), array.begin() + sub_size);
  return subArray;
}
