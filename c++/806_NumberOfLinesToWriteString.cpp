class Solution {
private:
	int MAX_LINE_WIDTH = 100;
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res(2, 0);
        int curr_line_size = 0;
        for (char c : S) {
        	if (curr_line_size + widths[c - 'a'] < MAX_LINE_WIDTH) {
        		curr_line_size += widths[c - 'a'];
        	} else if (curr_line_size + widths[c - 'a'] == MAX_LINE_WIDTH) {
        		res[0]++;
        		curr_line_size = 0;
        	} else {
        		res[0]++;
        		curr_line_size = widths[c - 'a'];
        	}
        }
        if (curr_line_size > 0) { res[0]++; }
        res[1] = curr_line_size;
        return res;
    }
};