n = input()
n = int(n)
status = 1
list = []
i = 0
while i < n:
    str = input()
    list.append(str)
    i += 1
ml = sorted(list, key = len)
i = 0
while i < n - 1:
    if ml[i] in ml[i + 1]:
        status = 1
    else:
        status = 0
        break
    i += 1
if status == 1:
    print ("YES")
    for i in range(n):
        print (ml[i])
else:
    print ("NO")