## Lab3


1.本次实验从文件ex3_Graph1.txt，ex3_Graph2.txt读取数据文件建立有向网，并遍历图，输出节点值；注意数据文件 矩阵中 -1 表示 不存在这条有向边，例如ex3_Graph1.txt中，s0行 s3列 的元素-1，表示不存在从s0到s3的边。

2.针对上步建立的第一个图的有向网,分别求出从节点s0到节点s1,s2,s3,s4的最短路径及对应的权值；针对上步建立的第二个图，求出节点a到节点h的最短路径及对应权值。

sample out：

    graph1 ：

          s0->s1  path : s0,s4,s3,s1  value=70

          s0->s2  path : s0,s2           value=30

          s0->s3  path : s0,s4,s3      value=60

          s0->s4  path : s0,s4           value=10

    graph2：

          a->h     path: a,c,e,f,h        value=9
