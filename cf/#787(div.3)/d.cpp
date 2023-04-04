#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5, INF = 0x3f3f3f3f;

int n;
int h[N], e[N], ne[N], idx;
vector<int> path[N];
bool st[N];
int cnt;

void insert(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u){
    path[cnt].push_back(u);
    st[u] = true;
    if (h[u] == -1){
        cnt ++ ;
        return;
    }
    

    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (st[j]) continue;
        dfs(j);
    }
}

void solve(){
    idx = cnt = 0;
    memset(st, false, sizeof st);
    memset(h, -1, sizeof h);

    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        if (x == i) root = x;
        else insert(x, i);
    }

    dfs(root);
    cout << cnt << endl;

    for (int i = 0; i < cnt; i ++ ){
        cout << path[i].size() << '\n';
        for (auto t : path[i]) cout << t << ' ';
        cout << '\n';
        path[i].clear();
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t -- ) solve();

    return 0;
}