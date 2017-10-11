//
//  main.cpp
//  lab02
//
//  Created by 제갈수민 on 2017. 10. 10..
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
//    gluLookAt(<#GLdouble eyeX#>, <#GLdouble eyeY#>, <#GLdouble eyeZ#>, <#GLdouble centerX#>, <#GLdouble centerY#>, <#GLdouble centerZ#>, <#GLdouble upX#>, <#GLdouble upY#>, <#GLdouble upZ#>)
    
    glutWireSphere(0.5, 10, 10);
    
    glRotatef(-45, 0, 0, 1.0);
    glTranslatef(0, 5, 0);
    glRotatef(45, 0, 0, 1.0);
    glScalef(2, 2, 1);

    glutWireSphere(0.5, 10, 10);
    
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
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("test");
    
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
