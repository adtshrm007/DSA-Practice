#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        return i + 1;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1,1,2};

    int ans = s.removeDuplicates(nums);

    cout << ans;

    return 0;
}