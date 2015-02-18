a = int(input("input:"))

k1 = 0
k2 = 1
k3 = 1

if a == 1:
    print(k1)
elif a == 2:
    print(k2)
elif a == 3:
    print(k2)
elif a < 1:
    print("nothing")
else:
    for i in range(3,a,+1):
        s = k2 + k3
        k2 = k3
        k3 = s
        if i == a-1:
            print("i:",i)
            print(s)
