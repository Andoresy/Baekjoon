#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


string S;
string e_S;
int main(){
    cin >> S;
    for(char c: S){
        e_S += '?';
        e_S += c;
    }
    e_S += '?';
    //cout << e_S << "\n";
    S = e_S;
    int p,r = -1;
    int res[200010];
    for(int i=0;i<S.size();i++){
        if(i>r){
            p = r = i;
            while(r<S.size() && r<= 2*p && S[r] == S[2*p -r]){
                r++;
            }
            r--;
            res[i] = r-p;
        }else{
            int l = (2*p-r);
            int j = (2*p-i);
            if(res[j] < r-i) res[i] = res[j];
            else if(res[j] > r-i) res[i] = r-i;
            else{
                p = i;
                while(r<S.size() && r<= 2*p && S[r] == S[2*p -r]){
                    r++;
                }
                r--;
                res[i] = r-p;
            }
        }
    }
    int m = 1;
    for(int i=0;i<S.size();i++){
        //cout << res[i] << " ";
        m = max(m, res[i]);
    }
    //cout <<endl;
    
    cout << m;
}
//abab