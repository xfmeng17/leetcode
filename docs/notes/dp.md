# Dynamic Programming 动态规划

## 2019-01 整理

## 1. 动态规划的理解

- 动态规划，和分治法(divide-and-conquer)一样，都是将大问题拆分成小问题，通过计算更容易得到的小问题的解，再汇集成大问题的解。
- 分治法是把问题拆分成`相互独立`的子问题，适用于拆分的子问题是互不影响的。相反，动态规划适用于子问题是`相互重叠`的，即存在两个子问题可能都包含同一个子子问题，在这种情况下，仍用分治法，在递归中容易反复计算某一个子问题，造成不必要的浪费。
- 所以，动态规划只求解子问题一次，然后把得到的结果保存到表格中，从而避免反复求解同一个子问题。
- Dynamic Programming中的Programming，是指一种`表格计数法`的意思，而不是指写代码。动态规划应该理解成，在一张表格上，动态的更新表格中得到的解。（联想做过的那些DP题，就像面前有一个N*N的大表格，不断地往里面添数，擦去旧结果，填写新的更优结果）
- 解题思路拆成4部分：
    1. 描绘求解最优问题的结构
    2. 递归的定义求解方程
    3. 从下到上的，依据已经得到的子问题的解，迭代求解问题
    4. 通过得到的每一步的最优解，回溯出得到最终最优解的路径（或选择，或过程）


## 2. 动态规划的判定

1. 求，最优问题(optimization problems) *人话：问题有很多个解，找个最好的，比如现实问题中，操作次数最少的，花费金额最少的等等*
2. 有，最优子结构(optimal sunstructure) *人话：求一个0...N的问题，其最优解由更小规模的0...N-1子问题的某个比较优秀的解得到，如果用子问题的最优解一定能得到问题的最优解，那就是贪心了*
3. 有，重叠子问题(overlapping subproblems) *人话：某两个N规模的问题，可能用到同一个N-1规模的子问题，那就求解这个子问题一次就OK*

## 3. LeetCode解题流程

参考自LeetCode上一个题解[From good to great. How to approach most of DP problems](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.)，简单来说，就是解决常见的DP问题，**分5步走**

> 1. `想出递归关系，或递归方式。`这一步最关键，决定了接下来的4步，这步想对了，接下来4步就是体力活，想错了可能很难得到最优解
> 2. Top-Down递归的方法
> 3. Top-Down递归 + 中间结果的保存（记忆化递归），一般是传入一个全局的array或者map，保存得到的子问题的解，当再次递归到同一个子问题时，直接返回结果
> 4. Bottom-Up迭代，通过一个2维或1维数组，从子问题0迭代求解到子问题N，即得到最终问题的解
> 5. Bottom-Up迭代，通过方法4发现可能迭代中只用到最近的一些数据，如迭代i层，只会用到i-1层，迭代j，可能只会用到比j小的列，从而`降维步骤#4的存储，达到节省空间的目的`

当足够熟练时，基本上思考出一个步骤#1，就能得到递归方程式，就能在脑海中得到步骤#2和步骤#3的代码，就能知道时空复杂度，进而验证步骤#1的想法可行与否，然后直接去写步骤#4的代码，在写的过程中，就知道如何压缩用到的存储，进而去写步骤#5的代码，得到最好的实现。

## 4. LeetCode例题简述

### 2020-01

#### [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/1143.cpp)
- 标准LCS

#### [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0300.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0300.go)
- 标准LIC，最长递增子序列，可以先排序，然后求排序好的和初始的LCS
- TODO，整理二分O(nlogn)的解法

#### [673. Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0673.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0673.go)
- 同理300，无法二分，只能用标准DP

#### [397. Integer Replacement](https://leetcode.com/problems/integer-replacement/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0397.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0397.go)
- 简单DP，注意N=int32是，最大值溢出，使用long

#### [139. Word Break](https://leetcode.com/problems/word-break/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0139.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0139.go)
- 一维`dp[i]`表示string从`0...i`的子结果
- 二维`dp[i][j]`表示string从`i...j`的子结果
- 二维是O(n^3)的time，一维是O(n^2)的，`一维要好很多，证明了想对递归关系，非常关键`
- **2020-02-04补充**：如果二维`dp[i][j]`表示string从`i...j`的子结果，那么迭代时，直接把`substring[0...i-1]`和`substring[j+1...n-1]`当成一个word判定，那么其实也是O(n^2)的Time

### 2020-02

#### [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0377.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0377.go)
- 简单DP，其实有Integer溢出隐患

#### [474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

- [Cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/0474.cpp), [Golang](https://github.com/xfmeng17/leetcode/blob/master/golang/0474.go)
- `dp[i][m][n]` 表示数组内第i个数，m个0，n个1的结果，实现上直接砍掉dp[i]那维，用`dp1`，`dp2`

#### [Best Time to Buy and Sell Stock 系列](https://xfmeng17.github.io/leetcode/notes/buy-sell-stock/)