## Data Structure
### Lab

#### Lab1

##### Problem1：线性链表的实现

任务描述：
实现线性表的链式存储结构—线性链表。并完成：  
* 从文件输入一批整数，建立有序链表（升序）  
Sample：input.txt 的内容为： 10 9 5 6 33 13 31 34 31 3843 23 -3 8  
* 查找一个指定元素  
* 插入一个指定元素   
* 删除一个指定元素  
* 统计链表的长度  
* 输出线性链表  
* 实现按逆序重建链表  

##### Problem2：两多项式相加

描述：  
我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。  

如多项式2x^20^ - x^17^ + 5x^9^- 7x^7^ + 16x^5^ + 10x^4^ + 22x^2^ - 15  

对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。    

为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。  

同时输入表达式的幂数大小顺序是随机的。  

输入  
输入包括多行。  
第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100)  
下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。  
每行长度小于300。  

输出  
输出包括n行，每行为1组多项式相加的结果。  
在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。
系数为零的项不要输出。  

样例输入：  
2  
-1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1  
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8  
-1 17 2 23 22 2 6 8 -4 7 -18 0 1 5 21 4 0 -1  
3 17 2 19 15 10 12 7 -4 5 23 4 -18 0 8 -1  


#### Lab2

实验项目：树型结构的建立与遍历  
实验题目：二叉树存储结构的建立与遍历  
实验内容：树型结构的遍历是树型结构算法的基础，本实验要求编写程序演示二叉树的存储结构的建立方法和遍历过程。     
实验要求：    
1．编写建立二叉树的二叉链表存储结构（左右链表示）的程序，并以适当的形式显示和保存二叉树；   
2．采用二叉树的二叉链表存储结构，编写程序实现二叉树的先序、中序和后序遍历的递归和非递归算法以及层序遍历算法，并以适当的形式显示和保存二叉树及其相应的遍历序列；   
3．给定一个二叉树， 编写算法完成下列应用:（二选一）  
（1）判断其是否为完全二叉树；  
（2）求二叉树中任意两个结点的公共祖先。  


### Homework

[Josephus.py](./Homework/Josephus.py) 约瑟夫环