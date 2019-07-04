class Solution {
public:
    int countSegments(string s) {        
        return func1(s);
    }

    int func1(string s) {
        string word;
        istringstream iss(s);
        int res = 0;
        while (iss >> word) {
            res++;
        }
        return res;
    }
};
