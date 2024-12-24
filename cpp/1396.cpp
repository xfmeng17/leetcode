class UndergroundSystem {
public:
  unordered_map<int, pair<string, int>> check_map;
  unordered_map<string, vector<int>> station_record;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    check_map[id] = make_pair(stationName, t);
    return;
  }

  void checkOut(int id, string stationName, int t) {
    pair<string, int> &p = check_map[id];
    string &st_station = p.first;
    int st_time = p.second;
    int costtime = t - st_time;
    station_record[st_station + "_" + stationName].emplace_back(costtime);
    check_map.erase(id);
    return;
  }

  double getAverageTime(string startStation, string endStation) {
    double ave = 0.0;
    double all = 0.0;
    vector<int> &time_vec = station_record[startStation + "_" + endStation];
    if (time_vec.size() <= 0) {
      return 0.0;
    }

    for (auto t : time_vec) {
      all += t + 0.0;
    }
    return all / (double)(time_vec.size());
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */