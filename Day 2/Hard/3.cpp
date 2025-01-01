#include <bits/stdc++.h>
using namespace std;

int maxDartsOnDartboard(vector<vector<int>>& darts, int r) {
    int n = darts.size();
    auto distanceSquared = [](int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    int maxDarts = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int x1 = darts[i][0], y1 = darts[i][1];
            int x2 = darts[j][0], y2 = darts[j][1];
            
            double dist = sqrt(distanceSquared(x1, y1, x2, y2));
            if (dist > 2 * r) continue;
            
            double midX = (x1 + x2) / 2.0;
            double midY = (y1 + y2) / 2.0;
            
            double angle = atan2(y2 - y1, x2 - x1);
            double offsetX = sqrt(r * r - (dist / 2) * (dist / 2)) * (-sin(angle));
            double offsetY = sqrt(r * r - (dist / 2) * (dist / 2)) * (cos(angle));
            
            vector<pair<double, double>> centers = {
                {midX + offsetX, midY + offsetY},
                {midX - offsetX, midY - offsetY}
            };

            for (auto& center : centers) {
                int count = 0;
                for (auto& dart : darts) {
                    if (distanceSquared(center.first, center.second, dart[0], dart[1]) <= r * r) {
                        count++;
                    }
                }
                maxDarts = max(maxDarts, count);
            }
        }
    }

    return maxDarts;
}

int main() {
    vector<vector<int>> darts1 = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
    int r1 = 2;
    vector<vector<int>> darts2 = {{-3, 0}, {3, 0}, {2, 6}, {5, 4}, {0, 9}, {7, 8}};
    int r2 = 5;

    cout << maxDartsOnDartboard(darts1, r1) << endl; // Output: 4
    cout << maxDartsOnDartboard(darts2, r2) << endl; // Output: 5

    return 0;
}
