#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector, std::map;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  // want to map the index of the sorted points to its original index
  vector <std::pair<int, int>> points_with_index;
  for (size_t i = 0; i < points.size(); ++i) {
    points_with_index.push_back(std::make_pair(points[i], i));
  }
  std::sort(points_with_index.begin(), points_with_index.end());
  
  
  //write your code here
  vector<std::pair<int, char>> pairs;
  for (size_t i = 0; i < starts.size(); ++i) {
    pairs.push_back(std::make_pair(starts[i], 'l'));
    pairs.push_back(std::make_pair(ends[i], 'r'));
  }
  for (size_t i = 0; i < points.size(); ++i) {
    pairs.push_back(std::make_pair(points[i], 'p'));
  }
  std::sort(pairs.begin(), pairs.end());
  int count = 0;
  int idx = 0;
  for (size_t i = 0; i < pairs.size(); ++i) {
    if (pairs[i].second == 'l') {
      ++count;
    } else if (pairs[i].second == 'r') {
      --count;
    } else {
      cnt[points_with_index[idx].second] = count;
      ++idx;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
