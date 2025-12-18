#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int pre_cal[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string P;
    while(true){
        getline(cin, P);
        if(P == ".") break;
        pre_cal[0] = 0;
        for(int i=1, j=0;i<P.size();i++){
            if(i==P.size()-1){
                while(j>0 && (P[i] != P[j] || (P.size()%(P.size()-j-1) !=0))){
                    //cout << i << j << "\n";
                    j=pre_cal[j-1];
                }
            }else{
                while(j>0 && P[i] != P[j]){
                    j = pre_cal[j-1];
                }
            }
            
            if(P[i] == P[j])
                j++;
            pre_cal[i] = j;
        }
        if(pre_cal[P.size()-1] == 0) cout << 1 << "\n";
        else cout << P.size()/(P.size()-pre_cal[P.size()-1]) << "\n";
    }
    
}
