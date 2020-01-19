# 题解笔记

## 2019-01

### 4. Madian Sorted Arrays

- 2个sorted数组，取第K大的数
- 用left_k，right_k（left_k + 1）的trick解决奇偶长度的问题
- 每次取第k/2位置的元素`val1，val2`比较，如果`val1 < val2`，则有`k/2`可以排除了，`arr1`起点`+ k/2`，递归查找第`k-k/2`大的数

### 398. Random Pick Index

- int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);
pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
- 随机索引，其实想模拟蓄水池问题（Reservoir Sampling）
- 了解蓄水池问题，理解蓄水池抽样算法中概率均等特点
- 蓄水池<https://cloud.tencent.com/developer/news/293271>
- 更好的模拟应该是stream流输入，每一个index造一个大小为10的池子，这样既节约空间有O（1）pick
- 其实可以进行扩展，服务化，提供/stream和/pick接口，多线程读写锁解决同步问题，hub模式通过hash解决多key的分布式，通过hub中对各子节点val值计数解决分布子节点不均匀的问题
- 2020-01-02补充，没有节点不均匀的问题，因为最大就是池子的大小

### 297. Serialize and Deserialize Binary Tree

- BST序列化与反序列化，中序遍历
- 序列化逻辑拆分：1-basic情况检测，2-int->string->char vector，3-recursive左树，然后recursive右子树
- 反序列化逻辑拆分：1-定义一个全局起始position，传递为指针，2-末尾边界check，3-取整段char转为int，4-position更新，递归左右

### 138. Copy List with Random Pointer

- 解法1，造个2个map，旧的[pointer, index]，新的[index, pointer]，先遍历一次create，设map，再遍历一次通过2个map找到random
- 注意random=NULL
- 解法2，A -> A'-> B -> B'-> C -> C':
    1. 插入copy
    2. random=random->next
    3. 分离

### 146. LRU Cache

- LRU，hashmap + double linked list
- 对于GET，2种情况，没找到/找到，找到调用PUT刷新last use
- 对于PUT，3种情况:
  - key在，delete删除双端链表节点，add添加新节点
  - key不在，size < cap，直接add
  - key不在，size = cap，eliminate淘汰最后的，返回淘汰的key，**map同步删除key**，执行add
- [LRU原理和Redis实现——一个今日头条的面试题](https://zhuanlan.zhihu.com/p/34133067?utm_source=wechat_session&utm_medium=social&utm_oi=28320779468800)

### 221. Maximal Square

- DP
- 如果 matrix[i][j] = '1', [i, j] = min([i+1, j], [i, j+1], [i+1, j+1]) + 1
- 如果 matrix[i][j] = '0', [i, j] = 0

### 236. Lowest Common Ancestor of a Binary Tree

```c++
// 如果p, q落在不同子树，则LCU是当前的root
// 如果p, q落在相同子树，递归左右的子问题，直至p,q落在不同子树
TreeNode* func2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode* left = func2(root->left, p, q);
    TreeNode* right = func2(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return left != NULL ? left : right;
}
```

### 300. Longest Increasing Subsequence

1. DP, copy+sort+unique初始数组，然后计算两个数组的LCS的长度，因为longest-common-subsequence时间是O(n^2)的，最终就是O(n^2)的，所以：
2. **要得到o(nlogn)的时间复杂度，该怎么做呢？** O(nlogn)的解法参考<https://blog.csdn.net/sgbfblog/article/details/7798737>，简述例子如[12, 17, 18, 19, 14, 15, 16]，构筑的逆序数组流程为：
    - 初始 [16]
    - 15，二分查找=1 > 数组大小，数组append为[16, 15]
    - 14，同上[16, 15, 14]
    - 19，二分查找=0，替换16为19，原因为19对应的长度和16一样，都是1，但是19比16大，如果16对于某一个点是递增的，那么19也一定递增
    - 18，同上，之后的省略
    - **注意**，二分查找，为，在一个逆序数组中，找到比target小的最大的元素

    ```golang
    // ** O(nlogn) binary-search solution, interesting
    func func3(nums []int) int {
        n := len(nums);
        arr := make([]int, 0);

        for i := n-1; i >= 0; i-- {
            idx := findLargestLessOrEqualThanTarget(arr, nums[i]);
            if idx >= len(arr) {
                arr = append(arr, nums[i])
            } else {
                arr[idx] = nums[i];
            }
        }

        return len(arr);
    }

    /* 
    * nums is inverted order and return the index that nums[index] is the
    * largest element <= target
    * eg: [19,18,17,16,10], find target | nums[lo] | nums[hi] | ret:
    * 20 | nums[0]=19 | nums[-1]=  | 0
    * 19 | nums[0]=19 | nums[0]=19 | 0
    * 12 | nums[4]=10 | nums[3]=16 | 4
    * 09 | nums[5]=   | nums[4]=10 | 5
    */
    func findLargestLessOrEqualThanTarget(nums []int, target int) int {
        lo := 0;
        hi := len(nums) - 1;

        for (lo <= hi) {
            mid := (lo + hi) / 2;
            if nums[mid] == target {
                return mid;
            } else if nums[mid] > target {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }
    ```
3. 标准DP，从左到右迭代，dp[i]为，从0到i，以i为结束，最长的LIS，从右到左迭代，dp[i]为，从i到n-1（尾），最长的LIS，时间均为O(n^2)

### 673. Number of Longest Increasing Subsequence

- DP，300求LIS的变种，多比较相等的情况，迭代中，保存每个点的最大的LIS的个数即可，之后，统一用得到的max_length迭代比较进行统计


### 通用二分查找整理

无论是找最右，大于target的最小，小于target的最大等等，**不要背代码**，在草纸上，用一个三元组[3, 5, 7]，while条件都是`while (lo <= hi)`**测试以下4种**情况即可：

- 0，比全部都小
- 9，比全部都大
- 3，存在值
- 4，在其间
