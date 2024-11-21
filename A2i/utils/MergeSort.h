#ifndef A2I_UTILS_MERGESORT_H_
#define A2I_UTILS_MERGESORT_H_

#include <functional>
#include <iterator>
#include <vector>

class MergeSort {
 public:
  template<typename Iterator>
  static std::vector<typename std::iterator_traits<Iterator>::value_type> Classic(Iterator begin, Iterator end);

  template<typename Iterator>
  static std::vector<typename std::iterator_traits<Iterator>::value_type> Optimized(Iterator begin, Iterator end);

 private:
  template<typename Iterator>
  static void InsertionSort(Iterator begin, Iterator end);

  template<typename Iterator>
  static std::vector<typename std::iterator_traits<Iterator>::value_type> Merge(Iterator left_begin, Iterator left_end, Iterator right_begin, Iterator right_end);

  const static int _insertion_threshold = 20;
};

#endif //A2I_UTILS_MERGESORT_H_
