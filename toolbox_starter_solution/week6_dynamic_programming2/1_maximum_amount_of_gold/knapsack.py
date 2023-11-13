from sys import stdin


def maximum_gold(capacity, weights):
    value = [[0 for _ in range(capacity + 1)] for _ in range(len(weights) + 1)]
    for i in range(1, len(weights) + 1):
        for w in range(1, capacity + 1):
            value[i][w] = value[i - 1][w]
            if weights[i - 1] <= w:
                val = value[i - 1][w - weights[i - 1]] + weights[i - 1]
                if value[i][w] < val:
                    value[i][w] = val
    return value[-1][-1]


if __name__ == '__main__':
    input_capacity, n, *input_weights = list(map(int, stdin.read().split()))
    assert len(input_weights) == n

    print(maximum_gold(input_capacity, input_weights))
