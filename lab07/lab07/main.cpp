//
//  main.cpp
//  lab07
//
//  Created by 제갈수민 on 2017. 11. 21..
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

double camera_look[3] = {0, 40, 50};

void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void animate();
GLuint loadRawTexture(const char * filename, int width, int height);

GLuint texture[13];

GLUquadricObj *sun, *mercury, *venus, *earth, *moon, *mars, *jupyter, *io, *europa, *satern, *uranus, *neptune;
GLUquadricObj *obj;

GLuint loadRawTexture(const char * filename, int width, int height){

    GLuint text;
    unsigned char * data;
    FILE * file;
    // open texture data
    file = fopen( filename, "rb" );
    if ( file == 0 ){
        printf("%s load fail\n",filename);
        return 0;
    }
    // allocate buffer
    printf("%s load success\n", filename);
    data = (unsigned char *)malloc( width * height * 3 );
    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );
    
    for(int i = 0; i < width * height ; ++i){
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];
        data[index] = R;
        data[index+2] = B;
    }
    
    glGenTextures(1, &text);
    glBindTexture(GL_TEXTURE_2D, text);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );
    return text;
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1280, 960);
    glutCreateWindow("Lab 07");
    
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    //Load texture
    sun = gluNewQuadric();
    mercury = gluNewQuadric();
    venus = gluNewQuadric();
    earth = gluNewQuadric();
    moon = gluNewQuadric();
    mars = gluNewQuadric();
    jupyter = gluNewQuadric();
    io = gluNewQuadric();
    europa = gluNewQuadric();
    satern = gluNewQuadric();
    uranus = gluNewQuadric();
    neptune = gluNewQuadric();
    obj = gluNewQuadric();
    gluQuadricTexture(sun, GL_TRUE);
    gluQuadricTexture(mercury, GL_TRUE);
    gluQuadricTexture(venus, GL_TRUE);
    gluQuadricTexture(earth, GL_TRUE);
    gluQuadricTexture(moon, GL_TRUE);
    gluQuadricTexture(mars, GL_TRUE);
    gluQuadricTexture(jupyter, GL_TRUE);
    gluQuadricTexture(io, GL_TRUE);
    gluQuadricTexture(europa, GL_TRUE);
    gluQuadricTexture(satern, GL_TRUE);
    gluQuadricTexture(uranus, GL_TRUE);
    gluQuadricTexture(neptune, GL_TRUE);
    gluQuadricTexture(obj, GL_TRUE);
    texture[0] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/sun.bmp", 1024, 574);
    texture[1] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/mercury.bmp", 1024, 512);
    texture[2] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/venus.bmp", 2500, 1250);
    texture[3] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/earth.bmp", 2048, 1024);
    texture[4] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/moon.bmp", 1024, 512);
    texture[5] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/mars.bmp", 1960, 988);
    texture[6] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/jupiter.bmp", 1024, 512);
    texture[7] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/io.bmp", 2048, 1024);
    texture[8] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/europa.bmp", 1024, 512);
    texture[9] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/saturn.bmp", 1024, 512);
    texture[10] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/uranus.bmp", 1024, 512);
    texture[11] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/neptune.bmp", 1024, 512);
    texture[12] = loadRawTexture("/Users/jegalsumin/Documents/Class_Computer-Graphics/lab07/lab07/ring.bmp", 1024, 2048);
    
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

    glEnable(GL_TEXTURE_2D);

    //태양
    glPushMatrix();
    GLfloat ambient0[] = {1.0f, 1.0f, 1.0f, 1.0f}; //0.1-0.2가 딱 적당. 주변광
    GLfloat diffuse0[] = {1.0f, 1.0f, 1.0f, 1.0f}; //물체의 색 표현. RGB. 0.0-1.0까지로 표현
    GLfloat specular0[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light0_pos[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

    GLfloat emission_light[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_light);
    glEnable(GL_LIGHT0);
    
    glRotated(rotationSun, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[0]); // get ready to use my texture
    gluSphere(sun, 7, 100, 100);
    glPopMatrix();
    
    
    //수성
    glPushMatrix();
    GLfloat emission_material[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_material);
    
    glRotatef(revolutionMercury, 0, 1, 0);
    glTranslatef(9.38, 0, 0);
    glRotatef(rotationMercury, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    
    glBindTexture(GL_TEXTURE_2D, texture[1]); // get ready to use my texture
    gluSphere(mercury,0.38, 100, 100);
    glPopMatrix();
    
    //금성
    glPushMatrix();
    glRotatef(revolutionVenus, 0, 1, 0);
    glTranslatef(12.7, 0, 0);
    glRotatef(rotationVenus, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[2]); // get ready to use my texture
    gluSphere(venus, 0.95, 100, 100);
    glPopMatrix();
    
    //지구
    glPushMatrix();
    glRotatef(revolutionEarth, 0, 1, 0);
    glTranslatef(16, 0, 0);
    
    //달
    glPushMatrix();
    glRotatef(revolutionMoon, 0, 1, 0);
    glTranslatef(1.5, 0, 0);
    glRotatef(rotationMoon, 0, 0, 1.0);
    glRotatef(6, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[4]); // get ready to use my texture
    gluSphere(moon, 0.2, 100, 100);
    glPopMatrix();
    //
    
    glRotatef(rotationEarth, 0, 0, 1.0);
    glRotatef(0.01, 0, 0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[3]); // get ready to use my texture
    gluSphere(earth, 1.0, 100, 100);
    glPopMatrix();
    
    
    //화성
    glPushMatrix();
    
    glRotatef(revolutionMars, 0, 1, 0);
    glTranslatef(19, 0, 0);
    glRotatef(rotationMars, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glBindTexture(GL_TEXTURE_2D, texture[5]); // get ready to use my texture
    gluSphere(mars, 0.98, 100, 100);
    glPopMatrix();
    
    
    //목성
    glPushMatrix();
    glRotatef(revolutionJupiter, 0, 1, 0);
    glTranslatef(25, 0, 0);
    
    //유로파
    glPushMatrix();
    glRotatef(revolutionEuropa, 0, 1, 0);
    glTranslatef(6, 2, 0);
    glRotatef(rotationEuropa, 0, 0, 1.0);
    glRotatef(15, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[8]); // get ready to use my texture
    gluSphere(europa, 0.6, 100, 100);
    glPopMatrix();
    //
    
    //이오
    glPushMatrix();
    glRotatef(revolutionIO, 0, 1, 0);
    glTranslatef(5, 0, 0);
    glRotatef(rotationIO, 0, 0, 1.0);
    glRotatef(10, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[7]); // get ready to use my texture
    gluSphere(io, 0.8, 100, 100);
    glPopMatrix();
    //
    
    
    glRotatef(rotationJupiter, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[6]); // get ready to use my texture
    gluSphere(jupyter, 3.6, 100, 100);
    glPopMatrix();
    
    
    //토성
    glPushMatrix();
    
    glRotatef(revolutionSaturn, 0, 1, 0);
    glTranslatef(33, 0, 0);
    glRotatef(rotationSaturn, 0, 0, 1.0);
    glRotatef(0.3, 0, 0, 1.0);
    
    //고리
    glPushMatrix();
    gluQuadricNormals(obj, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glRotatef(30, 0, 0, 1.0);
    gluDisk(obj, 2.4, 3.9, 10, 8);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, texture[9]); // get ready to use my texture
    gluSphere(satern, 2.2, 100, 100);
    glPopMatrix();
    
    
    //천왕성
    glPushMatrix();
    
    glRotatef(revolutionUranus, 0, 1, 0);
    glTranslatef(36.2, 0, 0);
    glRotatef(rotationUranus, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glBindTexture(GL_TEXTURE_2D, texture[10]); // get ready to use my texture
    gluSphere(uranus, 1.8, 100, 100);
    glPopMatrix();
    
    
    //해왕성
    glPushMatrix();
    
    glRotatef(revolutionNeptune, 0, 1, 0);
    glTranslatef(40, 0, 0);
    glRotatef(rotationNeptune, 0, 0, 1.0);
    glRotatef(0.2, 0, 0, 1.0);
    
    glBindTexture(GL_TEXTURE_2D, texture[11]); // get ready to use my texture
    gluSphere(neptune, 1.3, 100, 100);
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

