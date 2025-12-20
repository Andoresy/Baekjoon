#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> parent_list;
int parent[100001][17];
vector<int> child[100001];
int level[100001];
int l2(int n){
    return 31 - __builtin_clz(n);
}
void set_tree(int n, int pn){
    parent[n][0] = pn;
    level[n] = level[pn] + 1;
    for(int i=0;(1<<i)<level[n];i++){
        int s = 1<<i;
        if(parent_list.size()-s<0) break;
        parent[n][i] = parent_list[parent_list.size()-s];
    }
    parent_list.push_back(n);
    for(int i=0;i<child[n].size();i++){
        if(level[child[n][i]] != 0) continue;
        set_tree(child[n][i], n);
    }
    parent_list.pop_back();
}

int LCA(int a, int b){
    if(a==b) return a;
    if(level[a] < level[b]) return LCA(b, a);
    if(level[a] == level[b]){
        for(int i=1;i<=l2(level[a]);i++){
            if(parent[a][i] == parent[b][i]) return LCA(parent[a][i-1], parent[b][i-1]);
        }
    }else{
        int log2dif = l2(level[a] - level[b]);
        return LCA(parent[a][log2dif],b);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    int M;
    cin >> N;
    for(int i=0;i<N-1;i++){
        int p,c;
        cin >> p >> c;
        child[p].push_back(c);
        child[c].push_back(p);
    }
    set_tree(1,0);


    cin >> M;
    for(int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;
        cout << LCA(x,y) << "\n";
    }

}
