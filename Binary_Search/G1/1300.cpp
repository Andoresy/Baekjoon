#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long N,k;
long long le_count(long long n){
    long long cnt = 0;
    for(long long i=1;i<=N;i++){
        cnt += min(N,n/i);
    }
    return cnt;
}
long long l_count(long long n){
    long long cnt = 0;
    for(long long i=1;i<=N;i++){
        cnt += min(N,(n-1)/i);
    }
    return cnt;
}
//i*N+j = 
int main(){
    cin >> N >> k;
    long long left = 1,right = k;
    long long ans = 0;
    while(true){
        if(left > right) break;
        int mid = (left+right)/2;
        long long le_cnt  = le_count(mid);
        //cout << left << " " << right << " "<< mid << " "<<temp << endl;
        if(le_cnt >= k){
            ans = mid;
            right = mid-1;
        }else{
            left = mid + 1;    
        }
    }
    cout << ans;
}

//X보다 작거나 같은것
// 각 행에서  X/k 