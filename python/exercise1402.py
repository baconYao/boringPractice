#猜數字遊戲
import random

class aabb_game:
    def __init__(self):
        self.choiced = []
    def generate_four_number(self):
        #選到的號碼
        for i in range(4):
            self.choiced.append(random.choice([x for x in range(0,10) if x not in self.choiced]))
        print(self.choiced)
    def game_code(self):
        key = True
        while key is True:
            A = 0
            B = 0
            s = input("input four number:")
            if len(s) == 4:
                if s[0] != s[1] and s[0] != s[2] and s[0] != s[3] and s[1] != s[2] and s[1] != s[3] and s[2] != s[3]:
                    for i in range(4):
                        for x in range(4):
                            #數字相同
                            if self.choiced[i] == int(s[x]):
                                #且位置相同
                                if i == x:
                                    A +=1
                                else:
                                    B +=1
                    if A == 4 and B == 0:
                        key == False
                        print("Congratulation , you win ! The answer is:",s)
                    else:
                        print("A: ",A," B: ",B)
                else:
                    print("There is the same number in your input , enter again!")
            else:
                print("Your input isn't four digit number!")
                print("Please enter again!")

if __name__ == '__main__':
    game = aabb_game()
    game.generate_four_number()
    game.game_code()



#可以改善的地方:
    #判斷使用者是不是輸入數字
    #優化使用者輸入的數字有無重複
