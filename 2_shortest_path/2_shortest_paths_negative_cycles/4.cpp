#include <cstdio>
#include <vector>
#include <ios>

using namespace std;

const long long INF = 1000000000000000000;

vector<int> e_beg;
vector<int> e_end;
vector<long long> e_wei;

vector<long long> dists;

int main(){
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);
    s--; f--;

    int a, b;
    long long c;
    for(int i = 0; i < m; i++){
        scanf("%d %d %lld", &a, &b, &c);
        a--; b--;
        e_beg.push_back(a);
        e_end.push_back(b);
        e_wei.push_back(c);
    }    

    dists.assign(n, INF);
    dists[s] = 0;

    while(true){
        bool changed = false;
        for(int i = 0; i < m; i++)
            if(dists[e_beg[i]] < INF){
                if(dists[e_end[i]] > dists[e_beg[i]] + e_wei[i]){
                    dists[e_end[i]] = dists[e_beg[i]] + e_wei[i];
                    changed = true;
                }
            }
        if(!changed)
            break;
    }

    printf("%lld\n", dists[f]);

    return 0;
}