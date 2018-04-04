#include <iostream>
#include <vector>
#include <ios>

using namespace std;

const int INF = 600000000;

vector<pair<int, int>> e[100000];
vector<int> d(100000, INF);
int p[100000];
int n, m;

void dijkstra(int v){
    vector<char> used(n, false);
    d[v] = 0;
    for(int i = 0; i < n; ++i){
        int k = -1, val = INF;
        for(int j = 0; j < n; ++j)
            if(!used[j] && d[j] <= val){
                val = d[j];
                k = j;
            }
        if(val == INF)
            break;
        used[k] = true;
        for(auto u : e[k]){
            if(d[u.first] > d[k] + u.second){
                d[u.first] = d[k] + u.second;
                p[u.first] = k;
            } 
        }        
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, t;

    cin >> n >> m;
    cin >> s >> t;
    s--; t--;

    int a, b, w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        e[a - 1].push_back({b - 1, w});
        e[b - 1].push_back({a - 1, w});
    }

    dijkstra(s);

    if(d[t] < INF){
        cout << d[t] << '\n';
        vector<int> path;
        int z = t;
        while(z != s){
            path.push_back(z);
            z = p[z];
        }
        cout << s + 1;
        for(int z = path.size() - 1; z > -1; z--){
            cout << ' ' << path[z] + 1;
        }
        cout << '\n';
    }
    else
        cout << "-1\n";

    return 0;
}