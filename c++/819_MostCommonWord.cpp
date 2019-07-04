class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // return func1(paragraph, banned);
        return func2(paragraph, banned);
    }

    string func1(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (string b : banned) {
            bannedSet.insert(b);
        }
        for (int i = 0; i < paragraph.length(); i++) {
            paragraph[i] = tolower(paragraph[i]);
        }
        vector<string> paraVec = split(paragraph, "!?',;. ");
        unordered_map<string, int> paraMap;
        int max = 0;
        string res = "";
        for (string p : paraVec) {
            if (bannedSet.find(p) == bannedSet.end()) {
                paraMap[p]++;
                if (paraMap[p] > max) {
                    max = paraMap[p];
                    res = p;
                }
            }
        }
        return res;
    }

    /**
     * Reference solution:
     * 1. remove all punctuations
     * 2. change to lower case
     * 3. words count for each word not in banned set
     * 4. return the most common word
     * Very efficient to use istringstream
     */
    string func2(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        istringstream iss(paragraph);
        string word;
        pair<string, int> res("", 0);
        while (iss >> word) {
            if (ban.find(word) == ban.end() && ++count[word] > res.second) {
                res = make_pair(word, count[word]);
            }
        }
        return res.first;
    }

    /* helper funcitons */
    vector<string> split(string text, string delim) {
        unordered_set<char> delimSet;
        for (char d : delim) {
            delimSet.insert(d);
        }
        vector<string> res;
        int i = 0, j = 0;
        while (i < text.length()) {
            while (j < text.length() && delimSet.find(text[j]) == delimSet.end()) {
                j++;
            }
            if (j > i) {
                res.push_back(text.substr(i, j-i));
            }
            i = j+1;
            j = i;
        }
        return res;
    }
};
