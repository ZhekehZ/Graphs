#include <bits/stdc++.h>
using namespace std;

const int N = 5e4;
const int K = 100;

pair<int, int> points[N];

struct Edge{
    int a, b, w;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
} edges[N * K * 2];
int ecount = 0;
int ecount_= 0;

inline int sqr(int x) { return x * x; }
inline int len(const Edge & e) { return e.w; }
inline int len(const pair<int, int> & a, const pair<int, int> & b) {
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int pointsList[N];
int comp[N];

int dsu_get_comp(int v) {
    return (v == comp[v]) ? v : comp[v] = dsu_get_comp(comp[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        pointsList[i] = comp[i] = i;
    }

    bool (*comparators[])(int, int) = {
        [](int a, int b) { return points[a].first < points[b].first; },
        [](int a, int b) { return points[a].second < points[b].second; }
    };

    int it = 2;
    while(it-->0){
        sort(pointsList, pointsList + n, comparators[it]);
        for(int i = 0; i < n; ++i) {
            int p1 = pointsList[i];
            for(int j = i + 1; j < n && j < K + i + 1; ++j) {
                int p2 = pointsList[j];
                edges[ecount++] = {p1, p2, len(points[p1], points[p2])};
            }
        }
    }

    sort(edges, edges + ecount);

    int a, b;
    double sum = 0;
    for(int i = 0; i < ecount; ++i){
        if((a = dsu_get_comp(edges[i].a)) != (b = dsu_get_comp(edges[i].b))){
            if(rand() & 1){
                swap(a, b);
            }
            comp[a] = b;
            edges[ecount_++] = edges[i];
            sum += sqrt(edges[i].w);
        }
    }

    cout.precision(19);
    cout << sum << '\n';
    for(int i = 0; i < ecount_; ++i){
        cout << edges[i].a + 1 << ' ' << edges[i].b + 1 << '\n';
    }

    return 0;
}