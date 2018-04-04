#include <cstdio>
#include <vector>
#include <ios>

using namespace std;

const long long INF = 3000000000000000000;

vector<int> e_beg;
vector<int> e_end;
vector<long long> e_wei;

vector<long long> dists;

int main(){
    int n, m, s;
    //cin >> n >> m >> s;
    scanf("%d %d %d", &n, &m, &s);
    s--;

    int a, b;
    long long c;
    for(int i = 0; i < m; i++){
        //cin >> a >> b;
        //cin >> c;
        scanf("%d %d %lld", &a, &b, &c);
        a--; b--;
        e_beg.push_back(a);
        e_end.push_back(b);
        e_wei.push_back(c);
    }    

    dists.assign(n, INF);
    dists[s] = 0;

    for(size_t count = 1;; count++){
        bool changed = false;
        for(int i = 0; i < m; i++)
            if(dists[e_beg[i]] < INF && dists[e_end[i]] >-INF){
                if(dists[e_end[i]] > dists[e_beg[i]] + e_wei[i]){
                    if(count < n+1)
                        dists[e_end[i]] = dists[e_beg[i]] + e_wei[i];
                    else
                        dists[e_end[i]] = -INF;   
                    changed = true;
                }
            }
        if(!changed)
            break;
    }

    for(auto a : dists){
        if(a == INF)
            //cout << "*\n";
            printf("*\n");
        else if(a == -INF)
            //cout << "-\n";
            printf("-\n");
        else 
            //cout << a << '\n';
            printf("%lld\n", a);
    }

    return 0;
}