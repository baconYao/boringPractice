class IntegerDemo :

    @classmethod
    def set_value(cls,value = 5,p = int(input("p: "))):
        cls.__value = value
        cls.p = p

    def add(cls):
        return cls.__value + cls.p
    def subtract(cls):
        return cls.__value - cls.p
    def multiply(cls):
        return cls.__value * cls.p
    def division(cls):
        return cls.__value / cls.p

i = IntegerDemo()
i.set_value()
i.__value = 2
print(i.__value)
print("add:",i.add())
print("subtract:",i.subtract())
print("multiply:",i.multiply())
print("division:",i.division())

