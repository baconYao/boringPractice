class IntegerDemo :
    
    
    @classmethod
    def set_value(cls,value = int(input("value: ")),p = int(input("p: "))):
        cls.value = value
        cls.p = p

    def add(cls):
        return cls.value + cls.p
    def subtract(cls):
        return cls.value - cls.p
    def multiply(cls):
        return cls.value * cls.p
    def division(cls):
        return cls.value / cls.p

i = IntegerDemo()
i.set_value()
print("add:",i.add())
print("subtract:",i.subtract())
print("multiply:",i.multiply())
print("division:",i.division())

