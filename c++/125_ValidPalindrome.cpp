class Solution {
public:
    bool isPalindrome(string s) {
        return func1(s);       
    }

    bool func1(string s) {
        int lo = 0;
        int hi = s.length() -1;

        while (lo < hi) {
            while (lo < s.length() && !isalnum(s[lo]))  {
                lo++;
            }
            while (hi >= 0 && !isalnum(s[hi])) {
                hi--;
            }
            if (lo >= s.length() || hi <= -1) {
                return true;
            }
            if (lo < hi && tolower(s[lo]) != tolower(s[hi])) {
                return false;
            }
            lo++;
            hi--;
        }

        return true;
    }
};