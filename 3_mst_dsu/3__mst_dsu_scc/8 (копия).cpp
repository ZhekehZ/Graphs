    #include <bits/stdc++.h>
    using namespace std;

    const int N = 5e4;
    const int Z = 300;
    const int W = 1000;

    typedef pair<int, int> Point;
    typedef Point Edge;

    /*****************input*points*****************/
    int n;
    Point points[N];
    int pnum[N];

    inline int len(const Point &a, const Point &b){
        return (a.first - b.first) * (a.first - b.first) +
                    (a.second - b.second) * (a.second - b.second);
    }

    inline int len(const Edge &edge){
        return len(points[edge.first], points[edge.second]);
    }

    /**********************dsu*********************/
    int component[N];
    int get(int v){
        return (v == component[v]) ? v : component[v] = get(component[v]);
    }

    /********************edges*********************/
    int ecount = 0;
    Edge edges[N * Z];
    int okecount = 0;

    /*******************clipping*******************/
    int realZ;
    int Z_best[W];

    inline void get_Z_best(int i){
        if(i + 1 + W < n){
            copy(pnum + i + 1, pnum + W + i + 1, Z_best);
            nth_element(Z_best, Z_best + Z, Z_best + W,
                            [i](int a, int b) {
                            return len(points[pnum[a]], points[pnum[i]]) < 
                                    len(points[pnum[b]], points[pnum[i]]); 
                            }
                        );
            realZ = Z;
        } else {
            realZ = n - i - 1;
            copy(pnum + i + 1, pnum + n, Z_best);
            int tmp = Z;
            if(realZ < Z)
                tmp = realZ;
            nth_element(Z_best, Z_best + tmp, Z_best + realZ,
                            [i](int a, int b) {
                            return len(points[pnum[a]], points[pnum[i]]) < 
                                    len(points[pnum[b]], points[pnum[i]]); 
                            }
                        );
        }
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n;
        int x, y;
        for(int i = 0; i < n; ++i){
            cin >> points[i].first >> points[i].second;
            pnum[i] = i;
            component[i] = i;
        }

        Point p0 = {0, 0};
        sort(pnum, pnum + n, [p0](int a, int b) {return len(points[a], p0) <
                                                    len(points[b], p0);});

        for(int i = 0; i < n - 1; ++i){
            get_Z_best(i);
            for(int j = 0; j < realZ; ++j){
                edges[ecount++] = {pnum[i], Z_best[j]};
            }
        }

        sort(edges, edges + ecount, [](const Edge &a, const Edge &b){return len(a) < len(b);});

        int a, b;
        double sum;
        for(int i = 0; i < ecount; ++i){
            if((a = get(edges[i].first)) != (b = get(edges[i].second))){
                component[a] = b;
                edges[okecount++] = edges[i];
                sum += sqrt(len(edges[i]));
            }
        }

        cout.precision(16);
        cout << sum << '\n';
        for(int i = 0; i < okecount; ++i){
            cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
        }

        return 0;
    }