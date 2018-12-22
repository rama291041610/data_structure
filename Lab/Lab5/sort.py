# -*-coding:utf-8 -*-
import random


def buddle_sort(data):
    for i in range(len(data)):
        flag = 0
        for j in range(len(data) - 1):
            if data[j + 1] < data[j]:
                data[j + 1], data[j] = data[j], data[j + 1]
                flag = 1
        if flag == 0:
            break


def quick_sort(data, begin, end):
    if begin >= end:
        return
    l = begin
    r = end
    rand = random.randint(l + 1, r)
    data[l], data[rand] = data[rand], data[l]
    tmp = data[l]
    while l < r:
        while l < r and data[r] >= tmp:
            r -= 1
        if l < r:
            data[l] = data[r]
            l += 1
        while l < r and data[l] < tmp:
            l += 1
        if l < r:
            data[r] = data[l]
            r -= 1
    data[l] = tmp
    quick_sort(data, begin, l - 1)
    quick_sort(data, l + 1, end)
