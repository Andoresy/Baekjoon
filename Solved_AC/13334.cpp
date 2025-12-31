#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct CompareSecond {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        return lhs.second < rhs.second; // 'true' means lhs has lower priority than rhs
    }
};



vector<pair<int, int>> intervals;
vector<int> startloc;
int d;

int max_cnt(){
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    priority_queue<int, vector<int>, greater<int>> pq_start;
    int max_count = 0;
    for(int i=0;i<intervals.size();i++){
        int start = intervals[i].first;
        int end = intervals[i].second;
        if(end-start > d) continue;
        pq_start.push(start);
        while(!pq_start.empty() && pq_start.top() < end - d){
            pq_start.pop();
        }    
        max_count = max(max_count, (int)pq_start.size());
    }
    
    return max_count;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s,f;
        cin >> s >> f;
        if(s>f) intervals.push_back({f,s});
        else intervals.push_back({s,f});

    }
    cin >> d;
    cout << max_cnt();

}


