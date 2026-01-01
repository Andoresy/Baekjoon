#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <cmath>
using namespace std;


int main(){
    long long n;
    cin >> n;
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result = result / p * (p - 1);
        }
    }
    if (n > 1) result = result / n * (n - 1);
    cout << result;
    
}