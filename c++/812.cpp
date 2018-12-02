class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
    	return func1(points);   
    }
    // ** straight forward with QingJiuZhao's formula
    double func1(vector<vector<int>>& points) {
    	vector<int> edge;
    	for (int i = 0; i < points.size(); i++) {
    		for (int j = i + 1; j < points.size(); j++) {
    			int x = points[i][0] - points[j][0];
    			int y = points[i][1] - points[j][1];
    			edge.push_back(x * x + y * y);
    		}
    	}
    	sort(edge.begin(), edge.end(), myCompare);
    	int a = edge[0];
    	int b = edge[1];
    	int c = edge[2];
    	cout << "a = " << a << endl;
    	cout << "b = " << b << endl;
    	cout << "c = " << c << endl;
    	return sqrt((a * c - pow((a + c - b) / 2, 2)) / 4.0);
	}
	static bool myCompare(int i, int j) {
    	return i > j;
    }
};