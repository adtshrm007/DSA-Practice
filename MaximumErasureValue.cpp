class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int total = 0;

        map<char,int> m;

        for(int right = 0; right < s.size(); right++) {

            m[s[right]]++;

            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {

                total += s.size() - right;

                m[s[left]]--;
                left++;
            }
        }

        return total;
    }
};