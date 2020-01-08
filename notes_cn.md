# 题解笔记

## 2019-01

### 4. Madian Sorted Arrays

- 2个sorted数组，取第K大的数
- 用left_k，right_k（left_k + 1）的trick解决奇偶长度的问题

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
