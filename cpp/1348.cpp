class TweetCounts {
private:
  unordered_map<string, vector<int>> record;

public:
  TweetCounts() {}

  void recordTweet(string tweetName, int time) {
    record[tweetName].emplace_back(time);
    sort(record[tweetName].begin(), record[tweetName].end());
    return;
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    vector<int> ret;
    if (record.find(tweetName) == record.end()) {
      return ret;
    }

    vector<int> &times = record[tweetName];
    int delta = 0;
    if (freq == "minute") {
      delta = 60;
    } else if (freq == "hour") {
      delta = 60 * 60;
    } else if (freq == "day") {
      delta = 60 * 60 * 24;
    }

    int i = 0;
    while (startTime + delta * i <= endTime) {
      int cur_s = startTime + delta * i;
      int cur_e = startTime + delta * (i + 1) - 1;
      cur_e = min(cur_e, endTime);
      i++;
      int idx_s = bs(times, cur_s);
      int idx_e = bs(times, cur_e);
      ret.emplace_back(idx_e - idx_s + 1);
    }
    return ret;
  }

  int bs(vector<int> &times, int target) {
    int lo = 0;
    int hi = times.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (times[mid] == target) {
        return mid;
      } else if (times[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return hi;
  }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */