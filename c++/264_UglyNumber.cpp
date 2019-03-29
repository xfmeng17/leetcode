class Solution {
public:
    int nthUglyNumber(int n) {
        return func1(n);
    }

    // ** hash set
    // ** TLE
    int func1(int n) {
        unordered_set<int> table;
        table.insert(1);
        int len = 1;
        int curr = 1;
        int last = 1;

        while (table.size() < n) {
            curr++;
            if (curr % 2 == 0 && table.count(curr/2) > 0) {
                table.insert(curr);
                last = curr;
            } else if (curr % 3 == 0 && table.count(curr/3) > 0) {
                table.insert(curr);
                last = curr;
            } else if (curr % 5 == 0 && table.count(curr/5) > 0) {
                table.insert(curr);
                last = curr;
            }
        }

        return last;
    }
};
