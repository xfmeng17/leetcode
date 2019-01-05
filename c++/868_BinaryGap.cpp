class Solution {
public:
    int binaryGap(int N) {
    	int res = 0;
  		int lastPos = -1;
  		int currPos = 0;
  		while (N > 0) {
  			int remainder = N % 2;
  			if (remainder == 1) {
  				if (lastPos != -1) {
  					int gap = currPos - lastPos;
  					res = res < gap ? gap : res;
  				}
  				lastPos = currPos;
  			}
  			currPos++;
  			N /= 2;
  		}
  		return res;     
    }
};