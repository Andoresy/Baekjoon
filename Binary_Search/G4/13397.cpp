#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
int value[5001];

int is_possible(int s){
    int cnt=1, cur_pos = 0;
    int minval = value[cur_pos],maxval = value[cur_pos];
    for(int i=0;i<N;i++){
        maxval = max(maxval, value[i]);
        minval = min(minval, value[i]);
        if(maxval - minval> s){
            cur_pos = i;
            cnt++;
            minval = value[cur_pos];
            maxval = value[cur_pos];
        }
        if(cnt > M) return 0;
    }
    return 1;
}

int main(){
    cin >> N >> M;
    int temp_min = 10001,temp_max = 0;
    for(int i=0;i<N;i++) {
        cin >> value[i];
        temp_min = min(temp_min, value[i]);
        temp_max = max(temp_max, value[i]);
    }
    int left = 0,right = temp_max - temp_min;
    int ans;
    while(true){
        int mid = (left+right)/2;
        if(left>right) break;
        if(is_possible(mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid + 1;
        }
    }
    cout << ans;
}