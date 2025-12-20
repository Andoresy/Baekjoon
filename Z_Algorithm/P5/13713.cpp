#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

string s;
string r_s;
int Z[1000001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s;
    reverse(s.begin(), s.end());
    int L,R=0;
    //cout << s << endl;
    for(int i=1;i<s.size();i++){
        if(R<i){
            L = R = i;
            while(R<s.size() && s[R-i]==s[R]) R++;
            Z[i] = R-L;
            R--;
        }else{
            if(Z[i-L]<R-i + 1) Z[i] = Z[i-L];
            else{
                L = i;
                while(R<s.size() && s[R-i]==s[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    Z[0] = s.size();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        cout << Z[s.size()-temp] << "\n";
    }
}