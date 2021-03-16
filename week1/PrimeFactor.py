import math

def is_prime(x):
    for i in range(2, math.floor(math.sqrt(x))+1):
        if x%i==0:
            return False
    return True


user_input = int(input())
if user_input == 1:
    print('1=1*1')
    exit()
answer = ''

temp = user_input
for i in range(2, user_input):
    if is_prime(i):
        check = False
        temp_ans = ''
        exp = 1
        while (temp%i==0):
            if not check:
                check = True
                temp_ans += str(i)
            else:
                if exp==1:
                    temp_ans += '^'
                exp += 1
            temp /= i
        if exp != 1:
            temp_ans += str(exp)
        if check:
            answer += temp_ans + '*'
        if temp==1:
            break
if answer[-1:] == '*':
    print(str(user_input) + '=' + answer[:-1])
else:
    print(str(user_input) + '=' + answer)
