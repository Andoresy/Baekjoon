#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define point pair<int, int>
#define line pair<point, point>

int parent[500001];
int find_(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_(parent[x]);
}
void union_(int x, int y){
    int parent_x = find_(x);
    int parent_y = find_(y);
    parent[parent_y] = parent_x;
}

int in_set(int x, int y){
    return find_(x) == find_(y);
}




int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(in_set(a,b)){
            cout << i+1;
            return 0;
        }
        union_(a,b);
    }
    cout << 0;
}