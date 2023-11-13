#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> min_steps(n + 1, 0);
  std::vector<int> prev(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    min_steps[i] = 1000000;
    if (i % 3 == 0) {
      int num_steps = min_steps[i / 3] + 1;
      if (num_steps < min_steps[i]) {
        min_steps[i] = num_steps;
        prev[i] = i / 3;
      }
    }
    if (i % 2 == 0) {
      int num_steps = min_steps[i / 2] + 1;
      if (num_steps < min_steps[i]) {
        min_steps[i] = num_steps;
        prev[i] = i / 2;
      }
    }
    int num_steps = min_steps[i - 1] + 1;
    if (num_steps < min_steps[i]) {
      min_steps[i] = num_steps;
      prev[i] = i - 1;
    }
  }
  int i = n;
  while (i > 0) {
    sequence.push_back(i);
    i = prev[i];
  }
  std::reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
