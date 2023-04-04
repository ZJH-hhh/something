#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
    int n, MAX = 1,MAX1 = 1, temp;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int k = i;
        while(k != 1) {
            if(k % 2 ==0) temp = k / 2;
            else temp = k * 3 + 1;
            MAX1 = max(MAX1, temp);
            k = temp;
        }
        MAX = max(MAX1, MAX);
    }
    cout << MAX;
    return 0;
}