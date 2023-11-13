from sys import stdin


def partition3(values):
    # check if the values can be evenly divided to 3 sets, each set has the same sum
    # if yes, return 1, otherwise return 0
    # also record the values that can be used to form the sum
    def helper(values, parts_num):
        total = sum(values)
        if total % parts_num != 0:
            return 0
        else:
            target = total // parts_num
            value = [[0 for _ in range(target + 1)] for _ in range(len(values) + 1)]
            paths = [[[] for _ in range(target + 1)] for _ in range(len(values) + 1)]
            
            for i in range(1, len(values) + 1):
                for w in range(1, target + 1):
                    value[i][w] = value[i - 1][w]
                    paths[i][w] = paths[i-1][w]
                    if values[i - 1] <= w:
                        val = value[i - 1][w - values[i - 1]] + values[i - 1]
                        if value[i][w] < val:
                            value[i][w] = val
                            paths[i][w] = paths[i-1][w-values[i-1]] + [i]
            if value[-1][-1] == target:
                # print("Valid path numbers: ")
                for idx in paths[-1][-1]:
                    # print(values[idx-1])
                    values[idx-1] = 0
                return 1
            else:
                return 0

    parts_num = 3
    while parts_num > 1:
        if helper(values, parts_num) == 0:
            return 0
        parts_num -= 1
    return 1



if __name__ == '__main__':
    input_n, *input_values = list(map(int, stdin.read().split()))
    assert input_n == len(input_values)
    
    print(partition3(input_values))
