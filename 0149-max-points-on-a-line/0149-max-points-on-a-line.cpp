class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int same = 0, vertical = 0, localMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;
                } else if (dx == 0) {
                    vertical++;
                } else {
                    int g = __gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    string key = to_string(dy) + "/" + to_string(dx);
                    slopeCount[key]++;
                    localMax = max(localMax, slopeCount[key]);
                }
                localMax = max(localMax, vertical);
            }

            ans = max(ans, localMax + same + 1);
        }

        return ans;
    }
};
