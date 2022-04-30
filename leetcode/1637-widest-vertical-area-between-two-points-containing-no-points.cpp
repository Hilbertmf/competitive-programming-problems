class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int dist = 0;
        for(int i = 0; i < points.size()-1; ++i) {
            dist = max(dist, points[i+1][0] - points[i][0]);
        }
        return dist;
    }
};