#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int  De_duplication(vector<int> &nums) {
    return unique(nums.begin(), nums.end()) - nums.begin();
}

void display(vector<int> &nums,int n) {
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, num;
    vector<int> nums;
    do {
        cin >> n;
        if(n == -1)  break;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        int k = De_duplication(nums);
        display(nums, k);
    } while(1);
    return 0;
}