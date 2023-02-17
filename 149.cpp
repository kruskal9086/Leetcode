struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int result = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int samePoints = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samePoints++;
                    continue;
                }
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                int gcd = __gcd(dx, dy);
                string slope = to_string(dx / gcd) + ":" + to_string(dy / gcd);
                slopeCount[slope]++;
            }
            result = max(result, samePoints);
            for (auto& [slope, count] : slopeCount) {
                result = max(result, count + samePoints);
            }
        }
        return result;
    }
};
