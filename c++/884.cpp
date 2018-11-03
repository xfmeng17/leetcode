class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
  		unordered_map<string, int> map;
  		string &a = A;
		string &b = B;	
  		int p = a.find(' ');
  		while (p != -1) {
  			map[a.substr(0, p)]++;
  			a = a.substr(p);
  			p = a.find(' ');
  			cout << "a = " << a << endl;
  		}
  		map[a]++;

  		p = b.find(' ');
  		while (p != -1) {
  			map[b.substr(0, p)]++;
  			b = b.substr(p);
  			p = b.find(' ');
  			cout << "b = " << b << endl;
  		}
  		map[b]++;

  		vector<string> res;
  		for (auto it = map.begin(); it != map.end(); it++) {
  			if (it->second == 1) {
  				res.push_back(it->first);
  			}
  		}
  		return res;
    }
};