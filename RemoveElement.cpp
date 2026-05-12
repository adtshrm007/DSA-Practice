#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2};
    int val = 3;

    int ans = s.removeElement(nums, val);

    cout << ans;

    return 0;
}