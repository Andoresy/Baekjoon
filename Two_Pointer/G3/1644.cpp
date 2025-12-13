#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool is_not_prime[4000005];
vector<int> prime_numbers;
void prime(int N){
    int n=1;
    is_not_prime[1] = true;
    for(int i=2;i<=N;i++){
        if(is_not_prime[i]) continue;
        prime_numbers.push_back(i);
        for(int v=i*2;v<=N;v+=i){
            is_not_prime[v] = true;
        }
    }
}
int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << 0;
        return 0;
    }
    prime(N);
    int start_pos = 0;
    int end_pos = 0;
    int sum = prime_numbers[0];
    int cnt = 0;
    while(end_pos < prime_numbers.size()){
        if(sum<N){
            end_pos++;
            if(end_pos >= prime_numbers.size()) break;
            sum+=prime_numbers[end_pos];
        }else if(sum>N){
            sum-=prime_numbers[start_pos];
            start_pos++;
        }else{
            cnt++;
            sum-=prime_numbers[start_pos];
            start_pos++;
            end_pos++;
            if(end_pos >= prime_numbers.size()) break;
            sum+=prime_numbers[end_pos];
        }
    }
    cout << cnt;
}