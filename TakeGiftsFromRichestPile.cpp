class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(int g:gifts){
            pq.push(g);
        }  
        int a=1;
        while(a<=k){
            int x=floor(sqrt(pq.top()));
            pq.pop();
            pq.push(x);
            a++;
        }
        while(!pq.empty()){
            ans=ans+pq.top();
            pq.pop();
        } 
        return ans;
    }
};