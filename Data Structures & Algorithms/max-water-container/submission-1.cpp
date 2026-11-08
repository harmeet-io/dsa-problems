class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1;
        int i = 0;
        int j = heights.size()-1;

        while(i<j){
            int h = min(heights[i], heights[j]);
            ans = max(ans, h*(j-i));

            while(i<j && heights[i]<=h) i++;
            while(i<j && heights[j]<=h) j--;
        }

        return ans;
    }
};
