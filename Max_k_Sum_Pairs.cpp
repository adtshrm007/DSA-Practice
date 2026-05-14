class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int count = 0;

        for (int num : nums) {

            int diff = k - num;

            if (mp[diff] > 0) {
                count++;
                mp[diff]--;
            }
            else {
                mp[num]++;
            }
        }

        return count;
    }
};