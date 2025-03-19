#include <vector>
using namespace std;
class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            vector<bool> result;
            int n = candies.size();
            int max = candies[0];
            for(int i=1;i < n;i++){
                if(candies[i]>max)
                    max = candies[i];
            }
            for(int i = 0; i < n; i++){
                result.push_back((candies[i] + extraCandies ) >= max);
            }
            return result;
        }
    };