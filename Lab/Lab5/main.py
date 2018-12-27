# -*- coding:utf-8 -*-
import os
import time
import pickle
import random
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy import interpolate  # 插值
from sort import *


def generate_data(n, method="order"):
    data = [i for i in range(n)]
    if method == "anti":
        data.reverse()
    elif method == 'rand':
        random.shuffle(data)
    return data


def average(x):
    return sum(x) / len(x)


def analize(N, data, method):
    map = {'order': u"顺序", 'anti': u"逆序", 'rand': u"随机"}

    plt.figure()
    plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
    plt.title(map[method] + u"数据下冒泡排序和快速排序运行时间变化趋势")
    plt.xlabel(u"数据规模N")
    plt.ylabel(u"运行时间(ms)")

    x = np.array(N)
    y1 = np.array(data['buddle_sort'])
    y2 = np.array(data['quick_sort'])

    x_new = np.linspace(x.min(), x.max(), 10000)
    f = interpolate.UnivariateSpline(x, y1, k=2, s=1)
    plt.plot(x_new, f(x_new), label=u"冒泡排序")

    f = interpolate.UnivariateSpline(x, y2, k=2, s=1)
    plt.plot(x_new, f(x_new), c='c', label=u"快速排序")

    plt.legend()
    plt.savefig(method + ".png")


if __name__ == "__main__":
    N = [10, 50, 100, 300, 500, 800, 1500, 2500]
    if os.path.exists("time_use.data"):
        time_use = pickle.load(open("time_use.data", "rb"))
    else:
        time_use = {'buddle_sort': {'order': [], 'anti': [], 'rand': []},
                    'quick_sort': {'order': [], 'anti': [], 'rand': []}}
        for n in N:
            for method in ['order', 'anti', 'rand']:
                time_tmp = {'quick_sort': [], 'buddle_sort': []}
                for i in range(10):
                    data = generate_data(n, method)
                    data_cp = data
                    start_time = time.clock()
                    buddle_sort(data)
                    end_time = time.clock()
                    time_tmp['buddle_sort'].append((end_time - start_time) * 1e3)
                    start_time = time.clock()
                    quick_sort(data_cp, 0, len(data_cp) - 1)
                    end_time = time.clock()
                    time_tmp['quick_sort'].append((end_time - start_time) * 1e3)

                time_use['buddle_sort'][method].append(average(time_tmp['buddle_sort']))
                time_use['quick_sort'][method].append(average(time_tmp['quick_sort']))
        pickle.dump(time_use, open("time_use.data", "wb"))

    for method in ['order', 'anti', 'rand']:
        data = {'quick_sort': time_use['quick_sort'][method],
                'buddle_sort': time_use['buddle_sort'][method]}
        analize(N, data, method)
        print(method + ":")
        data = pd.DataFrame(data)
        data.index = N
        print(data)
