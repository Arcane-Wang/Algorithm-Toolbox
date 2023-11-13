#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void insertion_sort(vector<int> &a, int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= l && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}


void heap_sort(vector<int> &a, int l, int r) {
  std::make_heap(a.begin() + l, a.begin() + r + 1);
  for (int i = r; i >= l; i--) {
    std::pop_heap(a.begin() + l, a.begin() + i + 1);
  }
}

void introsort_helper(vector<int> &a, int l, int r, int depth_limit) {
  if (r - l < 16) {
    insertion_sort(a, l, r);
    return;
  }
  if (depth_limit == 0) {
    heap_sort(a, l, r);
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  introsort_helper(a, l, m - 1, depth_limit - 1);
  introsort_helper(a, m + 1, r, depth_limit - 1);
}

void introsort(vector<int> &a, int l, int r) {
  int depth_limit = 2 * log(r - l + 1);
  introsort_helper(a, l, r, depth_limit);
  // insertion_sort(a, l, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  introsort(a, l, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
