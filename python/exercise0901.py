class IntegerDemo :
    value = 25
    
    @classmethod
    def set_value(cls):
        cls.value = value

    def add(cls,p = 24):
        return cls.value + p

i = IntegerDemo()
print(i.add())
