#include<iostream>
#include<vector>
using namespace std;

int max_sub_sum(vector<int>& nums){
    if(nums.size() == 0) return 0;
    //���ö�̬�滮��˼��
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int maxAns = nums[0];
    for(int i = 1; i < nums.size(); i++){
        dp[i] = max(dp[i-1] + nums[i],nums[i]);
        maxAns = max(maxAns,dp[i]);
    }
    return maxAns;
}
 
int main()
{
    vector<int> nums;
    cout << "请输入：";
    char ch;
    int num;
    while((ch = getchar()) != '\n'){
        cin >> num;
        nums.emplace_back(num);
    }
    cout << max_sub_sum(nums);
    return 0;
}