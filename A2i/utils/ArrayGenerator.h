#ifndef A2I_UTILS_ARRAYGENERATOR_H_
#define A2I_UTILS_ARRAYGENERATOR_H_

#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

class ArrayGenerator {
 public:
  static std::vector<int> GenerateRandomArray(int size, int min_value, int max_value);
  static std::vector<int> GenerateReverseSortedArray(int size, int min_value, int max_value);
  static std::vector<int> GenerateAlmostSortedArray(int size, int min_value, int max_value, int swap_count = 7);
  static std::vector<int> GetSubArray(const std::vector<int>& array, int sub_size);
};

#endif //A2I_UTILS_ARRAYGENERATOR_H_
