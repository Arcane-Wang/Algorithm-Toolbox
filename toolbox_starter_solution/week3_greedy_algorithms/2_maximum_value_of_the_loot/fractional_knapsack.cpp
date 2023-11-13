#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  std::vector<std::vector<double>> value_per_weight;
  for (int i = 0; i < weights.size(); i++){
    value_per_weight.push_back({(double)values[i] / weights[i], (double)weights[i]});
  }
  std::sort(value_per_weight.begin(), value_per_weight.end(), [](std::vector<double> a, std::vector<double> b){return a[0] > b[0];});
  int idx = 0;
  while (capacity > 0 && idx < value_per_weight.size()){
    if (capacity >= value_per_weight[idx][1]){
      value += value_per_weight[idx][0] * value_per_weight[idx][1];
      capacity -= value_per_weight[idx][1];
    } else {
      value += value_per_weight[idx][0] * capacity;
      capacity = 0;
    }
    idx++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
