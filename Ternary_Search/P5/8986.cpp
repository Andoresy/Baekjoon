#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long long loc[100001];
int N;
long long cost(long long t){
    long long ret = 0;
    for(int i=0;i<N;i++){
        ret += abs(loc[i]-t*i);
    }
    return ret;
}

int main(){
    cin >> N;
    long long maxval = 0;
    for(int i=0;i<N;i++) {
        cin >> loc[i];
        maxval = max(loc[i], maxval);
    }

    long long left = 1;
    long long right = maxval;
    while(left < right-2){
        long long midl = left + (right-left)/3;
        long long midr = left + ((right-left)*2)/3;
        if(cost(midl) < cost(midr)){
            right = midr;
        }else{
            left = midl;
        }
        //cout << left << " " <<right << " "<<cost(left)<< endl;
    }
    long long minval = cost(left);
    for(int l = left+1;l<=right;l++){
        minval = min(cost(l), minval);
    }
    cout << minval;
    
}