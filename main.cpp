//
//  main.cpp
//  homework3
//
//  Created by Y P on 2018/05/09.
//  Copyright © 2018年 Y P. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

//array
float lightPosition[4] = {5.25, 2.0, 0.25, 1.0}; //x,y,z,w
float ambientColor[4] = {0.43,0.40,0.33, 1.0}; //r,g,b,a  //dosei no iro wo tyuusyutu simasita
float diffuseColor[4] = {1.0, 1.0, 1.0, 1.0}; //r,g,b,a
float specularColor[4] = {1.0, 1.0, 1.0, 1.0}; //r,g,b,a
float shininess = 5.0; //0-120

float rotation = 0.0;

void reshape(int width, int height){
    glViewport(0, 0, width, height); //viewport = screen
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //initialize projection matrix
    gluPerspective(45, width/height, 0.1, 100);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //initialize
    gluLookAt(-0.5, 2.1, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glPushMatrix();
    glRotatef(rotation, rotation,1,rotation);
    glutSolidSphere(0.4, 100, 100);
    glutWireCone(0.8, 0.0, 1000, 100);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(rotation, 0,1,1);
    glutWireTorus(0.01,0.5,10,1000);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(rotation, 0,1,0);
    glutWireTorus(0.01,0.6,10,1000);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(rotation, rotation,1,1);
    glutWireTorus(0.01,0.7,10,1000);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(rotation, 0,1,1);
    glutWireTorus(0.01,0.8,10,1000);
    glPopMatrix();
    

    
    glutSwapBuffers();
    
    
}

void animation(){
    rotation = rotation + 1;
    if(rotation >= 360.0) rotation = 0.0;
    
    glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    
    glutCreateWindow("gp-3d");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    glutIdleFunc(animation);
    
    
    //light and material
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); //Enable smooth shading
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ambientColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ambientColor);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    
    
    glutMainLoop();
    return 0;
}
