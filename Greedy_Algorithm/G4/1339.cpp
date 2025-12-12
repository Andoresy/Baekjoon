#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long weight[26];  // 각 알파벳의 자리수 기여도

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> words(N);

    for(int i=0; i<N; i++) cin >> words[i];

    // 1. 각 알파벳의 자리수 기여도 계산
    for(const string& w : words){
        int len = w.length();
        for(int i = 0; i < len; i++){
            int alpha = w[i] - 'A';
            int power = len - i - 1;   // 10^(자리수)
            weight[alpha] += pow(10, power);
        }
    }

    // 2. 기여도(weight)가 큰 순서대로 정렬
    vector<long long> wlist;
    for(int i=0; i<26; i++){
        if(weight[i] > 0) wlist.push_back(weight[i]);
    }

    sort(wlist.begin(), wlist.end(), greater<long long>());

    // 3. 9부터 차례대로 곱해 total 계산
    long long answer = 0;
    int digit = 9;
    for(long long w : wlist){
        answer += w * digit;
        digit--;
    }

    cout << answer;
}
