#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long N,M;
int times[10001];
int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> times[i];
    if(N<=M){
        cout << N;
        return 0;
    }
    long long left=0, right=N*30;
    long long ans;
    while(left <= right){
        long long cnt=0;
        long long mid = (left+right)/2;
        for(int i=0;i<M;i++){
            cnt += mid/times[i] + 1;
        }
        if(cnt >= N){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    long long cnt = 0;
    for(int i=0;i<M;i++){
        cnt += (ans-1)/times[i] + 1;
    }
    for(int i=0;i<M;i++){
        if(ans%times[i] == 0) cnt++;
        if(cnt==N){
            cout << (i+1);
            break;
        }
    }
    
}

// 9 4 3 2 1 ->19
// 20 21 . . 22