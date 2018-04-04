#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int S, F;
vector<int> g[100];
int d[100];

bool bfs(){
    queue<int> q;
    q.push(S);
    d[S] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i : g[t]){
            if(d[i] == 0){
                d[i] = d[t] + 1;
                q.push(i);
            }
            if(i == F)
                return true;
        }
    }
}

int main(){
    int n;
    bool t;
    cin >> n >> S >> F;
    S--; F--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> t;
            if(t) g[i].push_back(j);
        }

    bfs();
    if(d[F])
        cout << d[F] - 1 << '\n';
    else
        cout << 0;
    return 0;
}