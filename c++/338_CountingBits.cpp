class Solution {
public:
    vector<int> countBits(int num) {
        return func1(num);
    }

    // ** easy one, O(n * sizeof(integer))
    vector<int> func1(int num) {
    	vector<int> res;

        for (int i = 0; i <= num; i++) {
        	unsigned cur = i;
        	int cnt = 0;
        	while (cur > 0) {
        		cnt += cur & 1;
        		cur = cur >> 1;
        	}
        	res.push_back(cnt);
        }

        return res;
    }
};