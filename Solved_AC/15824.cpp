#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

long long scovil[300001];
long long MOD = 1000000007;
long long twos[300001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> scovil[i];
    }
    long long t = 1;
    for(int i=0;i<300001;i++){
        twos[i] = t;
        t*=2;
        t%=MOD;
    }
    long long total=0;
    sort(scovil, scovil+N);
    for(int i=0;i<N;i++){
        total -= scovil[i]*twos[N-i-1];
        total = (total + MOD)%MOD;
    }
    for(int i=0;i<N;i++){
        total += scovil[N-i-1]*twos[N-i-1];
        total %= MOD;
    }
    cout << total;

}
