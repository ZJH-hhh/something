#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

typedef long long ll;

const int N = 300010;

int n;
int p[N], a[N];
int h[N], e[N], ne[N], idx;
int cnt[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int root) {
	if (ne[root] == -1) return 0;
	int res = 1;
	for (int i = h[root]; ~i; i = ne[i]) res += dfs(e[i]);
	return cnt[root] = res;
}

int bfs(int root) {
	if (cnt[root] == 1) return 0;
	std::queue<int> q;
	q.push(root); 
	std::vector<int> v;
	v.push_back(root);
	while (q.size()) {
		for (int k = q.size(); k; k -- ) {
			int t = q.front();
			q.pop();
			for (int i = h[t]; ~i; i = ne[i]) {
				q.push(e[i]);
				v.push_back(e[i]);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < v.size(); i ++ ) {
		int t = 1e9;
		for (int j = 0; j < v.size(); j ++ )
			if (i != j) t = std::min(t, (a[v[i]] - a[v[j]]) * (a[v[i]] - a[v[j]]));
		res += t;
	}
		
	return res;
}

int main() {
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	
	p[1] = 1;
	for (int i = 2; i <= n; i ++ ) {
		scanf("%d", &p[i]);
		add(p[i], i);
	}
	
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	dfs(1);
	for (int i = 1; i <= n; i ++ ) {
		std::cout << bfs(i) << '\n';
	}
	
	return 0;
} 
