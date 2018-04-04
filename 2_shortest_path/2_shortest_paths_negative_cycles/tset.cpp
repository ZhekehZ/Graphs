#include <iostream>
#include <list>

using namespace std;

list<int> l;
void print(){
    cout << l.size() << ' ' << (l.empty() ? "true" : "false") << '\n';
}

#define p print();

int main(){
    p
    l.push_back(1);
    auto it = l.begin();
    l.push_back(1);
    l.push_back(1);
    l.push_back(1);
    p
    l.erase(it);
    l.pop_back();
    l.erase(it);
    l.pop_back();
    p
    return 0;
}

