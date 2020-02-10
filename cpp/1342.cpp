class Solution {
public:
    int numberOfSteps (int num) {
        int ret = 0;
        while (num > 0) {
            ret++;
            if (num & 1) {
                num -= 1;
            } else {
                num /= 2;
            }
        }
        return ret;
    }
};