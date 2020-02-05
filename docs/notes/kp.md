# Knapsack Problem 背包问题

## 2019-02 整理

> 主要参考自[背包9讲](https://www.kancloud.cn/kancloud/pack/70124)，这里做个备份

## 1. 01背包(ZeroOnePack)

### 1.1 题目说明

有N件物品，和一个容量为V的背包，求解将哪些物品放到背包中能获得最大的价值。**每件物品只能放一次，即`放`或者`不放`。** 第i件物品的费用（重量等，付出）是c[i]，第i件物品的价值（得到）是w[i]。

### 1.2 基本思路

最基础的背包问题，特点是物品只能放到背包一次，自有放还是不放的状态。动态转移方程为：
`f[i][v] = max(f[i-1][v], f[i-1][v-c[i]] + w[i])`

最重要的方程，先说明下各个变量：f[i][v]表示，第0...i个物品，放到一个容量为v的背包中，能获得的最大收益。v表示背包容量，c[i]表示第i个物品的消耗，w[i]表示第i个物品的获得。

迭代时，面对一个物品i，只有两中操作，取或者不取。所以，在面对第i个物品，背包容量为v时，不取便是f[i-1][v]，取便是f[i-1][v-c[i]] + w[i]

### 1.3 优化空间

注意，转移方程中，取时，用的是`f[i-1][v-c[i]] + w[i]`，需要之前一个容量更小背包的值。**所以当我们从`V...0`计算时，就可以优化掉f[i]这维，这是理解所有背包问题的关键，需要时间消化。** 优化后有如下伪代码：

```python
for i=1...N
    for v=V..0
        f[v]=max{f[v],f[v-c[i]] + w[i]}
```

使用一维背包的代码过程以后会被多次用到，抽象出来：

```python
procedure ZeroOnePack(cost, weight) {
    for V...cost
        f[v] = max(f[v], f[v-cost] + weight)
}
```

这样，01背包便成为：

```python
for 1...N
    ZeroOnePack(c[i], w[i])
```

### 1.4 初始化细节

我们看到的求最优解的背包问题题目中，事实上有两种不太相同的问法。**有的题目要求“恰好装满背包”时的最优解，有的题目则并没有要求必须把背包装满。** 一种区别这两种问法的实现方法是在初始化的时候有所不同。

如果是第一种问法，要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-INF，这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解，-INF表示无法恰好装满。

如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。

## 2. 完全背包(CompletePack)

### 2.1 题目说明

有N件物品，和一个容量为V的背包，求解将哪些物品放到背包中能获得最大的价值。**每件物品可以放无限次，即`放0...+INF`次。** 第i件物品的费用（重量等，付出）是c[i]，第i件物品的价值（得到）是w[i]。

### 2.2 基本思路

仿照01背包问题，递归方程应该是:
`f[i][v] = f[i-1][v-k*c[i]]+k*w[i]), 0 <= k*c[i] <= v`
但是用上面递归方程复杂度基本就是GG了，那么最trick的来啦，完全背包问题可以直接转换为01背包问题得到O(VN)的算法：

```python
for i=1..N
    for v=0..V
        f[v]=max{f[v], f[v-c[i]] + w[i]}
```

完全背包的实现只和01背包在V的迭代次序上不同，01背包是从`V...0`，而完全背包是从`0...V`，具体理解可以参考背包9讲的原文。目前我觉得我能理解，但是还说不明白。

所以完全背包的递归方程为：
`f[i][v] = max(f[i-1][v], f[i][v-c[i]] + w[i])`

伪代码为：
```python
procedure CompletePack(cost, weight)
    for v=cost...V
        f[v]=max{f[v],f[v-c[i]]+w[i]}
```

## 3. 多重背包问题(MultiplePack)

> 2020-02-04，暂时整理到这，LeetCode上还只有01和完全背包问题

### 3.1 题目说明

有N件物品，和一个容量为V的背包，求解将哪些物品放到背包中能获得最大的价值。**每件物品最多有n[i]件可用** 第i件物品的费用（重量等，付出）是c[i]，第i件物品的价值（得到）是w[i]。

### 3.2 基本思路

如果每个物品i，有 `c[i] * n[i] >= V`，那么这个题和完全背包就一样，难受的就是存在小于的情况。简述为，借用二进制表示的方法，采用2^n指数递增的方式模拟01背包的处理过程，伪代码如下：

```python
procedure MultiplePack(cost, weight, amount)
    if cost * amount >= V
        CompletePack(cost,weight)
        return
    integer k = 1
    while k < amount
        ZeroOnePack(k * cost, k * weight)
        amount = amount - k
        k = k * 2
    ZeroOnePack(amount * cost, amount * weight)
```

### 3.3 O(VN)算法

楼天成的“男人八题”幻灯片里面最简单的那个题，0.0

## 4. 混合三种背包问题(MixedPack)

## 5. 二维费用背包问题(2DimensionPack)

### 5.1 题目说明

有N件物品，和一个容量为V的背包，求解将哪些物品放到背包中能获得最大的价值。**每件物品有2种费用需要花费** 第i件物品的费用（重量等，付出）是`a[i]`，`b[i]`，第i件物品的价值（得到）是w[i]。

### 5.2 基本思路

费用加了一维，状态的存储也加一维即可，与01背包问题相似。动态转移方程为：
`f[i][v][u] = max(f[i-1][v][u], f[i-1][v-a[i]][u-b[i]] + w[i])`

### 5.3 隐式说明

有时候，“二位费用”的条件是以一种隐含的方式给出：**最多只能取M件物品**。这事实上相当于没件物品多了一个“件数”的费用，每个物品的件数费用均为1，可以付出的最大为M。类比其他背包问题，这里就不赘述了。

## 附录1：LeetCode上的背包问题

1. [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)，标准 `01背包`，入门题目，[Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0416.go)
2. [322. Coin Change](https://leetcode.com/problems/coin-change/)，标准 `完全背包`，入门题目，[Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0322.go)
3. [518. Coin Change 2](https://leetcode.com/problems/coin-change-2/)，`完全背包`，求解组成的可能数，[Cpp](https://github.com/xfmeng17/leetcode/blob/master/Cpp/0518.go)
4. [474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)，标准 `二维01背包`，`f[i][m][n]=xxx`，[Golang](https://github.com/xfmeng17/leetcode/blob/master/Golang/0474.go)