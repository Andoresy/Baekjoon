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
    SUMTREE(int n){
        this->n = n;
        rangeSum.resize(n*4);
        init(0, n-1, 1);
    }
    int init(int left, int right, int node){
        if(left==right) return rangeSum[node] = 1;
        int mid = (left+right)/2;
        int left_sign = init(left, mid, node*2);
        int right_sign = init(mid+1, right, node*2+1);
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
        change(index, 0, 0, n-1, 1);
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
    int find_pos_index(int blanks) {
        return find_pos_index(blanks, 0, n - 1, 1);
    }
    int find_pos_index(int blanks, int nodeLeft, int nodeRight, int node) {
        if (nodeLeft == nodeRight) {
            return nodeLeft;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        int leftEmpty = rangeSum[node * 2];

        if (leftEmpty >= blanks) {
            return find_pos_index(blanks, nodeLeft, mid, node * 2);
        } else {
            return find_pos_index(blanks - leftEmpty, mid + 1, nodeRight, node * 2 + 1);
        }
    }
}SUMTREE;
int A[100001];
int ANS[100001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    SUMTREE stree = SUMTREE(N);
    for(int i=0;i<N;i++){
        int position = stree.find_pos_index(A[i]+1);
        stree.change(position);
        ANS[position] = i + 1;
    }
    for(int i=0;i<N;i++){
        cout << ANS[i] << "\n";
    }
}