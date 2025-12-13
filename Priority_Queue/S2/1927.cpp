#include <iostream>
using namespace std;
int heap[100001];
int cur_loc;
int top(){
    return heap[0];
}
int pop(){
    int ret = heap[0];
    heap[0] = heap[--cur_loc];
    heap[cur_loc] = 0;
    int loc = 0;
    while(loc < cur_loc){
        if(heap[loc*2+1] == 0) break;
        if(heap[loc*2+2] == 0){
            if(heap[loc] > heap[loc*2 + 1]){
                int temp = heap[loc];
                heap[loc] = heap[loc*2+1];
                heap[loc*2+1] = temp;
                loc = loc*2 + 1;
                continue;
            }
        }
        else if(heap[loc*2+1] < heap[loc*2+2]){
            if(heap[loc] > heap[loc*2 + 1]){
                int temp = heap[loc];
                heap[loc] = heap[loc*2+1];
                heap[loc*2+1] = temp;
                loc = loc*2 + 1;
                continue;
            }
        }else{
            if(heap[loc] > heap[loc*2 + 2]){
                int temp = heap[loc];
                heap[loc] = heap[loc*2+2];
                heap[loc*2+2] = temp;
                loc = loc*2 + 2;
                continue;
            }
        }
        
        break;
    }
    return ret;
}
void push(int n){
    heap[cur_loc] = n;
    int loc = cur_loc++;
    while(loc!=0){
        if(heap[(loc-1)/2] > heap[loc]){
            int temp = heap[(loc-1)/2];
            heap[(loc-1)/2] = heap[loc];
            heap[loc] = temp;
        }else{
            break;
        }
        loc=(loc-1)/2;
    }
}

int main(){
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        if(t==0 && cur_loc == 0) cout << top() << "\n";
        else if(t==0) cout << pop() << "\n";
        else push(t);
    }
}