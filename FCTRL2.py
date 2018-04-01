def fact():
    x = 2
    i = 1
    factorials = [1]
    size = 100
    while(size):
        factorials.append(factorials[i-1]*x)
        size = size - 1
        x = x + 1
        i = i + 1
    return factorials


t = int(input())
factorials = fact()
while t:
    n = int(input())
    if n == 0:
        print (1)
    else:
        print(factorials[int(n-1)])
    t = t-1