#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long cache[1000001];
long long MOD = 1000000000;
long long present(int n){
    long long& ret = cache[n];
    if(ret != -1) return ret;
    if(n==1) return ret = 0;
    if(n==2) return ret = 1;
    ret = 0;
    ret += (n-1)*present(n-1);
    ret %=MOD;
    ret += ((n-1)*present(n-2))%MOD;
    ret %= MOD;
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<=N;i++){
        cache[i] = -1;
    }
    cout << present(N);
}
