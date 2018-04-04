
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int INF = 200000000;

deque<int> q;        
vector<int> en[50001];
vector<int> we[50001];

int dists[25000];
char in_queue[25000];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int a, b, c;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        en[a].push_back(b);
        we[a].push_back(c);
    }

    fill_n(&dists[0], n, INF);

    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; ++i){
        scanf("%d %d", &a, &b);
        a--; b--;

        if(dists[a] == 0){
            if(dists[b] < INF)
                printf("%d\n", dists[b]);
            else
                printf("-1\n");
        } else {
            fill_n(&dists[0], n, INF);
            dists[a] = 0;

            q.push_back(a);
            in_queue[a] = true;
            while(!q.empty()){
                int v = q.front();
                q.pop_front();
                in_queue[v] = false;
                for(int i = 0; i < en[v].size(); ++i){
                    int u = en[v][i], w = we[v][i];
                    if(dists[u] > dists[v] + w){
                        dists[u] = dists[v] + w;
                        if(!in_queue[u]){
                            if((!q.empty()) && dists[q.front()] >= dists[u])
                                q.push_front(u);
                            else
                                q.push_back(u);
                            in_queue[u] = true;
                        }
                    }
                }
            }
            if(dists[b] < INF)
                printf("%d\n", dists[b]);
            else
                printf("-1\n");
        }
    }
    return 0;
}