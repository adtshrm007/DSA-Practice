class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0,right=0;
        int sum=0;
        while(right<nums.size()){
            sum=sum+nums[right];

            while(sum>=target){
                ans=min(right-left+1,ans);
                sum=sum-nums[left];
                left++;
            }

            right++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};