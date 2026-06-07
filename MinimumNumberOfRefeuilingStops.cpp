class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        if (target - startFuel <= 0) {
            return 0;
        }
        int ans = 0;
        int lastPosition = -1;
        int i = 0;
        long long reach = startFuel;
        priority_queue<int> pq;
        while (reach < target) {

            while (i < stations.size() && stations[i][0] <= reach) {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty())
                return -1;

            reach += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};