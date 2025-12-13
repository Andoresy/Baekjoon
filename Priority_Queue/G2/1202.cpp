#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

priority_queue<long long> pq;
vector<pair<long long,long long>> jew;
vector<long long> backpack;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,K;
    cin >> N >> K;
    for(long long i=0;i<N;i++){
        long long m,v;
        cin >> m >> v;
        jew.push_back(make_pair(m,v));
    }
    for(long long k=0;k<K;k++){
        long long c;
        cin >> c;
        backpack.push_back(c);
    }
    sort(backpack.begin(), backpack.end());
    sort(jew.begin(), jew.end(), greater<pair<long long,long long>>());
    long long ans = 0;
    for(long long i=0;i<K;i++){
        long long bp = backpack[i];
        while(!jew.empty()){
            long long m = jew.back().first, v = jew.back().second;
            if(m>bp) break;
            pq.push(v);
            jew.pop_back();
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
    }
    cout << ans;
}