#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int cache[502][101][3];
int map[501];
int N,M,X,Y;
int a,b;
int MAXIMUM = (1<<30) - 1;
int sadari(int level, int cur_pos, int direction){//direction: 1. left 2. right
    /*
    1. 아무것도 안하기
    2. 왼쪽으로 한칸 추가하기
    3. 오른쪽으로 한칸 추가하기
    4. 없애고 내려가기
    */
   //cout << level << " " << cur_pos << " " << direction << endl;
   if(level==M+1 && cur_pos == b) return 0;
   if(level>=M + 1) return MAXIMUM;
   int& ret=  cache[level][cur_pos][direction];
   if(ret != -1) return ret;

    int new_pos;
    ret = MAXIMUM;
    
    if(level == M){ // 마지막하나 더...
        if(cur_pos != 0 && direction != 2){
            new_pos = cur_pos - 1;
            ret = min(ret, Y + sadari(level,new_pos,1));
        }
        //3번 케이스 (제일 오른쪽이 아닌경우)
        if(cur_pos != N-1 && direction !=1){
            new_pos = cur_pos + 1;
            ret = min(ret, Y + sadari(level,new_pos,2));
        }
        ret = min(ret, sadari(level+1, cur_pos, 0));
    }else{
        //1번 케이스
        if(cur_pos == map[level]) new_pos = cur_pos + 1;
        else if(cur_pos == map[level]+1) new_pos = cur_pos - 1;
        else new_pos = cur_pos;
        ret = min(ret, sadari(level+1, new_pos, 0));
        //2번 케이스 (제일 왼쪽이 아닌경우)
        if(cur_pos != 0 && direction != 2){
            new_pos = cur_pos - 1;
            ret = min(ret, Y + sadari(level,new_pos,1));
        }
        //3번 케이스 (제일 오른쪽이 아닌경우)
        if(cur_pos != N-1 && direction !=1){
            new_pos = cur_pos + 1;
            ret = min(ret, Y + sadari(level,new_pos,2));
        }
        ret = min(ret, X + sadari(level+1, cur_pos, 0));
    }
    
    return ret;
}

int main(){
    cin >> N >> M;
    cin >> a >> b >> X >> Y;
    a--;b--;
    for(int i=0;i<M;i++){
        cin >> map[i];
        map[i]--;
    }
    for(int i=0;i<=M+1;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<3;k++)
                cache[i][j][k] = -1;
        }
    }
    cout << sadari(0,a,0);
}