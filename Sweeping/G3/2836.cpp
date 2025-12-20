#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<long long,long long>> taxi;

bool sorting(pair<long long, long long>p1, pair<long long, long long>p2 ){
    if(p1.second ==p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        long long f,t;
        cin >> f >> t;
        if(f<t) continue;
        taxi.push_back(make_pair(f,t)); 
    }
    sort(taxi.begin(), taxi.end(), sorting);
    long long L = 0, R = 0;
    long long trip_length = 0;
    for(int i=0;i<taxi.size();i++){
        long long r = taxi[i].first, l = taxi[i].second;
        //cout << l <<" "<< r << "\n";
        if(r<R) continue;
        if(l==L){
            trip_length += (r-R)*3;
            R = r;
        }else{
            if(l<R){
                trip_length += (r-R)*3;
                R =r;
            }else{
                trip_length += (r-R);
                trip_length += 2*(r-l);
                L = l;
                R = r;
            }
        }
    }
    trip_length += (M-R);
    cout << trip_length;
}

// 10 2, 9 3, 11 3, 15 3
// 15->2->15
// 10->2->15->3->15
// x1 y1, x2 y2

// 10 8 16 10
// 10->8->10->16->10->16 (10+4+6+12) 32
//16->8->16 (16+8+8) 32