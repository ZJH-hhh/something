#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 25;

int n, m;
int a[N], b[N], c[N];

int main() {
	std::cin >> n >> m;
	c[0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
		c[i] = c[i - 1] * a[i];
	}
	
	for (int i = 1, sum = 0; i <= n; i ++ ) {
		b[i] = (m % c[i] - sum) / c[i - 1];
		sum = m % c[i - 1];
		printf("%d ", b[i]);
	}
	return 0;
}
