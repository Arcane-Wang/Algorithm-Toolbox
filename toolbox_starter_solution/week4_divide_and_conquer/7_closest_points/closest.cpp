#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::min;
using std::sort;

using Point = pair<int, int>;

double distance_squared(Point pt1, Point pt2)
{
    return (pt1.first - pt2.first) * (pt1.first - pt2.first) + (pt1.second - pt2.second) * (pt1.second - pt2.second);
}

double minimal_distance_helper(vector<Point> pts, int start, int end)
{
    if (start >= end) return DBL_MAX;
    if (start + 1 == end)
        return distance_squared(pts[start], pts[end]);
    int mid = start + (end - start) / 2;
    double min_dist_left = minimal_distance_helper(pts, start, mid);
    double min_dist_right = minimal_distance_helper(pts, mid + 1, end);
    double min_dist_within = min(min_dist_left, min_dist_right);

    double boundary_x = ((double)pts[mid].first + pts[mid + 1].first) / 2;
    double x_min = boundary_x - min_dist_within;
    double x_max = boundary_x + min_dist_within;

    int l = start, i = l;
    while (i <= end)
    {
        if (pts[i].first >= x_min && pts[i].first <= x_max)
        {
            swap(pts[l++], pts[i]);
        }
        i++;
    }
    
    // sort start ... l - 1;
    // sort(pts.begin() + start, pts.begin() + l, [](Point pt1, Point pt2) { return pt1.second < pt2.second; });

    double min_dist = min_dist_within;
    for (int i = start; i < l; ++i)
    {
        for (int j = i + 1; j < min(i + 8, l); ++j)
        {
            if ((pts[i].first < boundary_x && pts[j].first < boundary_x) || 
                (pts[i].first > boundary_x && pts[j].first > boundary_x))
                continue;
            min_dist = min(min_dist, distance_squared(pts[i], pts[j]));
        }
    }
    return min_dist;
}

double minimal_distance(vector<int> x, vector<int> y) {
    vector<Point> pts(x.size());
    for (int i = 0; i < x.size(); ++i)
        pts[i] = make_pair(x[i], y[i]);

    sort(pts.begin(), pts.end());

    double min_dist = minimal_distance_helper(pts, 0, pts.size() - 1);

    return sqrt(min_dist);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}