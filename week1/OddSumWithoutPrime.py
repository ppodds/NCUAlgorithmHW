import math

def is_prime(x):
    for i in range(2, math.floor(math.sqrt(x))+1):
        if x%i==0:
            return False
    return True


for _ in range(int(input())):
    a, b = input().split()
    a = int(a)
    b = int(b)
    sum = 0
    for i in range(a, b+1):
        if i%2==0:
            continue
        if not is_prime(i):
            sum += i
    print(sum)
        