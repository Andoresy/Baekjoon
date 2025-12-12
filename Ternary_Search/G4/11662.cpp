#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;

double distance(double t){
    double dis_x = (Ax+(Bx-Ax)*t) - (Cx+(Dx-Cx)*t);
    double dis_y = (Ay+(By-Ay)*t) - (Cy+(Dy-Cy)*t);
    return dis_x*dis_x + dis_y*dis_y;
}

int main(){
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
    double left = 0;
    double right = 1;
    for(int i=0;i<300;i++){
        double midl = left + (right-left)/3;
        double midr = left + (right-left)/3*2;

        if(distance(midl) > distance(midr)){
            left = midl;
        }else{
            right = midr;
        }

    }
    cout << fixed << setprecision(10) << pow(distance((left+right)/2),0.5);
}