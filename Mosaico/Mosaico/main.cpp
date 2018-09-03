//
//  Created by Andrea Marín Alarcón on 30/08/18.
//  Copyright © 2018 Andrea Marín Alarcón. All rights reserved.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void init(void) {
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,101,0.0,101);
}

void circulos(int radius){
    float x = 0 ,y = 0;
    
    // línea "punteada"
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(4, 0xBBBB);
    glEnable(GL_LINE_STIPPLE);
    
    // grosor de línea
    glLineWidth(20.0);
    
    //círculo arriba derecha
    glBegin(GL_LINE_LOOP);
    for (double i = 0; i < 2 * M_PI; i += M_PI / 40){
        x = 100 - cos(i) * radius;
        y = 100 - sin(i) * radius;
        
        if(x >= 49.5 and y >= 49.5)
            glColor3f(0.184, 0.455, 0.729);
        else
            glColor3f(1.0,1.0,1.0);
        
        glVertex2f(x, y);
    }
    glEnd();
    
    
    //círculo abajo izquierda
    glBegin(GL_LINE_LOOP);
    for (double i = 0; i < 2 * M_PI; i += M_PI / 40){
        x = cos(i) * radius;
        y = sin(i) * radius;
        
        if(x <= 49.5 and y <= 49.5)
            glColor3f(0.184, 0.455, 0.729);
        else
            glColor3f(1.0,1.0,1.0);
        
        glVertex2f(x, y);
    }
    glEnd();
    
    glColor3f(0.184, 0.455, 0.729);
    
    //círculo arriba izquierda
    glBegin(GL_LINE_LOOP);
    for (double i = 0; i < 2 * M_PI; i += M_PI / 40){
        x = cos(i) * radius;
        y = 100 - sin(i) * radius;
        
        if(x <= 49.5 and y >= 49.5)
            glColor3f(0.184, 0.455, 0.729);
        else
            glColor3f(1.0,1.0,1.0);
        
        glVertex2f(x,y);
    }
    glEnd();
    
    //círculo abajo derecha
    glBegin(GL_LINE_LOOP);
    for (double i = 0; i < 2 * M_PI; i += M_PI / 40){
        x = 100 - cos(i) * radius;
        y = sin(i) * radius;
        
        if(x >= 49.5 and y <= 49.5)
            glColor3f(0.184, 0.455, 0.729);
        else
            glColor3f(1.0,1.0,1.0);
        
        glVertex2f(x,y);
    }
    glEnd();

    glPopAttrib();

}

void lineSegment(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.184, 0.455, 0.729);
    
// ----------------------------------------------------------------- CIRCULOS -----------------------------------------------------------------------------------------------------------------------
    
    for(int r = 80; r >=50; r-=1)
        circulos(r);
    
    
    
//--------------------------------------------------------------- MARCO -----------------------------------------------------------------------------------------------------------------------------
    glColor3f(0.184, 0.455, 0.729);
    
    float width = 1;
    float space = 0.298;
    
    float v1 = 0;
    float v2 = width;
    float h = width;
    float b = 0;
    
    
    //marco inferior e izquierdo
    for(int i = 0; i<2; i++){
        while(v2 <= 101){
            glBegin(GL_POLYGON);
            glVertex2f(v1,b);
            glVertex2f(v2,b);
            glVertex2f(v2,h);
            glVertex2f(v1,h);
            glEnd();
            
            glBegin(GL_POLYGON);
            glVertex2f(b,v1);
            glVertex2f(b, v2);
            glVertex2f(h, v2);
            glVertex2f(h, v1);
            glEnd();
            
            v1 = v2 + space;
            v2 = v1 + width;
        }
        
        b = h + space;
        h = b + width;
        v1 = 0;
        v2 = width;
    }
    
    //marco superior y derecho
    v1 = 0;
    v2 = width;
    b = 101;
    h = b - width;
    
    for(int i = 0; i<2 ; i++){
        while(v2 <= 101){
            glBegin(GL_POLYGON);
            glVertex2f(v1,b);
            glVertex2f(v2,b);
            glVertex2f(v2,h);
            glVertex2f(v1,h);
            glEnd();
            
            glBegin(GL_POLYGON);
            glVertex2f(b,v1);
            glVertex2f(b, v2);
            glVertex2f(h, v2);
            glVertex2f(h, v1);
            glEnd();
            
            v1 = v2 + space;
            v2 = v1 + width;
        }
        
        b = h - space;
        h = b - width;
        v1 = 0;
        v2 = width;
    }
    
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(900,900);
    glutCreateWindow("Mosaico");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
}

