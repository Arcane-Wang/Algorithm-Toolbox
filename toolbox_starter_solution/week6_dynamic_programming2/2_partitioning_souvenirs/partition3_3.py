from sys import stdin
from itertools import combinations

def partition3(nums):
    # check if the values can be evenly divided to 3 sets, each set has the same sum
    # if yes, return 1, otherwise return 0
    # also record the values that can be used to form the sum
    nums.sort(reverse = True)
    result = []
    if sum(nums) % 3 != 0:
        return 0
    target = sum(nums) // 3
    
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
    
    return 1 if if_found else 0
    



if __name__ == '__main__':
    # input_n, *input_values = list(map(int, stdin.read().split()))
    # assert input_n == len(input_values)
    
    # print(partition3(input_values))

    import random, matplotlib.pyplot as plt, time, tqdm
    sizes = [i for i in range(1, 900, 1)]
    times = []
    for size in tqdm.tqdm(sizes):
        # nums = [1] * size
        nums = [random.randint(1, 100) for _ in range(size)]
        start = time.time()
        temp = partition3(nums)
        end = time.time()
        times.append(end - start)
        print("Size: {}, Time: {}, Result: {}".format(size, end - start, temp))
        
    plt.plot(sizes, times)
    plt.show()
    