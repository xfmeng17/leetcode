# 题解笔记

## 2019-01

### 4. Madian Sorted Arrays

- 2个sorted数组，取第K大的数
- 用left_k，right_k（left_k + 1）的trick解决奇偶长度的问题

### 398. Random Pick Index

- 随机索引，其实想模拟蓄水池问题（Reservoir Sampling）
- 了解蓄水池问题，理解蓄水池抽样算法中概率均等特点
- 蓄水池<https://cloud.tencent.com/developer/news/293271>
- 更好的模拟应该是stream流输入，每一个index造一个大小为10的池子，这样既节约空间有O（1）pick
