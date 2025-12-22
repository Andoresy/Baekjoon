#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int INT_MAX = numeric_limits<int>::max();
int sum(int a, int b){
    return a+b;
}
typedef struct RMQ{
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array){
        n = array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node){
        if(left == right) return rangeMin[node] = array[left];
        int mid = (left+right)/2;
        int leftSum = init(array, left, mid, node*2);
        int rightSum = init(array, mid+1, right, node*2 + 1 );
        return rangeMin[node] = sum(leftSum, rightSum);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return 0;
        if(left<= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return sum(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }
    int change(int pos, int node, int nodeLeft, int nodeRight, int value){
        if(nodeRight < pos || pos < nodeLeft) return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = value;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = sum(change(pos, node*2, nodeLeft, mid, value), 
            change(pos, node*2+1, mid+1, nodeRight, value));
    }
    int change(int pos, int value){
        return change(pos, 1, 0, n-1, value);
    }
}RMQ;

vector<int> tree;
int A[500001];
int B[1000001];
int N;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int t;
        cin >> A[i];
        tree.push_back(0);
    }
    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        B[t] = i;
    }
    RMQ stree = RMQ(tree);
    long long ans = 0;
    for(int i=0;i<N;i++){
        int index = B[A[i]];
        //cout << stree.query(index+1, N-1) << endl;
        ans += stree.query(index+1, N-1);
        stree.change(index, 1);
    }
    cout << ans;
}