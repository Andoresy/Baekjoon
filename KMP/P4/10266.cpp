#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


int n;

int a[200001];
int b[200001];
int dif_a[400001];
int dif_b[200001];
vector<int> pi(200001);
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i=1;i<n;i++){
        dif_a[i-1] = a[i] - a[i-1];
        dif_b[i-1] = b[i] - b[i-1];
    }
    dif_a[n-1] = (a[0] + 360000) - a[n-1];
    for(int i=1;i<n;i++){
        dif_a[n-1+i] = (a[i] + 360000) - (a[i-1]+360000); 
    }

    pi[0] = 0;
    for(int i=1,j=0;i<n;i++){
        while(j>0 && dif_b[i] != dif_b[j]){
            j = pi[j-1];
        }
        if(dif_b[i] == dif_b[j])
            j++;
        pi[i] = j;
    }
    //for(int i=0;i<2*n-1;i++) cout << dif_a[i] << " ";
    //cout << endl;
    //for(int i=0;i<n-1;i++) cout << dif_b[i] << " ";

    for(int i=1,j=0;i<2*n-1;i++){
        while(j>0 && dif_a[i] != dif_b[j])
            j = pi[j-1];
        if(dif_a[i] == dif_b[j]) j++;
        if(j==(n-1)){
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";
    return 0;
}