from random import shuffle

#建立Encrypt物件同同時建立密碼表
class Encrypt:
    def __init__(self,str=None):
        #設定code
        if str == None:
            self.code = [chr(i) for i in range(97,123)]
            shuffle(self.code)
        else:
            self.code = list(str)

        #設定alph
        self.alph = [chr(i) for i in range(97,123)]

        #print(self.code)
        #print(self.alph)

    #回傳密碼表字串
    def __str__(self):
        code = "".join(self.code)
        return "code: " + code

    def toEncode(self,str):
        #暫存解碼結果
        result = ""

        #利用迴圈走完參數字串的所有字元
        for i in str:
            #判斷英文字母是不是小寫
            #若是英文小寫字母就進行編碼
            if i in self.code:
                j = self.alph.index(i)
                result += self.code[j]
            else:
                result += i
        return result

    def toDecode(self,str):
        #暫存解碼結果
        result = ""

        #利用迴圈走完參數字串的所有字元
        for i in str:
            #判斷英文字母是不是小寫
            #若是英文小寫字母就進行解碼
            if i in self.code:
                j = self.code.index(i)
                result += self.alph[j]
            else:
                result += i
        return result
#測試部分
if __name__ == "__main__":
    e = Encrypt()
    print()
    s1 = "There is no spoon."
    print("Input :" + s1)

    s2 = e.toEncode(s1)
    print("Encode :" + s2)
    
    s3 = e.toDecode(s2)
    print("Decode :" + s3)
    print()
