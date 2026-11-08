class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum=0, item=prices[0];

        for(int i=1; i<n; i++){
            sum = max(sum, prices[i]-item);
            item = min(item, prices[i]);
        }

        return sum;
    }
};
