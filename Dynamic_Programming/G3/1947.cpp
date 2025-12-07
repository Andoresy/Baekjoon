#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long cache[1000001];
long long MOD = 1000000000;

long long present(int n){
    long long& ret = cache[n];
    if(ret != -1) return n;
    if(n==1) return ret = 0;
    if(n==2) return ret = 1;

}