#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int N;
bool comparePairsDesc(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}
vector<pair<int, int>> A;
typedef struct LIS{
    vector<int> rangeLen; //length, loc_last
    int n;
    LIS(const vector<pair<int,int>>& array){
        n = array.size();
        rangeLen.resize(n*4);
        init( 0, n-1, 1);
    }
    int init(int left, int right, int node){
        if(left==right) return rangeLen[node] = 0;
        int mid = (left+right)/2;
        init(left, mid, node*2);
        init(mid+1, right, node*2+1);
    }
    int add(int index, int nodeLeft, int nodeRight, int node){
        if(index < nodeLeft || nodeRight < index) return rangeLen[node];
        if(nodeLeft == nodeRight){
            int length = query(0, index);
            return rangeLen[node] = length + 1;
        }
        int mid = (nodeLeft + nodeRight)/2;
        int left_len = add(index, nodeLeft, mid, node*2);
        int right_len = add(index, mid+1, nodeRight, node*2+1);
        return rangeLen[node] = max(left_len, right_len);
    }
    void add(int index){
        add(index, 0, n-1, 1);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node){
        if(right < nodeLeft || nodeRight < left) return 0;
        if(left <= nodeLeft && nodeRight<=right) return rangeLen[node];
        int mid = (nodeLeft + nodeRight)/2;
        int left_len = query(left, right, nodeLeft, mid, node*2);
        int right_len = query(left, right, mid+1, right, node*2+1);
        return max(left_len, right_len);
    }
    int query(int left, int right){
        return query(left, right, 0, N-1, 1);
    }
}LIS;
int main(){
    //10,20,30,50
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(make_pair(a,i));
    }
    sort(A.begin(), A.end(),comparePairsDesc);
    LIS stree = LIS(A);
    for(int i=0;i<N;i++){
        int index = A[i].second;
        //cout << A[i].first << " "<<A[i].second <<"\n";
        stree.add(index);
    }
        cout << stree.query(0,N-1);
}