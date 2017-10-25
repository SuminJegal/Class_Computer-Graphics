//
//  main.cpp
//  lab03
//
//  Created by 제갈수민 on 2017. 10. 17..
//  Copyright © 2017년 제갈수민. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Matrix {
    double num[4][4];
};

struct Vertex {
    double num[4];
};

vector<struct Matrix> projection_stack, modelview_stack;
#define PROJECTION  1
#define MODELVIEW   2

vector<struct Matrix> stack = modelview_stack;

void mySetMatrixMode(int i); // set matrix mode: modelview mode or projection mode
void myLoadIdentity(); // load identity matrix to current matrix stack
void myPushMatrix(); // push into current matrix stack
void myPopMatrix(); // pop from current matrix stack
void myMatrixMul(struct Matrix m); // multiply a matrix m with current stack top & replace top with the result
struct Vertex myRunMatrix(struct Vertex v); // multiply a vertex v with current stack top
void myTranslateX(double d);
void myTranslateY(double d);
void myTranslateZ(double d);
void myRotateX(double r); // set matrix for translation in x-axis by 'd' & multiply with current stack top
void myRotateY(double r); // set matrix for rotation around y-axis by 'r' degree & multiply with current stack top
void myRotateZ(double r); // set matrix for rotation around z-axis by 'r' degree & multiply with current stack top
void myScaleX(double s); // set matrix for scaling in x-axis by 's' & multiply with current stack top
void myScaleY(double s); // set matrix for scaling in x-axis by 's' & multiply with current stack top
void myScaleZ(double s); // set matrix for scaling in x-axis by 's' & multiply with current stack top
void printM(struct Matrix m);
void printS();
void printV(struct Vertex v);


int main(int argc, const char * argv[]) {
    
    mySetMatrixMode(MODELVIEW);
    
    myLoadIdentity();
    myPushMatrix();
    
    myTranslateX(5);
    myTranslateY(5);
    myTranslateZ(5);
    myRotateZ(3);
    myScaleY(2);
    
    struct Vertex v = {1,2,3,1};
    myRunMatrix(v);
    
    
    return 0;
}

void mySetMatrixMode(int i){
    if(i==1)
        stack = projection_stack;
    else
        stack = modelview_stack;
}
void myLoadIdentity(){
    struct Matrix ident_matrix = {1,0,0,0,  0,1,0,0,  0,0,1,0,  0,0,0,1};
    stack.push_back(ident_matrix);
    printf("Load Identity Matrix\n");
    printS();
}
void myPushMatrix(){
    stack.push_back(stack.back());
    printf("Push Matrix top\n");
    printS();
}
void myPopMatrix(){
    stack.pop_back();
    printS();
}
void myMatrixMul(struct Matrix m){
    struct Matrix top = stack.back();
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            double tmp = 0;
            for(int k=0; k<4; k++){
                tmp = tmp + (top.num[i][k] * m.num[k][j]);
            }
            stack[stack.size()-1].num[i][j] = tmp;
        }
    }
    printS();
}
struct Vertex myRunMatrix(struct Vertex v){
    struct Matrix top = stack.back();
    struct Vertex result;
    for(int i=0; i<4; i++){
        double tmp = 0;
        for(int j=0; j<4; j++){
            tmp = tmp + (top.num[i][j] * v.num[j]);
        }
        result.num[i] = tmp;
    }
    printV(result);
    myPopMatrix();
    return result;
}
void myTranslateX(double d){
    struct Matrix transX = {1,0,0,d,  0,1,0,0,  0,0,1,0,  0,0,0,1};
    printf("Translate x\n");
    myMatrixMul(transX);
}
void myTranslateY(double d){
    struct Matrix transY = {1,0,0,0,  0,1,0,d,  0,0,1,0,  0,0,0,1};
    printf("Translate y\n");
    myMatrixMul(transY);
}
void myTranslateZ(double d){
    struct Matrix transZ = {1,0,0,0,  0,1,0,0,  0,0,1,d,  0,0,0,1};
    printf("Translate z\n");
    myMatrixMul(transZ);
}
void myRotateX(double r){
    struct Matrix rotateX = {1,0,0,0,  0,cos(r),(sin(r)*-1),0,  0,sin(r),cos(r),0,  0,0,0,1};
    printf("Rotate x\n");
    myMatrixMul(rotateX);
}
void myRotateY(double r){
    struct Matrix rotateY = {cos(r),(sin(r)*-1),0,0,  sin(r),cos(r),0,0,  0,0,1,0,  0,0,0,1};
    printf("Rotate y\n");
    myMatrixMul(rotateY);
}
void myRotateZ(double r){
    struct Matrix rotateR = {cos(r),0,sin(r),0,  0,1,0,0,  (sin(r)*-1),0,cos(r),0,  0,0,0,1};
    printf("Rotate z\n");
    myMatrixMul(rotateR);
}
void myScaleX(double s){
    struct Matrix scaleX = {s,0,0,0,  0,1,0,0,  0,0,1,0,  0,0,0,1};
    printf("Scale x\n");
    myMatrixMul(scaleX);
}
void myScaleY(double s){
    struct Matrix scaleY = {1,0,0,0,  0,s,0,0,  0,0,1,0,  0,0,0,1};
    printf("Scale y\n");
    myMatrixMul(scaleY);
}
void myScaleZ(double s){
    struct Matrix scaleZ = {1,0,0,0,  0,1,0,0,  0,0,s,0,  0,0,0,1};
    printf("Scale z\n");
    myMatrixMul(scaleZ);
}

void printM(struct Matrix m){
    for(int i=0; i<4; i++){
        printf("%.2lf %.2lf %.2lf %.2lf\n", m.num[i][0], m.num[i][1], m.num[i][2], m.num[i][3]);
    }
}

void printS(){
    printf("====================================\n");
    for(int i=0; i<stack.size(); i++){
        printf("------------------------------------\n");
        printM(stack[i]);
        printf("\n");
    }
    printf("\n\n\n");
}

void printV(struct Vertex v){
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%.2lf %.2lf %.2lf %.2lf\n", v.num[0], v.num[1], v.num[2], v.num[3]);
    printf("++++++++++++++++++++++++++++++++++++\n");
}









