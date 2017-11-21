//
//  main.cpp
//  lab04
//
//  Created by 제갈수민 on 2017. 10. 24..
//  Copyright © 2017년 제갈수민. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>


void display(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
    
    glPushMatrix();
    
    GLfloat ambient0[] = {0.2, 0.2, 0.2, 1.0}; //0.1-0.2가 딱 적당. 추변광
    GLfloat diffuse0[] = {1.0, 0.9, 0.6, 1.0}; //물체의 색 표현. RGB. 0.0-1.0까지로 표현
    GLfloat specular0[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light0_pos[] = {0.0, 0.0, 0.0, 1.0};
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
    
    GLfloat emission_light[] = {1.0, 0.8, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_light);
    
    glScalef(2, 2, 1);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
   
    //1번째 행성
    glPushMatrix();
    GLfloat ambient1[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse1[] = {1.0, 0.8, 0.0, 1.0};
    GLfloat specular1[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat shine1 = 100.0; //128이 최대
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialf(GL_FRONT, GL_SHININESS, shine1);
    
    GLfloat emission_material1[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_material1);
    
    glRotatef(45, 0, 0, 1.0);
    glTranslatef(0, 3, 0);
    glRotatef(-45, 0, 0, 1.0);
    
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
    //2번째 행성
    glPushMatrix();
    GLfloat ambient2[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse2[] = {0.8, 0.8, 0.3, 1.0};
    GLfloat specular2[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shine2 = 128.0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
    glMaterialf(GL_FRONT, GL_SHININESS, shine2);
    
    GLfloat emission_material2[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_material2);
    
    glRotatef(-45, 0, 0, 1.0);
    glTranslatef(0, 1.2, -2);
    glRotatef(45, 0, 0, 1.0);
    
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
    glFlush();
}

void reshape(int w, int h){
    float ratio = w/(float)h;
    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 10, 100);
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("test");
    
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

