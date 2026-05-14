class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a=0;
        int left=0,right=0;
        int ans=INT_MIN;
        while(right<nums.size()){
            if(nums[right]==0){
                a++;
            }
            while(a>1){
                if(nums[left]==0){
                    a--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans-1;
    }
};