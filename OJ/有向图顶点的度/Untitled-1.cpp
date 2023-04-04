#include <iostream>

using namespace std;

const int N = 100010;

char op[N];
int nums[N];

int Otop = -1, Dtop = -1;

int getpriority(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
}

void calculate(){
    int a = nums[Dtop --];
    int b = nums[Dtop --];
    char ch = op[Otop --];
    
    int num;
    if(ch == '+') num = b + a;
    if(ch == '-') num = b - a;
    if(ch == '*') num = b * a;
    if(ch == '/') num = b / a;
    
    nums[++ Dtop] = num;
} 

int main()
{
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i ++ ){
        if(isdigit(s[i])){
            
            int j = i, x = 0;
            while( j < s.size() && isdigit(s[j])){
                x = x *  10 + s[j ++] - '0';
            }
            nums[++ Dtop] = x;
            i = j - 1;
        }
        else if(s[i] == '(') op[++ Otop] = s[i];
        else if(s[i] == ')') {
            
            while (Otop >= 0 && op[Otop] != '(') calculate();
            Otop --;
        }
        else {
            
            while (Otop >= 0 && getpriority(op[Otop]) >= getpriority(s[i])) calculate();
            op[++ Otop] = s[i];
        }
    }
    
    while (Otop >= 0) calculate();
    
    printf("%d", nums[Dtop]);
    
    return 0;
}