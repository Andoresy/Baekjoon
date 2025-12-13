#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int X[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> X[i];
    int x;
    cin >> x;
    sort(X, X+N);
    int* left = X;
    int* right = X+(N-1);
    long long cnt = 0;
    while(left<right){
        int s = (*left) + (*right);
        if(s == x){
            cnt++;
            left++;
            right--;
        }else if(s<x){
            left++;
        }else{
            right--;
        }
    }
    cout << cnt;
}