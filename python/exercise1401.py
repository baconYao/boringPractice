class ex1401:
    def __init__(self):
        self.setcode()
    def setcode(self):
        self.a = ["abc",(6),6,268,"qq",[6],"hello",99,552,6]
    def getcode(self):
        i = 0
        while i < 10:
            if self.a[i] == 6:
                print("self.a[",i,"] is 6")
            i += 1

if __name__ == '__main__':
    e = ex1401()
    e.getcode()
