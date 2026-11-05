class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
       set<vector<int>> st;

       sort(nums.begin(), nums.end());
       
       for(int k=0; k<n-2; k++){
            int i=k+1;
            int j=n-1;

            while(i<j){
                int target = nums[i] + nums[j] + nums[k];
                if(target == 0){
                    vector<int> t({nums[i], nums[j], nums[k]});
                    sort(t.begin(), t.end());
                    st.insert(t);
                    i++; j--;

                    while(j>0 && nums[j]==nums[j+1]) j--;
                    while(i<n && nums[i]==nums[i-1]) i++;
                    
                }else if(target > 0){
                    j--;
                }else{
                    i++;
                }

            }
       } 

       vector<vector<int>> ans(st.begin(), st.end());
       return ans;
    }
};
