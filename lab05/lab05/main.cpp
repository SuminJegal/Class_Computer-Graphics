//
//  main.cpp
//  lab05
//
//  Created by 제갈수민 on 2017. 10. 31..
//  Copyright © 2017년 제갈수민. All rights reserved.
//

#include <iostream>

using namespace std;

#define AMB 1
#define DIFF 2
#define SPEC 3
#define EMI 4
#define POS 5

struct Light{
    double ambient[4]; //r, g, b, a
    double diffuse[4];
    double specular[4];
};

struct Light light[8];

void mySetLight(int id, string prop, double coef[]);
void myAmbient(int id, double coef[]);
void myDiffuse(int id, double coef[]);
void mySpecualr(int id, double coef[]);
double myAttenuation(double ka, double kb, double kc, double distance); //거리에 따른 빛 감소 효과
void myLighting(int id);


int main(int argc, const char * argv[]) {

    return 0;
}

void mySetLight(int id, int prop, double coef[]){
    switch (prop) {
        case 1:
            myAmbient(id, coef);
            break;
        case 2:
            myDiffuse(id, coef);
            break;
        case 3:
            mySpecualr(id, coef);
            break;
            
        default:
            break;
    }
}

void myAmbient(int id, double coef[]){
    for(int i=0; i<4; i++){
        light[id].ambient[i] = coef[i];
    }
}

void myDiffuse(int id, double coef[]){
    for(int i=0; i<4; i++){
        light[id].diffuse[i] = coef[i];
    }
}

void mySpecualr(int id, double coef[]){
    for(int i=0; i<4; i++){
        light[id].specular[i] = coef[i];
    }
}

double myAttenuation(double ka, double kb, double kc, double distance){
    return 1/(ka + (kb * distance) + (kc * distance * distance));
}

void myLighting(int id){
    
}
