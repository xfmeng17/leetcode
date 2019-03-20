class Solution {
public:
    int getMoneyAmount(int n) {
        return func1(n);
    }

    // ** WA after n  = 20
    // ** mine output=51, expected=49, weird
    int func1(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n <= 11) return 4 + (n - 4) * 2;
        
        return (n - 3) + getMoneyAmount(n-4);
    }
};
