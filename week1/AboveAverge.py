for _ in range(int(input())):
    user_in = input().split()
    scores = user_in[1:]

    student_amount = int(user_in[0])
    sum = 0
    for score in scores:
        sum += int(score)
    avg = sum/int(user_in[0])

    amount = 0
    for score in scores:
        if int(score) > avg:
            amount += 1
    print('%.3f' % round(amount / int(user_in[0]) * 100, 3) + '%')    