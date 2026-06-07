class Solution {
    multiset<int> low, high;

    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
    }

    void addNum(int num) {
        if (low.empty() || num <= *prev(low.end()))
            low.insert(num);
        else
            high.insert(num);

        balance();
    }

    void removeNum(int num) {
        auto it = low.find(num);

        if (it != low.end())
            low.erase(it);
        else
            high.erase(high.find(num));

        balance();
    }

    double getMedian(int k) {
        if (k & 1)
            return (double)*prev(low.end());

        return ((double)*prev(low.end()) +
                (double)*high.begin()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            addNum(nums[i]);

            if (i >= k)
                removeNum(nums[i - k]);

            if (i >= k - 1)
                ans.push_back(getMedian(k));
        }

        return ans;
    }
};