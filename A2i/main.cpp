#include <iostream>

#include "utils/SortTester.h"

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);

  SortTester sort_tester;

  sort_tester.RandomArray();
  sort_tester.AlmostSortedArray();
  sort_tester.ReverseSortedArray();

  return 0;
}
