class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
  		unordered_map<string, int> map;	
  		int p = A.find(' ');
  		while (p != -1) {
  			map[A.substr(0, p)]++;
  			A = A.substr(p + 1);
  			p = A.find(' ');
  			// cout << "A = " << A << endl;
  		}
  		map[A]++;

  		p = B.find(' ');
  		while (p != -1) {
  			map[B.substr(0, p)]++;
  			B = B.substr(p + 1);
  			p = B.find(' ');
  			// cout << "B = " << B << endl;
  		}
  		map[B]++;

  		vector<string> res;
  		for (auto it = map.begin(); it != map.end(); it++) {
  			if (it->second == 1) {
  				res.push_back(it->first);
  			}
  		}
  		return res;
    }
};