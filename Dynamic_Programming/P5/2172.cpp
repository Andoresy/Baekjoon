#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int cache[21][21][21][21][21];
int way[8][2] = {
    {-1, 0}, // 상
    { 1, 0}, // 하
    { 0,-1}, // 좌
    { 0, 1}, // 우
    {-1,-1}, // 좌상
    {-1, 1}, // 우상
    { 1,-1}, // 좌하
    { 1, 1}  // 우하
};
int value[21][21];
int L,N;
int palin(int len, int x1, int y1, int x2, int y2){
    int& ret = cache[len][x1][y1][x2][y2];
    if(ret != -1) return ret;
    if(value[x1][y1] != value[x2][y2]) return ret = 0;
    if(len==L-1 && x1 == x2 && y1 == y2) return ret = 1;
    if(len==L-2 && abs(x1-x2) <= 1 && abs(y1-y2) <=1 && !(x1==x2 && y1==y2)) return ret = 1;
    if(len>=L-2) return ret = 0;
    ret = 0;
    for(int w1=0;w1<8;w1++){
        for(int w2=0;w2<8;w2++){
            int nx1 = x1 + way[w1][0], ny1 = y1 + way[w1][1];
            int nx2 = x2 + way[w2][0], ny2 = y2 + way[w2][1];
            if(nx1<0 || nx1>=N || ny1<0 || ny1>=N) continue;
            if(nx2<0 || nx2>=N || ny2<0 || ny2>=N) continue;
            if(value[nx1][ny1] != value[nx2][ny2]) continue;
            ret += palin(len+2, nx1,ny1,nx2,ny2);
        }
    }
    return ret;
}

int main(){
    cin >> N >> L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> value[i][j];
        }
    }
    for(int i=0;i<=L;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                for(int l=0;l<N;l++){
                    for(int p=0;p<N;p++){
                        cache[i][j][k][l][p] = -1;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int x1=0;x1<N;x1++){
        for(int y1=0;y1<N;y1++){
            for(int x2=0;x2<N;x2++){
                for(int y2=0;y2<N;y2++){
                    //cout << x1 <<" " << y1 << " " << x2 << " " << y2 << " " << palin(0,x1,y1,x2,y2) << endl;
                    ans+=palin(0,x1,y1,x2,y2);
                }
            }
        }
    }
    cout << ans;
}