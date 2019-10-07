class Solution {
public:
    string toGoatLatin(string S) {
  		vector<string> words;
  		int pos = S.find(' ');
  		while (pos > 0) {
  			words.push_back(S.substr(0, pos));
  			S = S.substr(pos + 1);
  			pos = S.find(' ');
  		}
  		if (S.length() > 0) {
  			words.push_back(S);
  		}

  		string a = "a";
  		string res = "";
  		unordered_set<char> vowel ({'a', 'e', 'i', 'o', 'u'});
  		for (string word : words) {
  			if (vowel.count(tolower(word[0]))) {
  				res += word + "ma" + a + ' ';
  			} else {
  				res += word.substr(1) + word[0] + "ma" + a + ' ';
  			}
  			a += "a";
  		}

  		return res.substr(0, res.length() - 1); 
    }
};