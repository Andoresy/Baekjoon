#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,C;
long long cord[200001];
bool is_ge(int distance){
    int cur = 0;
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(cur <= cord[i]){
            cur = cord[i] + distance;
            cnt++;
        }
        if(cnt >= C) return true;
    }
    return false;
}

int main(){
    cin >> N >> C;
    long long max_ = -1;
    for(int i=0;i<N;i++){
        cin >> cord[i];
        max_ = max(max_, cord[i]);
    }
    sort(cord, cord+N);
    long long left = 1, right= max_;
    long long ans = 1;
    while(true){
        if(left>right) break;
        long long mid = (left+right)/2;
        if(is_ge(mid)){
            ans = mid;
            left = mid+1;
        }else{
            right = mid - 1;
        }
    }
    cout << ans;
}