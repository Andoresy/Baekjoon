#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

long long scovil[300001];
long long MOD = 1000000007;
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> scovil[i];
    }
    long long total=0;
    sort(scovil, scovil+N);
    for(int i=0;i<N-1;i++){
        total += ((scovil[i+1]-scovil[i])*(i+1)*(N-i-1))%MOD;
        total %= MOD;
    }
    cout << total;

}


/*1 2 4 7 11
1 (1+2) (1+2+3) (1+2+3+4)
2 (2+3) (2+3+4)
3 (3+4)
4*/
