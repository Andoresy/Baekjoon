#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int pre_cal[1000001];
string prefix(string s, int n){
    return s.substr(0,n);
}
string suffix(string s, int n){
    return s.substr(s.size()-n,s.size());
}
vector <int> answers;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string T,P;
    getline(cin, T);
    getline(cin, P);
    pre_cal[0] = 0;
    for(int i=1, j=0;i<P.size();i++){
        while(j>0 && P[i] != P[j])
            j = pre_cal[j-1];
        if(P[i] == P[j])
            j++;
        pre_cal[i] = j;
    }
    for(int i=0,j=0;i<T.size();i++){
        while(j>0 && T[i] != P[j])
            j = pre_cal[j-1];
        if(T[i] == P[j])
            j++;
        //cout << i<< " " << j <<"\n";
        if(j==P.size()){
            answers.push_back(i-j+2);
            j=pre_cal[j-1];
        }
    }
    cout << answers.size() << "\n";
    for(int i=0;i<answers.size();i++) cout << answers[i] << " ";
}
