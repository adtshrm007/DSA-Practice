class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        multiset<pair<int, int>, greater<pair<int, int>>> mt;
        for (int i = 0; i < profits.size(); i++) {
            mt.insert({profits[i], capital[i]});
        }

        int a = 1;
        int ans = w;
        while (a <= k) {
    bool found = false;

    for (auto it = mt.begin(); it != mt.end(); ++it) {
        if (it->second <= ans) {
            ans += it->first;
            mt.erase(it);
            found = true;
            break;
        }
    }

    if (!found)
        break;

    a++;
}
        return ans;
    }
};