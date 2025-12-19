#include <iostream>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

string T;
vector<int> pi(1000001);
int T_l(int i, int l){
    if(i>=l) return 0;
    else return T[i];
}
bool is_cam(int l){
    int cnt = 0;
    for(int i=0,j=0;i<T.size()-1;i++){
        while(j>0 && T[i] != T_l(j,l)) j = pi[j-1];
        if(T[i] == T_l(j,l)) j++;
        if(j==l) cnt++;
        if(cnt>=2) return true;
    }
    return false;
}
int main(){
    cin >> T;
    pi[0] = 0;
    for(int i=1,j=0;i<T.size();i++){
        if(i==T.size()-1){
            while(j>0 && (T[i] != T[j] || !is_cam(j+1))) j = pi[j-1];
            if(T[i] == T[j] && is_cam(j+1)) j++;
            pi[i] = j; 
        }else{
            while(j>0 && T[i] != T[j]) j = pi[j-1];
            if(T[i] == T[j]) j++;
            pi[i] = j; 
        }
        
    }
    if(pi[T.size()-1] == 0) cout << -1;
    else cout << T.substr(0,pi[T.size()-1]);
    
}