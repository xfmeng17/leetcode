public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        ret[0] = -1;
        ret[1] = -1;
        
        HashMap<Integer, Integer> set = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            set.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            if (set.containsKey(target-nums[i])) {
                if (set.get(target-nums[i]) != i) {
                    ret[0] = i;
                    ret[1] = set.get(target-nums[i]);
                    return ret;
                }
            }
        }
        
        return ret;
    }
}


/*
ABSDCASDF
*/

