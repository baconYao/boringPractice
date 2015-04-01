class Demo:
    def __init__(self,v1 = 11,v2 = None):
        if v2 is None:
            self.__a = v1
            self.__b = v1
        else:
            self.__a = v1
            self.__b = v2
    def do_something(self):
        return self.__a + self.__b
if __name__ == "__main__":
    d = Demo(12,34)
    print(d.do_something())
