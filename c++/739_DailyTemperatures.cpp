class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		// return func1(T);
		return func2(T);   
    }

    // ** time O(N^2), Time Limit Exceeded
    vector<int> func1(vector<int>& T) {
		vector<int> res = vector<int>(T.size(), 0);
		for (int i = 0; i < T.size(); i++) {
			for (int j = i+1; j < T.size(); j++) {
				if (T[j] > T[i]) {
					res[i] = j - i;
					break;
				}
			}
		}
		return res;
    }

    /* Use hint:
     * If the temperature is say 70 today, then in the future
     * a warmer temperature must be either 71, 72, 73 ... 100.
     * We could remember when all of them occur next.
     * 
     * Result: time faster than 10.15%, memory less than 5.02%. 
	*/
	vector<int> func2(vector<int>& T) {
		vector<int> res = vector<int>(T.size(), 0);
		int MAX_TEMPERATURE = 101;
		vector<queue<int>> vec = vector<queue<int>>(MAX_TEMPERATURE);
		for (int i = 0; i < T.size(); i++) {
			vec[T[i]].push(i);
		}
		for (int i = 0; i < T.size(); i++) {
			for (int j = T[i]+1; j < MAX_TEMPERATURE; j++) {
				if (!vec[j].empty() && vec[j].front() > i) {
					if (res[i] == 0) {
						res[i] = vec[j].front() - i;
					} else {
						res[i] = min(res[i], vec[j].front() - i);
					}
				}
			}
			vec[T[i]].pop();
		}
		return res;
	}
};
