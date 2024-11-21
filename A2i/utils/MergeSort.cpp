#include "MergeSort.h"

template std::vector<int> MergeSort::Classic<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
template std::vector<int> MergeSort::Optimized<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);

template<typename Iterator>
std::vector<typename std::iterator_traits<Iterator>::value_type> MergeSort::Classic(Iterator begin, Iterator end) {
  auto size = std::distance(begin, end);

  if (size <= 1) {
    return { begin, end };
  }

  auto mid = std::next(begin, size / 2);

  auto left_sorted = Classic(begin, mid);
  auto right_sorted = Classic(mid, end);

  return Merge(left_sorted.begin(), left_sorted.end(), right_sorted.begin(), right_sorted.end());
}

template<typename Iterator>
std::vector<typename std::iterator_traits<Iterator>::value_type> MergeSort::Optimized(Iterator begin, Iterator end) {
  auto size = std::distance(begin, end);

  if (size <= _insertion_threshold) {
    std::vector<typename std::iterator_traits<Iterator>::value_type> result(begin, end);
    InsertionSort(result.begin(), result.end());
    return result;
  }

  auto mid = std::next(begin, size / 2);

  auto left_sorted = Optimized(begin, mid);
  auto right_sorted = Optimized(mid, end);

  return Merge(left_sorted.begin(), left_sorted.end(), right_sorted.begin(), right_sorted.end());
}

template<typename Iterator>
void MergeSort::InsertionSort(Iterator begin, Iterator end) {
  for (Iterator i = std::next(begin); i != end; ++i) {
    auto key = *i;
    auto j = i;
    while (j != begin && *(std::prev(j)) > key) {
      *j = *(std::prev(j));
      --j;
    }
    *j = key;
  }
}

template<typename Iterator>
std::vector<typename std::iterator_traits<Iterator>::value_type> MergeSort::Merge(Iterator left_begin, Iterator left_end, Iterator right_begin, Iterator right_end) {
  std::vector<typename std::iterator_traits<Iterator>::value_type> result;
  result.reserve(std::distance(left_begin, left_end) + std::distance(right_begin, right_end));

  while (left_begin != left_end && right_begin != right_end)
    result.push_back(*left_begin < *right_begin ? *left_begin++ : *right_begin++);

  result.insert(result.end(), left_begin, left_end);
  result.insert(result.end(), right_begin, right_end);

  return result;
}