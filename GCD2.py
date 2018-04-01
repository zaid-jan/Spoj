def gcd(a,b):
    if a is 0 or b is 0:
        return 0
    if a is b:
        return a
    if a>b:
        return gcd(a-b,b)
    return gcd(a,b-a)

def main():
    t = int(input())
    while (t>0):
        string = input()
        nums = string.split()
        print(gcd(int(nums[0]),int(nums[1])))
        t = t-1
    return 0


main()