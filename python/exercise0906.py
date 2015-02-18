class IntegerDemo :
    print("WW")
    p = int(input("input hierarchy: "))
    value = 1
    @classmethod
    def set_value(cls):
        cls.p = p
        cls.value = value

    def hierarchy(cls):
        for i in range(1 ,cls.p+1 ,+1 ):
            cls.value*= i
        return cls.value

i = IntegerDemo()
print("hierarchy ",i.p,"!: ",i.hierarchy())


