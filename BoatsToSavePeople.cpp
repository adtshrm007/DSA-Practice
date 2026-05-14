class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;

        int boats = 0;

        while(left <= right) {

            // pair lightest + heaviest if possible
            if(people[left] + people[right] <= limit) {
                left++;
            }

            // heaviest always goes
            right--;

            boats++;
        }

        return boats;
    }
};