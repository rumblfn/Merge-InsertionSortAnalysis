#include "MergeSort.h"
#include "SortTester.h"
#include "ArrayGenerator.h"

void SortTester::RandomArray() {
  std::cout << "Test array with random values \n";
  auto generated_nums = ArrayGenerator::GenerateRandomArray(10000, 0, 6000);
  Run(generated_nums);
}

void SortTester::AlmostSortedArray() {
  std::cout << "Test almost sorted array \n";
  auto generated_nums = ArrayGenerator::GenerateAlmostSortedArray(10000, 0, 6000, 302);
  Run(generated_nums);
}

void SortTester::ReverseSortedArray() {
  std::cout << "Test reverse sorted array \n";
  auto generated_nums = ArrayGenerator::GenerateReverseSortedArray(10000, 0, 6000);
  Run(generated_nums);
}

void SortTester::Run(std::vector<int>& generated_nums) {
  std::cout << "Classic merge sort \n";
  ProcessSort(generated_nums, MergeSort::Classic<std::vector<int>::iterator>);

  std::cout << "Insertion + merge sort \n";
  ProcessSort(generated_nums, MergeSort::Optimized<std::vector<int>::iterator>);
}

template<typename Func, typename... Args>
void SortTester::ProcessSort(std::vector<int>& generated_nums, Func func) {
  std::vector<std::pair<int, double>> measurements;
  for (int sub_size = 500; sub_size <= 10000; sub_size += 100) {
    double sum = 0;
    for (int i = 0; i < _measurements_count; ++i) {
      auto sub_nums = ArrayGenerator::GetSubArray(generated_nums, sub_size);
      sum += ProcessTime(func, sub_nums.begin(), sub_nums.end());
    }
    double average_time = sum / _measurements_count;
    measurements.emplace_back(sub_size, average_time);
  }
  Out(measurements);
}

template<typename Func, typename... Args>
double SortTester::ProcessTime(Func func, Args &&... args) {
  auto start = std::chrono::high_resolution_clock::now();
  func(std::forward<Args>(args)...);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  return (double)std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}

void SortTester::Out(std::vector<std::pair<int, double>>& measurements) {
  std::cout << "{\n";
  for (auto& measurement : measurements) {
    std::cout << '"' << measurement.first << "\": " <<  measurement.second << (measurement == measurements.back() ? "\n" : ",\n");
  }
  std::cout << "}\n";
}