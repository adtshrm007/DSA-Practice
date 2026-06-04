class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int pos = 0;

        while (nums[pos] != k)
            pos++;

        unordered_map<int, int> mp;

        mp[0] = 1;

        int balance = 0;

        // Right side including k
        for (int i = pos + 1; i < n; i++) {

            if (nums[i] > k)
                balance++;
            else
                balance--;

            mp[balance]++;
        }

        long long ans = 0;

        balance = 0;

        // Left side including k
        for (int i = pos; i >= 0; i--) {

            if (nums[i] > k)
                balance++;
            else if (nums[i] < k)
                balance--;

            ans += mp[-balance];
            ans += mp[1 - balance];
        }

        return ans;
    }
};