#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int mid = 0;
        cin >> N;
        cout << (N/2+1) << "\n";
        for(int j=0;j<N;j++){
            int number;
            cin >> number;
            if(j==0){
                mid = number;
            }
            else{
                if(mid<number) min_heap.push(number);
                else max_heap.push(number);
            }
            if(j%2==0){
                if(max_heap.size() > min_heap.size()){
                    min_heap.push(mid);
                    mid = max_heap.top();
                    max_heap.pop();
                }else if(max_heap.size()<min_heap.size()){
                    max_heap.push(mid);
                    mid = min_heap.top();
                    min_heap.pop();
                }
                cout << mid << " ";
            }
            if(j!=0 && (j+2)%20==0) cout << "\n";
            else if(j==N-1) cout << "\n";
        }
    }
}