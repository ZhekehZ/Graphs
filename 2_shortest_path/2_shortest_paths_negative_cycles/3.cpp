#include <iostream>
#include <vector>
#include <deque>
#include <ios>

using namespace std;

vector<int> g[100000];
char type[100000];
bool used[100000];
int p[100000];
int path[100000];
int n;

void bfs(){
    deque<int> dq;
    dq.push_back(0);
    used[0] = true;
    while(!dq.empty()){
        int k = dq.front();
        dq.pop_front();
        for(auto u : g[k]){
            if(!used[u]){
                used[u] = true;
                p[u] = k;
                if(u == n - 1)
                    break;
                if(type[u] == type[k])
                    dq.push_front(u);
                else
                    dq.push_back(u);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> type[i];

    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();

    if(!used[n - 1]){
        cout << "impossible\n";
    } else { 
        int count = 1;
        path[0] = n - 1;
        int t = n - 1;
        int sum = 0;
        while(t != 0){
            if(type[t] != type[p[t]])
                sum++;
            t = p[t];
            path[count++] = t;
        }

        cout << sum << ' ' << count << '\n';
        for(int i = count - 1; i > -1; --i)
            cout << path[i] + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
