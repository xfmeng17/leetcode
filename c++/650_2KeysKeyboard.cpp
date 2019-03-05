class Solution {
public:
    int minSteps(int n) {
        return func1(n);
    }
    int func1(int n) {
        if (n <= 0) {
            return 0;
        }
        return 1 + helper1(n, 1, 1);
    }
    int helper1(int target, int notepad, int paste) {
        if (target == notepad) {
            return 0;
        }
        if (target < notepad) {
            return target;
        }

        int p = 1 + helper1(target, notepad + paste, paste);
        int c = p;
        if (notepad != paste) {
            c = 1 + helper1(target, notepad, notepad);
        }

        return min(p, c);
    }
};
