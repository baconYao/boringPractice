class IntegerDemo :

    @classmethod
    def __init__(cls,value = 11,p = None):
        if p is None:
            cls.__value = value
            cls.__p = value
        else:
            cls.__value = value
            cls.__p = p

    def add(cls):
        return cls.__value + cls.__p
    def subtract(cls):
        return cls.__value - cls.__p
    def multiply(cls):
        return cls.__value * cls.__p
    def division(cls):
        return cls.__value / cls.__p

if __name__ == "__main__":
    i = IntegerDemo()
    print("add:",i.add())
    print("subtract:",i.subtract())
    print("multiply:",i.multiply())
    print("division:",i.division())        
