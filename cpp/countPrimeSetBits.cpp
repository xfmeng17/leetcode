#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		return func1(L, R);
		// return func2(L, R);
	}
	
    // func1: loop
    int func1(int L, int R) {
		int ans = 0;
		int x = L;
		while (x <= R)  {
			int cnt = 0;
            int y = x;
			while (y > 0) {
				cnt++;
				y &= (y - 1);
			}
			if (isPrime(cnt)) {
				ans++;
				// printf("%d\n", x);
			}
            x++;
		}
		// printf("ans=%d\n", ans);
		return ans;
    }

    // func2: bitwise operation
    int func2(int L, int R) {
    	int ans = 0;
    	int x = L;
    	while (x <= R) {
    		int y = x;
    		y = (y & 0x55555555) + ((y >> 1) & 0x55555555);
    		y = (y & 0x33333333) + ((y >> 2) & 0x33333333);
    		y = (y & 0x0F0F0F0F) + ((y >> 4) & 0x0F0F0F0F);
    		y = (y & 0x00FF00FF) + ((y >> 8) & 0x00FF00FF);
    		y = (y & 0x0000FFFF) + ((y >> 16) & 0x0000FFFF);
    		if (isPrime(y)) {
    			ans++;
    		}
            x++;
    	}
    	return ans;
    }

    // helper func
	bool isPrime(int n) {
		if (n < 2) {
			return false;
		}
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;

		// set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
		// return primes.count(n);
	}
};

// int main() {
// 	Solution s;
// 	s.countPrimeSetBits(244, 269);
// 	return 0;
// }
