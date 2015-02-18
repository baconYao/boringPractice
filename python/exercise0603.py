a = int(input("成績:"))

while(True):
    if a < 60:
        print("Bad!")
    elif a >= 60 and a < 70:
        print("Not Bad!")
    elif a >= 70 and a < 80:
        print("Good!")
    elif a >= 80 and a < 90:
        print("Great!")
    elif a >= 90 and a < 100:
        print("Excellent")
    else :
        print("Perfect!")
