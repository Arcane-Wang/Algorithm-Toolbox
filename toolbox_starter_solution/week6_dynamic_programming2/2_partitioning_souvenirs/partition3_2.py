from sys import stdin
from itertools import combinations

def partition3(nums):
    # check if the values can be evenly divided to 3 sets, each set has the same sum
    # if yes, return 1, otherwise return 0
    # also record the values that can be used to form the sum
    nums.sort()
    result = []
    if sum(nums) % 3 != 0:
        return 0
    target = sum(nums) // 3
    # def helper_dp(values):
    #     def helper(values, parts_num):
    #         total = sum(values)
    #         if total % parts_num != 0:
    #             return 0
    #         else:
    #             target = total // parts_num
    #             value = [[0 for _ in range(target + 1)] for _ in range(len(values) + 1)]
    #             paths = [[[] for _ in range(target + 1)] for _ in range(len(values) + 1)]
                
    #             for i in range(1, len(values) + 1):
    #                 for w in range(1, target + 1):
    #                     value[i][w] = value[i - 1][w]
    #                     paths[i][w] = paths[i-1][w]
    #                     if values[i - 1] <= w:
    #                         val = value[i - 1][w - values[i - 1]] + values[i - 1]
    #                         if value[i][w] < val:
    #                             value[i][w] = val
    #                             paths[i][w] = paths[i-1][w-values[i-1]] + [i]
    #             if value[-1][-1] == target:
    #                 # print("Valid path numbers: ")
    #                 for idx in paths[-1][-1]:
    #                     # print(values[idx-1])
    #                     values[idx-1] = 0
    #                 return 1
    #             else:
    #                 return 0

    #     parts_num = 3
    #     while parts_num > 1:
    #         if helper(values, parts_num) == 0:
    #             return 0
    #         parts_num -= 1
    #     return 1
    
    # if helper_dp(nums) == 1:
    #     return 1
    
    if_found = False
    def backtrack(start, path, current_sum, found_sets_num, used_idxs):
        nonlocal if_found
        if found_sets_num == 3 and len(used_idxs) == len(nums):
            if_found = True
            return
        if current_sum == target:
            found_sets_num += 1
            for p in path:
                used_idxs.add(p)
            backtrack(0, [], 0, found_sets_num, used_idxs)
            # result.append(path[:])
            found_sets_num -= 1
            for p in path:
                used_idxs.remove(p)
            return
        for i in range(start, len(nums)):
            if current_sum + nums[i] <= target and i not in used_idxs:
                path.append(i)
                backtrack(i + 1, path, current_sum + nums[i], found_sets_num, used_idxs)
                path.pop()
                if if_found:
                    return
    
    backtrack(0, [], 0, 0, set())
    
    # def check_three_sets(sets, a):
    #     # Ensure there are at least 3 sets
    #     if len(sets) < 3:
    #         return 0

    #     # Generate all combinations of 3 sets
    #     set_combinations = combinations(sets, 3)

    #     # Check each combination
    #     for combination in set_combinations:
    #         # Check if any two sets in the combination overlap
    #         if not any(set1 & set2 for set1, set2 in combinations(combination, 2)):
    #             # Check if the union length is equal to a
    #             union_set = set().union(*combination)
    #             if len(union_set) == a:
    #                 return 1

    #     # No such combination found
    #     return 0
    
    # taken_idxs = [set(i) for i in result]
    # return check_three_sets(taken_idxs, len(nums))
    return 1 if if_found else 0 
    



if __name__ == '__main__':
    input_n, *input_values = list(map(int, stdin.read().split()))
    assert input_n == len(input_values)
    print(partition3(input_values))
