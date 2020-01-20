class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_map<string, int> set;
    for (string email : emails) {
      int at = email.find('@');
      string old_local = email.substr(0, at);
      string new_local;
      for (int i = 0; i < old_local.length(); i++) {
        if (old_local[i] == '+') {
          break;
        } else if (old_local[i] == '.') {
        } else {
          new_local.push_back(old_local[i]);
        }
      }
      set[new_local + email.substr(at)] += 1;
    }
    return set.size();
  }
};