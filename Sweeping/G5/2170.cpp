#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long,long long>> line;
int N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        line.push_back(make_pair(x,y));
    }
    sort(line.begin(), line.end());
    long long end = line[0].first;
    long long total_length = 0;
    for(int i=0;i<N;i++){
        int x = line[i].first, y = line[i].second;
        if(x >= end){
            total_length += y-x;
            end = y;
        }
        else{
            if(y <= end) continue;
            total_length += y-end;
            end = y;
        }
    }
    cout << total_length;
}