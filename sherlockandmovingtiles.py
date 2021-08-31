import math

def calculator(l, var, v1, v2):
    q = var
    h = l-math.sqrt(q)
    r = h/(abs(v1-v2)/math.sqrt(2))
    return r

if __name__ == '__main__':
    entrada = input()
    entrada = entrada.split()
    l, v1, v2 = map(int, entrada)

    n = int(input())
    queries = []

    for i in range(n):
        var = int(input())
        r = calculator(l, var, v1, v2) 
        queries.append(r)

    for i in queries:
        print(i)