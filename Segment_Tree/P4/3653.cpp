#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int pos[100001];
int TOP;
typedef struct SUMTREE{
    vector<int> rangeSum; //sign -1, 0, 1
    int n;
    SUMTREE(const vector<int>& array){
        n = array.size();
        rangeSum.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node){
        if(left==right) return rangeSum[node] = array[left];
        int mid = (left+right)/2;
        int left_sign = init(array, left, mid, node*2);
        int right_sign = init(array, mid+1, right, node*2+1);
        return rangeSum[node] = left_sign + right_sign;
    }
    int change(int index, int value, int nodeLeft, int nodeRight, int node){
        if(index < nodeLeft || nodeRight < index) return rangeSum[node];
        if(nodeLeft == nodeRight){
            return rangeSum[node] = value;
        }
        int mid = (nodeLeft + nodeRight)/2;
        int left_sum = change(index, value, nodeLeft, mid, node*2);
        int right_sum = change(index, value, mid+1, nodeRight, node*2+1);
        return rangeSum[node] = left_sum + right_sum;
    }
    void change(int index){
        change(pos[index], 0, 0, n-1, 1);
        change(--TOP, 1, 0, n-1, 1);
        pos[index] = TOP;
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node){
        if(right < nodeLeft || nodeRight < left) return 0;
        if(left <= nodeLeft && nodeRight<=right) return rangeSum[node];
        int mid = (nodeLeft + nodeRight)/2;
        int left_sum = query(left, right, nodeLeft, mid, node*2);
        int right_sum = query(left, right, mid+1, nodeRight, node*2+1);
        return left_sum + right_sum;
    }
    int query(int left, int right){
        return query(left, right, 0, n-1, 1);
    }
}SUMTREE;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int N,M;
        cin >> N >> M;
        vector<int> exist;
        for(int i=0;i<M;i++) exist.push_back(0);
        for(int i=0;i<N;i++) exist.push_back(1);
        for(int i=0;i<N;i++) pos[i] = M+i; 
        TOP = M;
        SUMTREE stree = SUMTREE(exist);
        for(int i=0;i<M;i++){
            int loc;
            cin >> loc;
            loc--;
            cout << stree.query(TOP,pos[loc]-1) << " ";
            stree.change(loc);
        }
        cout << "\n";
    }
}