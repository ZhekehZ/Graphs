#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> id;
char yes[150000];

int get (int v) {
	return (v == id[v]) ? v : (id[v] = get(id[v]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        //DO NOTHING
    }

    vector<pair<char,pair<int, int>>> questions;
    string s;
    for(int i = 0; i < k; ++i){
        cin >> s >> a >> b;
        a--; b--;
        questions.push_back({s[0], {a, b}});
    }

    id.resize(n);
    int y = 0;
    for(int i = 0; i <n; ++i)
        id[i] = i;

    for(int j = questions.size() - 1; j >= 0; --j){
        a = questions[j].second.first;
        b = questions[j].second.second;
        
        if(questions[j].first == 'c'){
            //cut == add
            if((a = get(a)) != (b = get(b))){
                if(rand() & 1) 
                    swap(a, b);
                id[a] = b;
            }
        } else {
            //ask
            yes[y++] = (get(a) == get(b));
        }
    }

    while(y-- > 0)
        cout << (yes[y] ? "YES\n" : "NO\n");

    return 0;
}