#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <unistd.h>

using namespace std;

list<int>::iterator its[25000];
int dists[25000];

struct Magic{
    struct pack{
        list<int> batch[1000];
        set<int> nempty;

        void push(int v, int pos){
            batch[pos].push_front(v);
            its[v] = batch[pos].begin();
            nempty.insert(pos);
        }

        void erase(int v, int pos){
            batch[pos].erase(its[v]);
            if(batch[pos].empty())
                nempty.erase(pos);
        }

        int get_min(){
            int pos = *(nempty.begin());
            int v = batch[pos].front();
            return v;
        }

        bool empty(){
            return nempty.empty();
        }
    };

    int left_bound = 0;
    pack bucket[3];

    void reset(){
        left_bound = 0;
    }

    bool empty(){
        return bucket[0].empty() && 
                bucket[1].empty() && 
                bucket[2].empty();
    }

    void push(int v, int d){
        d -= left_bound;
        int b = d / 1000;
        d %= 1000;
        bucket[b].push(v, d);
    }

    int get_min(){
        return bucket[0].get_min();
    }

    void erase(int v){
        if(dists[v] < left_bound || 
            dists[v] > left_bound + 3000) return;
        int d = dists[v] - left_bound;
        int b = d / 1000;
        d %= 1000;
        bucket[b].erase(v, d);
        check();
    }

    void check(){
        for(int i = 0; i < 2; ++i)
            if(bucket[0].empty()){
                swap(bucket[0], bucket[1]);
                swap(bucket[1], bucket[2]);
                left_bound += 1000;
            }
    }
};

int n, m;
const int INF = 1e9;
Magic MAGIC;
vector<pair<int, int>> g[25000];

void dijkstra(int s){
    MAGIC.reset();
    fill_n(dists, n, INF);
    dists[s] = 0;
    MAGIC.push(s, dists[s]);
    while(!MAGIC.empty()){
        int v = MAGIC.get_min();
        for(auto u : g[v]){
            if(dists[u.first] > dists[v] + u.second){
                MAGIC.erase(u.first);
                dists[u.first] = dists[v] + u.second;
                MAGIC.push(u.first, dists[u.first]);
            }
        }
        MAGIC.erase(v);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        a--; b--;
        if(a != b)
            g[a].push_back({b, c});
    }
    
    int k;
    cin >> k;
    for(int j = 0; j < k; ++j){
        cin >> a >> b;
        a--; b--;
        dijkstra(a);
        cout << (dists[b] < INF ? dists[b] : -1)<< '\n';
    }
    return 0;
}
