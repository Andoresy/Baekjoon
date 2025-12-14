#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
int color[128][128];
int nums[2];
void num_papers(int x, int y, int size){
    if(size==1){
        nums[color[x][y]]++;
        return;
    }
    int c = color[x][y];
    int is_same = 1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int tx = x + i, ty = y + j;
            if(color[tx][ty]!= c){
                is_same =0;
                break;
            }
        }
        if(!is_same) break;
    }
    if(is_same){
        nums[color[x][y]]++;
        return;
    }
    else {
        num_papers(x,y,size/2);
        num_papers(x+size/2, y, size/2);
        num_papers(x,y+size/2,size/2);
        num_papers(x+size/2, y+size/2, size/2);
    }
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> color[i][j];
        }
    }
    num_papers(0,0,N);
    cout << nums[0] <<"\n" << nums[1];
}