/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func rob(root *TreeNode) int {
	// Error
	// return func1(root);
	return func2(root);
}

func func1(root *TreeNode) int {
	nums := level_sum(root);
	return func_0198(nums);
}

func func2(root *TreeNode) int {
	node_map := make(map[*TreeNode]int);
	return helper2(root, node_map);
}
func helper2(root *TreeNode, node_map map[*TreeNode]int) int {
	if root == nil {
		return 0;
	}
	if val, ok := node_map[root]; ok {
		return val;
	}

	leftleft := 0;
	leftright := 0;
	rightleft := 0;
	rightright := 0;
	if root.Left != nil {
		leftleft = helper2(root.Left.Left, node_map);
		leftright = helper2(root.Left.Right, node_map);

	}
	if root.Right != nil {
		rightleft = helper2(root.Right.Left, node_map);
		rightright = helper2(root.Right.Right, node_map);
	}
	dp_rob := root.Val + leftleft + leftright + rightleft + rightright;
	
	dp_not := helper2(root.Left, node_map) + helper2(root.Right, node_map);

	node_map[root] = max(dp_rob, dp_not);

	return node_map[root];
}

func level_sum(root *TreeNode) []int {
	nums := make([]int, 0);
	node_queue := make([]*TreeNode, 0);
	level_queue := make([]int, 0);
	
	if root == nil {
		return nums;
	}

	node_queue = append(node_queue, root);
	level_queue = append(level_queue, 0);

	for len(node_queue) > 0 {
		node := node_queue[0];
		level := level_queue[0];
		if len(nums) <= level {
			nums = append(nums, node.Val);
		} else {
			nums[level] += node.Val;
		}
		if node.Left != nil {
			node_queue = append(node_queue, node.Left);
			level_queue = append(level_queue, level+1);
		}
		if node.Right != nil {
			node_queue = append(node_queue, node.Right);
			level_queue = append(level_queue, level+1);
		}
		node_queue = node_queue[1:];
		level_queue = level_queue[1:];
	}

	return nums;
}

func func_0198(nums []int) int {
    if len(nums) <= 0 {
        return 0;
    }
    if len(nums) == 1 {
        return nums[0];
    }
    if len(nums) == 2 {
        return max(nums[0], nums[1]);
    }
    
    n := len(nums);
    dp := make([]int, n);
    dp[0] = max(0, nums[0]);
    dp[1] = max(dp[0], nums[1]);
    ret := max(0, max(dp[0], dp[1]));
    
    for i := 2; i < n; i++ {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        ret = max(ret, dp[i]);
    }
    return ret;
}

func max(a int, b int) int {
    if (a > b) {
        return a;
    }
    return b;
}