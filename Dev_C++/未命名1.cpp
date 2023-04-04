#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int a[N], tree[N << 2], tag[N << 2];

void pushUp(LL rt){
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushDown(LL rt, LL ln, LL rn){
	if (tag[rt]){
		tag[rt << 1] += tag[rt];
		tag[rt << 1 | 1] += tag[rt];
		
		tree[rt << 1] += tag[rt] * ln;
		tree[rt << 1 | 1] += tag[rt] * rn;
		
		tag[rt] = 0;
	}
}

void update(LL l, LL r, LL s, LL t, LL rt, LL c){
	if (l <= s && t <= r){
		tree[rt] += (t - s + 1) * c;
		tag[rt] += c;
		return ;
	}
	
	LL mid = s + t >> 1;
	pushDown(rt, mid - s + 1, t - mid);
	
	if (l <= mid) update(l, r, s, mid, rt << 1, c);
	if (r > mid)  update(l, r, mid + 1, t, rt << 1 | 1, c);
	
	pushUp(rt);
}

LL query(LL l, LL r, LL s, LL t, LL rt){
	if (l <= s && t <= r) return tree[rt];
	
	LL res = 0;
	LL mid = s + t >> 1;
	pushDown(rt, mid - s + 1, t - mid);
	
	if (l <= mid) res += query(l, r, s, mid, rt << 1);
	if (r > mid)  res += query(l, r, mid + 1, t, rt << 1 | 1);
	
	return res;
}

void build(LL s, LL t, LL rt){
	if (s == t){
		tree[rt] = a[s];
		return ;
	}
	
	LL mid = s + t >> 1;
	build(s, mid, rt << 1), build(mid + 1, t, rt << 1 | 1);
	
	pushUp(rt);
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	build(1, n, 1);
	
	while (m -- ){
		int op;
		LL a, b, c;
		scanf("%d", &op);
		
		if (op == 1){
			scanf("%lld%lld%lld", &a, &b, &c);
			update(a, b, 1, n, 1, c);
		}
		else {
			scanf("%lld%lld", &a, &b);
			printf("%lld\n", query(a, b, 1, n, 1));
		}
	}
	
	return 0;
}
