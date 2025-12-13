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
    sort(X, X+N);
    int* left = X;
    int* right = X+(N-1);
    int ans = (*left) + (*right);
    int l = *left;
    int r = *right;
    while(left<right){
        int s = (*left) + (*right);
        if(abs(ans) > abs(s)){
            ans = s;
            l = *left;
            r = *right;
        } 
        if(ans==0) break;
        if(s < 0){
            left++;
        }else{
            right--;
        }
    }
    cout << l << " " << r;
}