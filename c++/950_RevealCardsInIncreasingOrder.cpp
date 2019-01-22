class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // return func1(deck);
        return func2(deck);

    }

    // ** referance queue
    vector<int> func1(vector<int>& deck) {
    	vector<int> res(deck.size());
    	sort(deck.begin(), deck.end());
    	queue<int> que;
    	for (int i = 0; i < deck.size(); i++) {
    		que.push(i);
    	}
    	for (int i = 0; i < deck.size(); i++) {
    		res[que.front()] = deck[i];
    		que.pop();
    		if (que.size() > 0) {
    			que.push(que.front());
    			que.pop();
    		}
    	}
    	return res;
    }

    // ** more readable
    vector<int> func2(vector<int>& deck) {
    	vector<int> res(deck.size());
    	queue<int> que;
    	for (int i = 0; i < deck.size(); i++) {
    		que.push(i);
    	}

    	int idx = 0;
    	while(que.size() > 0) {
    		res[que.front()] = idx;
    		idx++;
    		que.pop();
    		if (que.size() > 0) {
    			que.push(que.front());
    			que.pop();
    		}
    	}

    	sort(deck.begin(), deck.end());
    	for (int i = 0; i < res.size(); i++) {
    		res[i] = deck[res[i]];
    	}

    	return res;
    }
};
