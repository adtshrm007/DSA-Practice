class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int n:nums){
            pq.push(n);
        }
        int a=1;
        while(a<=k&&!pq.empty()){
            ans=ans+pq.top();
            int a1=pq.top();
            pq.pop();
            pq.push((a1+3-1)/3);
            a++;
        }
        return ans;
    }
};