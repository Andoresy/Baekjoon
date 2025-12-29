#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
#define point pair<int, int>
#define line pair<point, point>

vector<int> children[1000001];
vector<int> adj[1000001];
int visited[1000001];
int cache[1000001][2];
void init_tree(int node){
    visited[node] = 1;
    for(const auto& child: adj[node]){
        if(visited[child] == 0){
            visited[child] = 1;
            children[node].push_back(child);
            init_tree(child);
        }
    }
}


int early(int start, int is_last_early){
    int& ret = cache[start][is_last_early];
    if(ret != -1) return ret;
    ret = std::numeric_limits<int>::max();
    if(start == 1 || is_last_early == 1){
        int wo = 0;
        for(const auto& child: children[start]){
            wo+=early(child, 0);
        }

        ret = min(ret, wo);
    }
    int with = 1;
    for(const auto& child: children[start]){
        with+=early(child, 1);
    }
    ret = min(ret, with);
    return ret;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        cache[i][0] = -1;
        cache[i][1] = -1;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init_tree(1);

    cout << early(1,0);
}