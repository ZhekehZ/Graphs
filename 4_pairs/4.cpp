#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g;

bool check(int mask){
	for (auto e : g) {
		if ((e.first & mask) && (e.second & mask)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	n = (1 << n);

	int a, b;
	while (m--) {
		cin >> a >> b;
		g.push_back({(1 << (b - 1)), (1 << (a - 1))});
	}

	bool is[n];
	for (int mask = 0; mask < n; ++mask) {
		is[mask] = check(mask);
	}

	vector<int> dp;
	dp.assign(n, n);
	dp[0] = 0;

	for (int mask = 0; mask < n; ++mask) {
		for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
			if(is[sub]) {
				dp[mask] = min(dp[mask], 1 + dp[sub ^ mask]);
			}
		}
	}

	cout << dp.back() << '\n';
	return 0;
}