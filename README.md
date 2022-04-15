# PCCAwinterCamp2022

---
tags : 2022 PCCA camp
title : 題單
---
# 2022 PCCA camp


[All Of My Code](https://github.com/peterxcli/PCCAwinterCamp2022)

### dsu

- [X] https://open.kattis.com/problems/ladice
- [X] https://open.kattis.com/problems/control
- [X] https://codeforces.com/contest/1609/problem/D

### heap

- [X] https://open.kattis.com/problems/janeeyre
- [X] https://open.kattis.com/problems/continuousmedian

### segment tree

- [ ] https://codeforces.com/contest/446/problem/C

  - [~~題解~~](https://i.imgur.com/9vIrsdi.png)
- [X] https://codeforces.com/problemset/problem/52/C
- [X] https://open.kattis.com/problems/justforsidekicks
- [X] https://codeforces.com/problemset/problem/1547/F

  - $a_i$經$k$次操作後第$i$項會變為$gcd(a_{i}, a_{i+1}, a_{i+2},..., a_{i+k})$
  - 且$gcd$是可以分治的操作，所以$gcd(...)$用segment tree或sparse table作區間查詢
  - 最後用二分單調找最小操作數
- [X] https://codeforces.com/contest/622/problem/C

  - state : $dp[i]$ means the position of the first element to the left from the $i^{th}$ element
  - transfer : $dp[i] = (a[i] \neq a[i-1] ? i-1 : dp[i-1]), dp[0] = 0$
- [X] https://codeforces.com/contest/1555/problem/E

  - sort segments by $w_i$
  - two pointer with segment tree
    :::

### dp

#### basic

- [X] https://open.kattis.com/problems/commercials
- [X] https://open.kattis.com/problems/alphabet
- [X] https://open.kattis.com/problems/walrusweights
- [X] https://open.kattis.com/problems/knapsack
- [ ] https://open.kattis.com/problems/increasingsubsequence
  - [題解QQ](https://www.hackerrank.com/challenges/super-kth-lis/editorial)
- [X] https://open.kattis.com/problems/ninepacks
- [ ] https://open.kattis.com/problems/spiderman
- [ ] https://open.kattis.com/problems/presidentialelections
- [ ] https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=615
- [ ] https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2326
- [ ] https://toj.tfcis.org/oj/pro/80/

#### advance

- [ ] https://open.kattis.com/problems/canonical
- [ ] https://codeforces.com/gym/103443/problem/I
- [ ] https://open.kattis.com/problems/orders
- [ ] https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

  * 我们首先考虑至少有两个元素的等差子序列，下文将其称作弱等差子序列。
  * 由于尾项和公差可以确定一个等差数列，因此我们定义状态 $f[i][d]$ 表示尾项为 $nums[i]$，公差为 $d$ 的弱等差子序列的个数。
  * 我们用一个二重循环去遍历 $nums$ 中的所有元素对 $(nums[i],nums[j])$，其中 $j<i$。将 $nums[i]$ 和 $nums[j]$ 分别当作等差数列的尾项和倒数第二项，则该等差数列的公差 $d=nums[i]-nums[j]$。由于公差相同，我们可以将 $nums[i]$ 加到以 $nums[j]$ 为尾项，公差为 $d$ 的弱等差子序列的末尾，这对应着状态转移 $f[i][d]+=f[j][d]$。同时，$(nums[i],nums[j])$ 这一对元素也可以当作一个弱等差子序列，故有状态转移:

    $$
    f[i][d] += f[j][d] + 1

    $$
  * 由于题目要统计的等差子序列至少有三个元素，我们回顾上述二重循环，其中「将 $nums[i]$ 加到以 $nums[j]$ 为尾项，公差为 $d$ 的弱等差子序列的末尾」这一操作，实际上就构成了一个至少有三个元素的等差子序列，因此我们将循环中的 $f[j][d]$ 累加，即为答案。
  * 代码实现时，由于 $nums[i]$ 的范围很大，所以计算出的公差的范围也很大，我们可以将状态转移数组 $f$ 的第二维用哈希表代替。
- [ ] https://leetcode.com/problems/russian-doll-envelopes/

### graph

- [ ] https://tioj.ck.tp.edu.tw/problems/1509
- [ ] https://codeforces.com/problemset/problem/938/D
- [ ] https://codeforces.com/contest/1463/problem/E

### linear algebra

* [x] https://toj.tfcis.org/oj/pro/174/
* [x] https://toj.tfcis.org/oj/pro/466/
* [x] https://zerojudge.tw/ShowProblem?problemid=a542
* [ ] https://tioj.ck.tp.edu.tw/problems/2170

### 模擬賽

- [ ] https://codeforces.com/group/zRMlZHwppH/contest/364321
- [ ] https://codeforces.com/group/zRMlZHwppH/contest/365494


[題單](https://hackmd.io/@peter12345678/B1BE4ik0Y)
