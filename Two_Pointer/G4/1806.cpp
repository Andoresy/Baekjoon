#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int X[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> X[i];
    int* left = X;
    int* right = X;
    long long sum = *X;
    int ans = N+1;
    while(right<X+N){
        while(left<right && sum>S){
            if(sum - (*left) >= S){
                sum -= (*left);
                left++;
            }else break;
        }
        //cout << (left-X)<< " "<< (right-X) << " " <<  sum <<endl;
        if(sum>=S) ans = min(ans, (int)(right-left) + 1);
        right++;
        sum+=*right;
    }
    if(ans == N+1) cout << 0;
    else cout << ans;
}