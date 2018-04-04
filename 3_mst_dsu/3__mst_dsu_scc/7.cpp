#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
 
int comp[N], strong_comp[N];    //components
int parent[N], tree_size[N];    //trees

int bridges;

int get_strong_comp(int v){
    if(v < 0)
        return -1;
    return (v == strong_comp[v]) ? v : 
            strong_comp[v] = get_strong_comp(strong_comp[v]);
}

int get_comp(int v){
    if(v < 0)
        return -1;
    return (v == comp[v]) ? v : comp[v] = get_comp(comp[v]);
}

void reroot(int v){
    int new_root = v;
    int child = -1;
    while(v >= 0){
        int par = get_strong_comp(parent[v]);
        parent[v] = child;
        comp[v] = new_root;
        child = v;
        v = par;
    }
    tree_size[new_root] = tree_size[child];
}

int current;
int used[N];
void merge(int a, int b){
    current++;

    int LCA = -1;
    vector<int> va, vb;
    while(true){
        if(a != -1){
            va.push_back(a);
            if(used[a] == current){
                LCA = a;
                break;
            }
            used[a] = current;
            a = get_strong_comp(parent[a]);
        }
        if(b != -1){;
            vb.push_back(b);
            if(used[b] == current){
                LCA = b;
                break;
            }
            used[b] = current;
            b = get_strong_comp(parent[b]);
        }
    }

    for(auto a : va){
        strong_comp[a] = LCA;
        if(a == LCA) break;
        bridges--;
    }
    for(auto b : vb){
        strong_comp[b] = LCA;
        if(b == LCA) break;
        bridges--;
    }
}

void add_edge(int a, int b){
    a = get_strong_comp(a);
    b = get_strong_comp(b);
    if(a == b) return; //same strong comp, do nothing

    int ca = get_comp(a);
    int cb = get_comp(b);
    if(ca != cb){
        //new bridge
        bridges++;
        if(tree_size[ca] > tree_size[cb]){
            swap(a, b); //a - min tree
            swap(ca, cb);
        }
        reroot(a);
        parent[a] = comp[a] = b;
        tree_size[cb] += tree_size[ca]; //a-?
    } else {
        //delete bridge(s)
        merge(a, b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m;

	bridges = 0;
    current = 0;
	for (int i=0; i < n; ++i) {
		comp[i] = strong_comp[i] = i;
        parent[i] = -1;
        tree_size[i] = 1;
 	}

    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        add_edge(a - 1, b - 1);
        //cout << bridges << '\n';
    }

    cin >> k;
    for(int i = 0; i < k; ++i){
        cin >> a >> b;
        add_edge(a - 1, b - 1);
        cout << bridges << '\n';
    }

    return 0;
}