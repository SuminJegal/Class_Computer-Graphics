//
//  main.cpp
//  lab06
//
//  Created by 제갈수민 on 2017. 11. 16..
//  Copyright © 2017년 제갈수민. All rights reserved.
//


#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>


double rotationSun = 0.0; //자전
double rotationMercury = 0;
double rotationVenus = 0;
double rotationEarth = 0;
double rotationMars = 0;
double rotationJupiter = 0;
double rotationSaturn = 0;
double rotationUranus = 0;
double rotationNeptune = 0;

double revolutionMercury = 0; //공전
double revolutionVenus = 0;
double revolutionEarth = 0;
double revolutionMars = 0;
double revolutionJupiter = 0;
double revolutionSaturn = 0;
double revolutionUranus = 0;
double revolutionNeptune = 0;

double revolutionMoon = 0; //위성
double revolutionEuropa = 0;
double revolutionIO = 0;
double rotationMoon = 0;
double rotationEuropa = 0;
double rotationIO = 0;

double camera_look[3] = {0, 40, 70};

void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void animate();

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1280, 960);
    glutCreateWindow("Lab 06");
    
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0, 1.0, 1.0);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera_look[0], camera_look[1], camera_look[2], 0, 0, 0, 0, 1, 0);

//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    //태양
    glPushMatrix();
    
    GLfloat ambient0[] = {0.2, 0.2, 0.2, 1.0}; //0.1-0.2가 딱 적당. 주변광
    GLfloat diffuse0[] = {1.0, 0.9, 0.6, 1.0}; //물체의 색 표현. RGB. 0.0-1.0까지로 표현
    GLfloat specular0[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light0_pos[] = {0.0, 0.0, 0.0, 1.0};
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
    
    GLfloat emission_light[] = {1.0, (128.0/255.0), 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_light);
    
    glRotated(rotationSun, 0, 0, 1);
    glutSolidSphere(7, 100, 100);
    glPopMatrix();
    
    
    //수성
    glPushMatrix();
//    glColor3f(145.0/256, 152/256, 77/256);
//    glColor3f(0.011f, 0.825f, 0.562f);
    GLfloat ambient1[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse1[] = {(145.0/256.0), (162.0/256.0), (71.0/256.0)};
    GLfloat specular1[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat shine = 128.0; //128이 최대

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

    GLfloat emission_material[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_material);
    
    glRotatef(revolutionMercury, 0, 1, 0);
    glTranslatef(9.38, 0, 0);
    glRotatef(rotationMercury, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    
    glutSolidSphere(0.38, 100, 100);
    glPopMatrix();
    
    //금성
    glPushMatrix();
    
//    glColor3f(220/256, 152/256, 31/256);
    GLfloat ambient2[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse2[] = {(220.0/256.0), (152.0/256.0), (31.0/256.0)};
    GLfloat specular2[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glRotatef(revolutionVenus, 0, 1, 0);
    glTranslatef(12.7, 0, 0);
    glRotatef(rotationVenus, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    
    glutSolidSphere(0.95, 100, 100);
    glPopMatrix();
    
    //지구
    glPushMatrix();
    
    GLfloat ambient3[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse3[] = {0.1, 0.8, 0.9, 1.0};
    GLfloat specular3[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;

    glRotatef(revolutionEarth, 0, 1, 0);
    glTranslatef(16, 0, 0);
    
    //달
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
        glMaterialf(GL_FRONT, GL_SHININESS, shine);
        glRotatef(revolutionMoon, 0, 1, 0);
        glTranslatef(1.5, 0, 0);
        glRotatef(rotationMoon, 0, 0, 1.0);
        glRotatef(6, 0, 0, 1);
        glutSolidSphere(0.2, 100, 100);
    glPopMatrix();
    //
    
    glRotatef(rotationEarth, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular3);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glutSolidSphere(0.95, 100, 100);
    glPopMatrix();
    
    
    //화성
    glPushMatrix();
    
    GLfloat ambient4[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse4[] = {(153.0/256.0), (30.0/256.0), (30.0/256.0)};
    GLfloat specular4[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse4);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular4);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glRotatef(revolutionMars, 0, 1, 0);
    glTranslatef(19, 0, 0);
    glRotatef(rotationMars, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glutSolidSphere(0.98, 100, 100);
    glPopMatrix();
    
    
    //목성
    glPushMatrix();
    
    GLfloat ambient5[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse5[] = {(188.0/256.0), (162.0/256.0), (90.0/256.0)};
    GLfloat specular5[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;
    
    glRotatef(revolutionJupiter, 0, 1, 0);
    glTranslatef(25, 0, 0);
    
    //유로파
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
        glMaterialf(GL_FRONT, GL_SHININESS, shine);
        glRotatef(revolutionEuropa, 0, 1, 0);
        glTranslatef(6, 2, 0);
        glRotatef(rotationEuropa, 0, 0, 1.0);
        glRotatef(15, 0, 0, 1);
        glutSolidSphere(0.6, 100, 100);
    glPopMatrix();
    //
    
    //이오
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
        glMaterialf(GL_FRONT, GL_SHININESS, shine);
        glRotatef(revolutionIO, 0, 1, 0);
        glTranslatef(5, 0, 0);
        glRotatef(rotationIO, 0, 0, 1.0);
        glRotatef(10, 0, 0, 1);
        glutSolidSphere(0.8, 100, 100);
    glPopMatrix();
    //
    
    
    glRotatef(rotationJupiter, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient5);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse5);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular5);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    glutSolidSphere(3.5, 100, 100);
    glPopMatrix();
    
    
    //토성
    glPushMatrix();
    
    GLfloat ambient6[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse6[] = {(203.0/256.0), (102.0/256.0), (10.0/256.0)};
    GLfloat specular6[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient6);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse6);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular6);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glRotatef(revolutionSaturn, 0, 1, 0);
    glTranslatef(33, 0, 0);
    glRotatef(rotationSaturn, 0, 0, 1.0);
    glRotatef(0.3, 0, 0, 1.0);
    
    //고리
    //    glPushMatrix();
    GLUquadricObj *obj = gluNewQuadric();
    gluQuadricNormals(obj, GLU_SMOOTH);
    gluDisk(obj, 2.4, 4.7, 14, 80);
    //    glPopMatrix();
    
    glutSolidSphere(2.2, 100, 100);
    glPopMatrix();
    
    
    //천왕성
    glPushMatrix();
    
    GLfloat ambient7[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse7[] = {(103.0/256.0), (217.0/256.0), (230.0/256.0)};
    GLfloat specular7[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient7);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse7);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular7);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glRotatef(revolutionUranus, 0, 1, 0);
    glTranslatef(36.2, 0, 0);
    glRotatef(rotationUranus, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glutSolidSphere(1.8, 100, 100);
    glPopMatrix();
    
    
    //해왕성
    glPushMatrix();
    
    GLfloat ambient8[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse8[] = {(15.0/256.0), (83.0/256.0), (171.0/256.0)};
    GLfloat specular8[] = {1.0, 1.0, 1.0, 1.0};
    shine = 128.0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient8);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse8);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular8);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
    
    glRotatef(revolutionNeptune, 0, 1, 0);
    glTranslatef(40, 0, 0);
    glRotatef(rotationNeptune, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glutSolidSphere(1.3, 100, 100);
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape(int w, int h){
    float ratio = w/(float)h;
    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 10, 100);
}

void animate(){
    //행성 자전
    rotationSun = rotationSun + 0.09;
    rotationSun = rotationSun >= 360 ? rotationSun-360 : rotationSun;
    rotationMercury = rotationMercury + 0.8;
    rotationMercury = rotationMercury >= 360 ? rotationMercury-360 : rotationMercury;
    rotationVenus = rotationVenus + 0.7;
    rotationVenus = rotationVenus >= 360 ? rotationVenus-360 : rotationVenus;
    rotationEarth = rotationEarth + 1;
    rotationEarth = rotationEarth >= 360 ? rotationEarth-360 : rotationEarth;
    rotationMars = rotationMars + 0.99;
    rotationMars = rotationMars >= 360 ? rotationMars-360 : rotationMars;
    rotationJupiter = rotationJupiter + 9;
    rotationJupiter = rotationJupiter >= 360 ? rotationJupiter-360 : rotationJupiter;
    rotationSaturn = rotationSaturn + 10;
    rotationSaturn = rotationSaturn >= 360 ? rotationSaturn-360 : rotationSaturn;
    rotationUranus = rotationUranus + 11;
    rotationUranus = rotationUranus >= 360 ? rotationUranus-360 : rotationUranus;
    rotationNeptune = rotationNeptune + 12;
    rotationNeptune = rotationNeptune >= 360 ? rotationNeptune-360 : rotationNeptune;
    
    //행성 공전
    revolutionMercury = revolutionMercury + 4.14;
    revolutionMercury = revolutionMercury >=360 ? revolutionMercury-360 : revolutionMercury;
    revolutionVenus = revolutionVenus + 1.66;
    revolutionVenus = revolutionVenus >=360 ? revolutionVenus-360 : revolutionVenus;
    revolutionEarth = revolutionEarth + 1;
    revolutionEarth = revolutionEarth >=360 ? revolutionEarth-360 : revolutionEarth;
    revolutionMars = revolutionMars + 0.53;
    revolutionMars = revolutionMars >=360 ? revolutionMars-360 : revolutionMars;
    revolutionJupiter = revolutionJupiter + 0.08;
    revolutionJupiter = revolutionJupiter >=360 ? revolutionJupiter-360 : revolutionJupiter;
    revolutionSaturn = revolutionSaturn + 0.03;
    revolutionSaturn = revolutionSaturn >=360 ? revolutionSaturn-360 : revolutionSaturn;
    revolutionUranus = revolutionUranus + 0.011;
    revolutionUranus = revolutionUranus >=360 ? revolutionUranus-360 : revolutionUranus;
    revolutionNeptune = revolutionNeptune + 0.006;
    revolutionNeptune = revolutionNeptune >=360 ? revolutionNeptune-360 : revolutionNeptune;
    
    //위성 자전
    rotationMoon = rotationMoon + 13;
    rotationMoon = rotationMoon >= 360 ? rotationMoon-360 : rotationMoon;
    rotationEuropa = rotationEuropa + 3;
    rotationEuropa = rotationEuropa >= 360 ? rotationEuropa-360 : rotationEuropa;
    rotationIO = rotationIO + 4;
    rotationIO = rotationIO >= 360 ? rotationIO-360 : rotationIO;
    
    //위성 공전
    revolutionMoon = revolutionMoon + 13;
    revolutionMoon = revolutionMoon >=360 ? revolutionMoon-360 : revolutionMoon;
    revolutionEuropa = revolutionEuropa + 1;
    revolutionEuropa = revolutionEuropa >=360 ? revolutionEuropa-360 : revolutionEuropa;
    revolutionIO = revolutionIO + 2;
    revolutionIO = revolutionIO >=360 ? revolutionIO-360 : revolutionIO;
    
    
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'i' : //up
            camera_look[1] +=1;
            break;
        case 'k' : //down
            camera_look[1] -=1;
            break;
        case 'j': //left
            camera_look[0] -=1;
            break;
        case 'l': //right
            camera_look[0] +=1;
            break;
        case 'u' : //close
            camera_look[2] -=1;
            break;
        case 'o': //far
            camera_look[2] +=1;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}





