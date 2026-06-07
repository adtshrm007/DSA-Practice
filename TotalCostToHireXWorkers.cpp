class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0, j = n - 1;

        // Fill left heap
        for (; i < candidates && i <= j; i++) {
            left.push(costs[i]);
        }

        // Fill right heap
        for (; j >= n - candidates && j >= i; j--) {
            right.push(costs[j]);
        }

        long long ans = 0;

        while (k--) {
            int leftCost = left.empty() ? INT_MAX : left.top();
            int rightCost = right.empty() ? INT_MAX : right.top();

            if (leftCost <= rightCost) {
                ans += leftCost;
                left.pop();

                if (i <= j) {
                    left.push(costs[i++]);
                }
            } else {
                ans += rightCost;
                right.pop();

                if (i <= j) {
                    right.push(costs[j--]);
                }
            }
        }

        return ans;
    }
};