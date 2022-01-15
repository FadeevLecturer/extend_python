import helloworld
import math


help(helloworld)

print(helloworld.say_hello())
print(helloworld.say_bye("Egor"))


x = 2
def f(x):
    return math.sqrt(x) ** 2

print(helloworld.call(f, x))