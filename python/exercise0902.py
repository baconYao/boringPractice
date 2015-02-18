class IntegerDemo :
    value = int(input("value: "))
    p = int(input("p: "))

    @classmethod
    def set_value(cls):
        cls.value = value
        cls.p = p

    def add(cls):
        return cls.value + cls.p

i = IntegerDemo()
print(i.add())
