# -*-coding:utf-8 -*
import os
import random

data = [str(i) for i in range(1, 2048, 2)]

with open("data.txt", "w") as f:
    f.write(" ".join(data))

with open("data.txt", "a+") as f:
    while data:
        rand = random.randint(0, len(data) - 1)
        f.write(data[rand] + " ")
        data.pop(rand)
