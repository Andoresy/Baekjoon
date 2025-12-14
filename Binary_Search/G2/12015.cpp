#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int val[1000001];
int N;
vector<int> LIS;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++) cin >> val[i];
    for(int i=0;i<N;i++){
        if(LIS.empty()){
            LIS.push_back(val[i]);
            continue;
        }
        if(LIS.back() < val[i]){
            LIS.push_back(val[i]);
            continue;
        }
        int left = 0;
        int right = LIS.size()-1;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(LIS[mid] < val[i]){
                left = mid + 1;
            }else{
                ans = mid;
                right = mid - 1;
            }
        }
        if(ans != -1)
            LIS[ans] = val[i];

    }
    cout << LIS.size();

}