//
//  main.cpp
//  lab01
//
//  Created by 제갈수민 on 2017. 9. 26..
//  Copyright © 2017년 제갈수민. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1f, 0.245f, 0.362f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Drawing Example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
