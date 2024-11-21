#ifndef A2I_UTILS_SORTTESTER_H_
#define A2I_UTILS_SORTTESTER_H_

#include <vector>
#include <iostream>

class SortTester {
 public:
  void RandomArray();
  void AlmostSortedArray();
  void ReverseSortedArray();

 private:
  void Run(std::vector<int>& generated_nums);

  template<typename Func, typename... Args>
  void ProcessSort(std::vector<int>& generated_nums,  Func func);

  template<typename Func, typename... Args>
  double ProcessTime(Func func, Args&&... args);

  void Out(std::vector<std::pair<int, double>>& measurements);

  const int _measurements_count = 10;
};

#endif //A2I_UTILS_SORTTESTER_H_
