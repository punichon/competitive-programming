#include<iostream>
#include<cstdio>
using namespace std;

string deg_ans(int wind){//風向

    int deg = wind * 10;

    if(deg >= 1125 && deg < 3375){
        return "NNE";
    }else if(deg >= 3375 && deg < 5625){
        return "NE";
    }else if(deg >= 5625 && deg < 7875){
        return "ENE";
    }else if(deg >= 7825 && deg < 10125){
        return "E";
    }else if(deg >= 10125 && deg < 12375){
        return "ESE";
    }else if(deg >= 12375 && deg < 14625){
        return "SE";
    }else if(deg >= 14625 && deg < 16875){
        return "SSE";
    }else if(deg >= 16875 && deg < 19125){
        return "S";
    }else if(deg >= 19125 && deg < 21375){
        return "SSW";
    }else if(deg >= 21375 && deg < 23625){
        return "SW";
    }else if(deg >= 23625 && deg < 25875){
        return "WSW";
    }else if(deg >= 25875 && deg < 28125){
        return "W";
    }else if(deg >= 28125 && deg < 30375){
        return "WNW";
    }else if(deg >= 30375 && deg < 32625){
        return "NW";
    }else if(deg >= 32625 && deg < 34875){
        return "NNW";
    }else{
        return "N";
    }
}

int Dis_ans(double dis){

    if(dis >= 0 && dis <= 0.2){
        return 0;
    }if(dis >= 0.3 && dis <= 1.5){
        return 1;
    }if(dis >= 1.6 && dis <= 3.3){
        return 2;
    }if(dis >= 3.4 && dis <= 5.4){
        return 3;
    }if(dis >= 5.5 && dis <= 7.9){
        return 4;
    }if(dis >= 8.0 && dis <= 10.7){
        return 5;
    }if(dis >= 10.8 && dis <= 13.8){
        return 6;
    }if(dis >= 13.9 && dis <= 17.1){
        return 7;
    }if(dis >= 17.2 && dis <= 20.7){
        return 8;
    }if(dis >= 20.8 && dis <= 24.4){
        return 9;
    }if(dis >= 24.5 && dis <= 28.4){
        return 10;
    }if(dis >= 28.5 && dis <= 32.6){
        return 11;
    }if(dis >= 32.7){
        return 12;
    }


}

int main(){

    int deg,dis;

    cin >> deg >> dis;

    double tmp = ((double)(dis)) / 60;
    
    tmp *= 10;
    tmp += 0.5;
    tmp =int(tmp);
    tmp /= 10;

    string Dir = deg_ans(deg);
    int W = Dis_ans(tmp);
    if(W == 0){
        Dir = "C";
    }

    cout << Dir << " " << W << endl;

    return 0;
}
