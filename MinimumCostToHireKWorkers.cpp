class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality,
                                vector<int>& wage,
                                int k) {

        vector<pair<double, int>> workers;

        for (int i = 0; i < quality.size(); i++) {
            workers.push_back({
                (double)wage[i] / quality[i],
                quality[i]
            });
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq; // max heap
        long long sumQuality = 0;
        double ans = 1e18;

        for (auto &[ratio, q] : workers) {
            sumQuality += q;
            pq.push(q);

            if (pq.size() > k) {
                sumQuality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, ratio * sumQuality);
            }
        }

        return ans;
    }
};