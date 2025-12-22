#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
const int INT_MAX = numeric_limits<int>::max();
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
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid+1, right, node*2 + 1 );
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        if(left<= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }
    int change(int pos, int node, int nodeLeft, int nodeRight, int value){
        if(nodeRight < pos || pos < nodeLeft) return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = value;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(change(pos, node*2, nodeLeft, mid, value), 
            change(pos, node*2+1, mid+1, nodeRight, value));
    }
    int change(int pos, int value){
        return change(pos, 1, 0, n-1, value);
    }
}RMQ;
vector<int> num;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        num.push_back(n);
    }
    RMQ min_stree = RMQ(num);
    cin >> M;
    for(int i=0;i<M;i++){
        int m,a,b;
        cin >> m >> a >> b;
        a--;
        if(m==1){
            min_stree.change(a, b);
            //cout << min_stree.query(0,4) << "\n";
        }else{
            b--;
            cout << min_stree.query(a,b) << "\n";
        }
        
    }

}