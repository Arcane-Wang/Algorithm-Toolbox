#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

bool if_found = false;

void backtrack(int start, vector<int>& path, int current_sum, int found_sets_num, unordered_set<int>& used_idxs, const vector<int>& nums, int target) {
    if (found_sets_num == 3 && used_idxs.size() == nums.size()) {
        if_found = true;
        return;
    }
    if (current_sum == target) {
        found_sets_num += 1;
        for (int p : path) {
            used_idxs.insert(p);
        }
        vector<int> new_path{};
        backtrack(0, new_path, 0, found_sets_num, used_idxs, nums, target);
        found_sets_num -= 1;
        for (int p : path) {
            used_idxs.erase(p);
        }
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (current_sum + nums[i] <= target && used_idxs.find(i) == used_idxs.end()) {
            path.push_back(i);
            backtrack(i + 1, path, current_sum + nums[i], found_sets_num, used_idxs, nums, target);
            path.pop_back();
            if (if_found) {
                return;
            }
        }
    }
}

int partition3(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    if_found = false;
    unordered_set<int> used_idxs;
    int target = accumulate(nums.begin(), nums.end(), 0) / 3;
    if (accumulate(nums.begin(), nums.end(), 0) % 3 != 0) {
        return 0;
    }
    vector<int> new_path{};
    backtrack(0, new_path, 0, 0, used_idxs, nums, target);

    return if_found ? 1 : 0;
}

int main() {
    vector<int> nums;
    // Read input or generate input as needed
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        nums.push_back(rand() % 100 + 1);
    }

    vector<int> sizes;
    for (int i = 1; i < 5000; i++) {
        sizes.push_back(i);
    }

    vector<double> times;
    for (int size : sizes) {
        vector<int> nums(size);
        generate(nums.begin(), nums.end(), []() { return rand() % 100 + 1; });

        clock_t start_time = clock();
        int result = partition3(nums);
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Size: " << size << ", Time: " << elapsed_time << ", Result: " << result << endl;
        times.push_back(elapsed_time);
    }

    // Plotting the times if needed
    // ...

    return 0;
}
