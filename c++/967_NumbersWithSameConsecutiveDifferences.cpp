class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        return func1(N, K);
    }

    // ** iterative
    vector<int> func1(int N, int K) {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        for (int i = 2; i <= N; i++) {
            vector<int> aux;
            for (int x : res) {
                int y = x % 10;
                if (x > 0 && y + K < 10) {
                    aux.push_back(x * 10 + y + K);
                }
                // ** check K > 0 in case re-push same value (x * 10 + y + 0)
                if (x > 0 && y - K >= 0 && K > 0 ) {
                    aux.push_back(x * 10 + y - K);
                }
            }
            res = aux;
        }

        return res;
    }
};
