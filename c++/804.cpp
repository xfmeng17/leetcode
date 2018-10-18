class Solution {
public:
    const string MORSE_MAP[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> str_set;
        for (string word : words) {
        	string morse_str;
        	for (char c : word) {
        		morse_str += MORSE_MAP[c - 'a'];
        	}
        	if (str_set.count(morse_str) < 1) {
        		str_set.insert(morse_str);
        	}
        }
        return str_set.size();
    }
};