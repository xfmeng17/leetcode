class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    // return func1(cpdomains);
    return func2(cpdomains);
  }
  vector<string> func1(vector<string> &cpdomains) {
    vector<string> res;
    unordered_map<string, int> set;
    for (int i = 0; i < cpdomains.size(); i++) {
      vector<string> vec_record = split(cpdomains[i], ' ');
      int count = atoi(vec_record[0].c_str());
      vector<string> vec_domain = subdomain(vec_record[1], '.');
      for (int j = 0; j < vec_domain.size(); j++) {
        if (set.count(vec_domain[j]) <= 0) {
          set.insert({vec_domain[j], count});
        } else {
          set[vec_domain[j]] = set[vec_domain[j]] + count;
        }
      }
    }
    for (auto i = set.begin(); i != set.end(); i++) {
      string str = to_string(i->second) + " " + i->first;
      res.push_back(str);
    }
    return res;
  }

  vector<string> split(string str, char del) {
    vector<string> res;
    int pos = 0;
    int len = 0;
    while (pos < str.length()) {
      if (str[pos] == del) {
        res.push_back(str.substr(pos - len, len));
        len = 0;
      } else {
        len++;
      }
      pos++;
    }
    res.push_back(str.substr(pos - len));
    return res;
  }
  vector<string> subdomain(string domain, char del) {
    vector<string> res;
    int pos = 0;
    res.push_back(domain);
    while (pos < domain.length()) {
      if (domain[pos] == del) {
        domain = domain.substr(pos + 1);
        res.push_back(domain);
        pos = 0;
      } else {
        pos++;
      }
    }
    return res;
  }

  // ** ref
  vector<string> func2(vector<string> &cpdomains) {
    unordered_map<string, int> set;
    for (auto cd : cpdomains) {
      int i = cd.find(" ");
      int n = stoi(cd.substr(0, i));
      string s = cd.substr(i + 1);
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
          cout << s.substr(i + 1) << endl;
          set[s.substr(i + 1)] += n;
        }
      }
      set[s] += n;
    }
    vector<string> res;
    for (auto s : set) {
      res.push_back(to_string(s.second) + " " + s.first);
    }
    return res;
  }
};