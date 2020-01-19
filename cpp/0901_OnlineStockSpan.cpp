/*
 * TLE with no doubt
 */
class StockSpanner1 {
private:
  vector<int> dailyprice;

public:
  StockSpanner1() { dailyprice.clear(); }

  int next(int price) {
    dailyprice.push_back(price);
    int res = 0;
    for (int i = dailyprice.size() - 1; i >= 0; i--) {
      if (price >= dailyprice[i]) {
        res++;
      } else {
        break;
      }
    }
    return res;
  }
};

/*
 * AC, really fast
 */
class StockSpanner2 {
private:
  vector<int> dailyprice;
  vector<int> stockspan;

public:
  StockSpanner2() {
    dailyprice.clear();
    stockspan.clear();
  }

  int next(int price) {
    int res = 1;
    int pos = dailyprice.size() - 1;
    while (pos >= 0 && price >= dailyprice[pos]) {
      res += stockspan[pos];
      pos -= stockspan[pos];
    }
    dailyprice.push_back(price);
    stockspan.push_back(res);
    return res;
  }
};

class StockSpanner {
private:
  StockSpanner1 *ss1;
  StockSpanner2 *ss2;

public:
  StockSpanner() {
    ss1 = new StockSpanner1();
    ss2 = new StockSpanner2();
  }

  int next(int price) {
    // return ss1->next(price);
    return ss2->next(price);
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
