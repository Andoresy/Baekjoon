#include <iostream>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

char str1[2000001];
char str2[1000001];
vector<int> pi(2000001);
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> str1[i];
    for(int i=0;i<N;i++) cin >> str2[i];
    for(int i=0;i<N-1;i++){
        str1[N+i] = str1[i];
    }
    pi[0] = 0;
    for(int i=1,j=0;i<N;i++){
        while(j>0 && str2[i] != str2[j]){
            j = pi[j-1];
        }
        if(str2[i] == str2[j])
            j++;
        pi[i] = j;
    }
    int cnt = 0;
    for(int i=0,j=0;i<2*N-1;i++){
        while(j>0 && str1[i] != str2[j]){
            j = pi[j-1];
        }
        if(str1[i] == str2[j])
            j++;
        if(j==N){
            cnt++;
        }
    }
    int g = gcd(cnt, N);
    cout << (cnt/g) << "/" << ((N)/g);
    
    
}
