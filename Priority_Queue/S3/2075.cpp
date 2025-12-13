#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

priority_queue<int> realpq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        priority_queue<int> pq;
        for(int j=0;j<N;j++){
            int t;
            cin >> t;
            realpq.push(t);
        }
        for(int i=0;i<N;i++){
            pq.push(realpq.top());
            realpq.pop();
        }
        realpq = pq;
    }
    for(int i=0;i<N-1;i++){
        realpq.pop();
    }
    cout << realpq.top();
}