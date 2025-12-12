#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
double pos[51][2];
double vel[51][2];

double getL(double time){
    double L = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double posx1 = pos[i][0] + vel[i][0]*time;
            double posy1 = pos[i][1] + vel[i][1]*time;
            double posx2 = pos[j][0] + vel[j][0]*time;
            double posy2 = pos[j][1] + vel[j][1]*time;
            L = max(L, abs(posx1-posx2));
            L = max(L, abs(posy1-posy2));
        }
    }
    return L;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> pos[i][0] >> pos[i][1];
        cin >> vel[i][0] >> vel[i][1];
    }

    double left = 0;
    double right =5000;
    for(int i=0;i<200;i++){
        double midl = left + (right-left)/3;
        double midr = left + (right-left)/3*2;
        if(getL(midl) < getL(midr)){
            right = midr;
        }else{
            left = midl;
        }
    }
    cout << fixed << setprecision(15) << getL((left+right)/2);
}