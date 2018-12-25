class Solution {
public:
    int compress(vector<char>& chars) {
    	// return func1(chars);
    	return func2(chars);   
    }

    // ** a a a b b a a
    // ** should return a 3 b 2 a 2
    // ** not a 5 b 2
    int func1(vector<char>& chars) {
    	int alpha[256] = {0};
    	for (int i = 0; i < chars.size(); i++) {
    		alpha[chars[i]]++;
    	}

    	int size = 0;
    	stack<int> stk;
    	for (int i = 0; i < 256; i++) {
    		if (alpha[i] == 1) {
    			chars[size++] = i;
    		}
    		if (alpha[i] > 1) {
    			chars[size++] = i;
    			while (alpha[i] > 0) {
	    			stk.push(alpha[i] % 10);
	    			alpha[i] /= 10;
	    		}
	    		while (!stk.empty()) {
	    			chars[size++] = '0' + stk.top();
	    			stk.pop();
	    		}
    		}
    	}
    	chars.resize(size);

    	return size;
    }

    int func2(vector<char>& chars) {
    	int head = 0, curr = 0, write = 0;
    	while (curr < chars.size()) {
    		if (chars[curr] != chars[head] && curr - head > 1) {
				chars[write++] = chars[head];
				stack<int> stk;
				int sum = curr - head;
				while (sum > 0) {
					stk.push(sum % 10);
					sum /= 10;
				}
				while (!stk.empty()) {
					chars[write++] = '0' + stk.top();
					stk.pop();
				}
				head = curr;
			}
			curr++;
    	}

    	if (curr - head >= 1) {
    		chars[write++] = chars[head];
			stack<int> stk;
			int sum = curr - head;
			while (sum > 0) {
				stk.push(sum % 10);
				sum /= 10;
			}
			while (!stk.empty()) {
				chars[write++] = '0' + stk.top();
				stk.pop();
			}
		}
		chars.resize(write);
		return write;
    }
};
