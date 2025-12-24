#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct SIGN{
    vector<int> rangeSign; //sign -1, 0, 1
    int n;
    SIGN(const vector<int>& array){
        n = array.size();
        rangeSign.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node){
        if(left==right) return rangeSign[node] = array[left];
        int mid = (left+right)/2;
        int left_sign = init(array, left, mid, node*2);
        int right_sign = init(array, mid+1, right, node*2+1);
        return rangeSign[node] = left_sign * right_sign;
    }
    int change(int index, int value, int nodeLeft, int nodeRight, int node){
        if(index < nodeLeft || nodeRight < index) return rangeSign[node];
        if(nodeLeft == nodeRight){
            return rangeSign[node] = value;
        }
        int mid = (nodeLeft + nodeRight)/2;
        int left_sign = change(index, value, nodeLeft, mid, node*2);
        int right_sign = change(index, value, mid+1, nodeRight, node*2+1);
        return rangeSign[node] = left_sign*right_sign;
    }
    void change(int index, int value){
        change(index, value, 0, n-1, 1);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node){
        if(right < nodeLeft || nodeRight < left) return 1;
        if(left <= nodeLeft && nodeRight<=right) return rangeSign[node];
        int mid = (nodeLeft + nodeRight)/2;
        int left_sign = query(left, right, nodeLeft, mid, node*2);
        int right_sign = query(left, right, mid+1, nodeRight, node*2+1);
        return left_sign*right_sign;
    }
    int query(int left, int right){
        return query(left, right, 0, n-1, 1);
    }
}SIGN;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, K;
    while(cin >> N >> K){
        vector<int> NUM;
        for(int i=0;i<N;i++){
            int t;
            cin >> t;
            t = (t>0)?1:((t==0)?0:-1);
            NUM.push_back(t);
        }
        SIGN stree = SIGN(NUM);
        for(int i=0;i<K;i++){
            char X;
            int a,b;
            cin >> X >> a >> b;
            if(X == 'C'){
                b = (b>0)?1:((b==0)?0:-1);
                stree.change(a-1, b);
            }else{
                int t = stree.query(a-1,b-1);
                if(t>0) cout << "+";
                else if(t<0) cout << "-";
                else cout << t;
            }
        }
        cout << "\n";
    }
}