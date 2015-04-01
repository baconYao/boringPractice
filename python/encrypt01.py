import random

#定義encrypt類別
class Encrypt:
    def __init__(self):
        self.setcode()
    def setcode(self):
        a = 0
        b = 0
        while a % 2 == 0:
            a = random.randint(0,9)
            b = random.randint(0,9)
        self.code = ""
        c = "a"
        i = 0
        while i < 26:
            x = c
            y = ord(x) * a + b
            m = y % 26
            self.code +=chr(m + 97)
            c = chr(ord(c) + 1)
            i += 1
    def getcode(self):
        return self.code
    #編碼的方法
    def toEncode(self,str):
        #暫存編碼結果的字串
        result = ""
        #利用迴圈走完參數字串的所有自元
        for c in str:
            #判斷英文字母是不是小寫
            #若是英文小寫字母就進行編碼
            c1 = ord(c) >= 97
            c2 = ord(c) <= 122
            if c1 and c2:
                m = ord(c) - 97
                result += self.code[m]
            else:
                result += c
        return result
    #解碼的方法
    def toDecode(self,str):
        #暫存解碼結果
        result = ""

        i = 0
        #第一層迴圈逐一取得每一個字元
        while i < len(str):
            #判斷英文字母是不是小寫
            #若是英文小寫字母就進行解碼
            i1 = ord(str[i]) >= 97
            i2 = ord(str[i]) <= 122
            if i1 and i2:
                j = 0
                #第二層迴圈尋找該字元在密碼表中的索引值，再加上DIFF就可轉換回原本的字元
                while j < len(self.code):
                    if str[i] == self.code[j]:
                        result += chr(97 + j)
                    j += 1
            else:
                result += str[i]
            i += 1
        return result
#測試部分
if __name__ == "__main__":
    e = Encrypt()
    print()
    print(e.getcode())
    s1 = "There is no spoon."
    print("Input :" + s1)

    s2 = e.toEncode(s1)
    print("Encode :" + s2)
    
    s3 = e.toDecode(s2)
    print("Decode :" + s3)
    print()
