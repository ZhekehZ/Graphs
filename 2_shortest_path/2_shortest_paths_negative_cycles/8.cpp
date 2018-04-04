
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<ll, int> pii;

int main() {
	ll h;
	int a, b, c;
	cin >> h >> a >> b >> c;
	vector<ll> d(c, h + 1);
	set<pii> heap;
	d[0] = 0;
	heap.insert(pii(d[0], 0));
	while (!heap.empty()) {
		int j, i = heap.begin()->second;
		heap.erase(heap.begin());
		forn(t, 2) {
			ll x = d[i] + a;
			if (d[j = x % c] > x) {
				heap.erase(pii(d[j], j));
				d[j] = x;
				heap.insert(pii(d[j], j));
			}
			swap(a, b);
		}
	}
	ll ans = 0;
	forn(i, c)
		if (d[i] < h)
			ans += (h - d[i] + c - 1) / c;
	cout << ans << endl;
}
