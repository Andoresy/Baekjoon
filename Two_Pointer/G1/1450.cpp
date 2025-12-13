#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> left_half;
vector<int> right_half;
int left_array[15];
int right_array[15];
int N,C;
void dfs_search(int N, int array[], vector<int>& vec){
    stack<pair<int,int>> st;
    if(N==0) return;
    st.push(make_pair(array[0],0));
    st.push(make_pair(0,0));
    while(!st.empty()){
        int top = st.top().first, index = st.top().second;
        st.pop();
        if(index==N-1){
            if(top<=C) vec.push_back(top);
            continue;
        }
        if(top > C){
            continue;
        }
        st.push(make_pair(top, index+1));
        if(top + array[index + 1]) st.push(make_pair(top+array[index+1], index+1));
    }
}

int main(){
    cin >> N >> C;
    int NL = N/2 + (N%2);
    int NR = N/2;

    for(int i=0;i<NL;i++){
        cin >> left_array[i];
    }
    for(int i=0;i<NR;i++){
        cin >> right_array[i];
    }

    dfs_search(NL, left_array, left_half);
    dfs_search(NR, right_array, right_half);

    if(NR==0){
        cout << left_half.size();
        return 0;
    }

    sort(left_half.begin(), left_half.end());
    sort(right_half.begin(), right_half.end());
    
    int total_count = 0;
    for(int i=0;i<left_half.size();i++){
        int left = 0;
        int right = right_half.size()-1;
        int val = left_half[i];
        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(val + right_half[mid] <= C){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if(ans == -1) break;
        total_count += ans+1;
    }
    cout << total_count;
    return 0;
}