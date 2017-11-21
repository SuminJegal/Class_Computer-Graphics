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
    double phong[4];
    double ambient[4]; //r, g, b, a
    double diffuse[4];
    double specular[4];
};

struct Light light[8];

void mySetLight(int id, int prop, double coef[]);
void myAmbient(int id, double coef[]);
void myDiffuse(int id, double coef[]);
void mySpecualr(int id, double coef[]);
double myAttenuation(double ka, double kb, double kc, double distance); //거리에 따른 빛 감소 효과
void myLighting(int id, int l[], int n[], int r[], int v[]);


int main(int argc, const char * argv[]) {
    int l[4] = {0,1,1,0};
    int v[4] = {0,0,1,0};
    int n[4] = {0,0,1,0};
    
    int r[4];
    for(int i=0; i<4; i++){
        r[i] = 2*(l[0]*n[0] + l[1]*n[1] + l[2]*n[2] + l[3]*n[3])*n[i] + l[i];
    }
    
    double ambient[4] = {0.2, 0.2, 0.2, 1.0};
    double diffuse[4] = {1.0, 0.8, 0.0, 1.0};
    double specular[4] = {0.5, 0.5, 0.5, 1.0};
    
    mySetLight(0, AMB, ambient);
    mySetLight(0, DIFF, diffuse);
    mySetLight(0, SPEC, specular);

    myLighting(0, l, n, r, v);
    
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

void myLighting(int id, int l[4], int n[4], int r[4], int v[4]){
    double l_dot_n = l[0]*n[0] + l[1]*n[1] + l[2]*n[2] + l[3]*n[3];
    double r_dot_v = r[0]*v[0] + r[1]*v[1] + r[2]*v[2] + r[3]*v[3];
    for(int i=0; i<4; i++){
        double attenuation = myAttenuation(0, 0, 1, 10);
        light[id].phong[i] = light[id].ambient[i] +
                attenuation*light[id].diffuse[i]*l_dot_n + attenuation*light[id].specular[i]*r_dot_v;
    }
    
    printf("Light %d : r = %.2lf, g = %.2lf, b = %.2lf\n", id, light[id].phong[0], light[id].phong[1], light[id].phong[2]);
}









