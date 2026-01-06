#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct MINTREE{
    vector<int> rangeMin; //sign -1, 0, 1
    int n;
    MINTREE(const vector<int>& array){
        n = array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node){
        if(left==right) return rangeMin[node] = array[left];
        int mid = (left+right)/2;
        int left_min = init(array, left, mid, node*2);
        int right_min = init(array, mid+1, right, node*2+1);
        return rangeMin[node] = min(left_min, right_min);
    }
    
    int query(int left, int right, int nodeLeft, int nodeRight, int node){
        if(right < nodeLeft || nodeRight < left) return 1000000001;
        if(left <= nodeLeft && nodeRight<=right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight)/2;
        int left_min = query(left, right, nodeLeft, mid, node*2);
        int right_min = query(left, right, mid+1, nodeRight, node*2+1);
        return min(left_min,right_min);
    }
    int query(int left, int right){
        return query(left, right, 0, n-1, 1);
    }
}MINTREE;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int t;
    vector<int> array;
    vector<int> array2;
    for(int i=0;i<N;i++){
        cin>>t;
        array.push_back(t);
        array2.push_back(-t);
    }
    MINTREE mintree(array);
    MINTREE maxtree(array2);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cout << mintree.query(a,b) << " " << -1 * maxtree.query(a,b) << "\n";
    }
}