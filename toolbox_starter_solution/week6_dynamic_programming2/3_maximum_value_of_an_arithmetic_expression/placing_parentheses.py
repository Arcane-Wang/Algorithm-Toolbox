def evaluate(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def min_and_max(i, j, m, M, operators):
    min_val = float('inf')
    max_val = float('-inf')
    #  i <= k < j
    for k in range(i, j):
        a = evaluate(M[i][k], M[k + 1][j], operators[k]) # M[i][k] and M[k + 1][j] are the max values of the subexpressions
        b = evaluate(M[i][k], m[k + 1][j], operators[k]) 
        c = evaluate(m[i][k], M[k + 1][j], operators[k])
        d = evaluate(m[i][k], m[k + 1][j], operators[k])
        min_val = min(min_val, a, b, c, d)
        max_val = max(max_val, a, b, c, d)
    return min_val, max_val

def maximum_value(dataset):
    # write your code here
    digits = []
    operators = []
    for i in range(len(dataset)):
        if i % 2 == 0:
            digits.append(int(dataset[i]))
        else:
            operators.append(dataset[i])
    n = len(digits)
    m = [[0 for _ in range(n)] for _ in range(n)]
    M = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        m[i][i] = digits[i]
        M[i][i] = digits[i]
    # s is the distance between i and j
    for s in range(1, n):
        # i is the starting index
        for i in range(n - s):
            j = i + s
            m[i][j], M[i][j] = min_and_max(i, j, m, M, operators)
    return M[0][n - 1]


if __name__ == "__main__":
    print(maximum_value(input()))
