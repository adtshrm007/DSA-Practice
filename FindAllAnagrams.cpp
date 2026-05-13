class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size()) return ans;

        map<char,int> pCount, window;

        // Frequency of p
        for(char ch : p) {
            pCount[ch]++;
        }

        int k = p.size();

        // First window
        for(int i = 0; i < k; i++) {
            window[s[i]]++;
        }

        if(window == pCount) {
            ans.push_back(0);
        }

        // Sliding window
        for(int i = k; i < s.size(); i++) {

            // Add new character
            window[s[i]]++;

            // Remove old character
            window[s[i-k]]--;

            // Remove zero frequency entries
            if(window[s[i-k]] == 0) {
                window.erase(s[i-k]);
            }

            if(window == pCount) {
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};



//2nd Approach
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size()) return ans;

        vector<int> pFreq(26, 0);
        vector<int> window(26, 0);

        for(char ch : p) {
            pFreq[ch - 'a']++;
        }

        int k = p.size();

        for(int i = 0; i < k; i++) {
            window[s[i] - 'a']++;
        }

        if(window == pFreq) {
            ans.push_back(0);
        }

        for(int i = k; i < s.size(); i++) {

            window[s[i] - 'a']++;

            window[s[i-k] - 'a']--;

            if(window == pFreq) {
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};