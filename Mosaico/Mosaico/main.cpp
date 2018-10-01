
//  Mosaico
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
#include <vector>
#include <array>

float w = 0.025;
float space = 0.00243;
float m_width = 2*w + space; // ancho del marco
float t;

void init(void) {
    glClearColor(0.949,0.937,.9098,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

// Convierte grados a radianes
float toRad(float grad){
    float rad;
    rad = (grad * M_PI)/180;
    return rad;
}

// pinta un círculo
std::array<std::vector<float>,2> circulo(float radio, float cx, float cy, float start_angle, float end_angle){
    std::array<std::vector<float>,2> points;
    
    start_angle = toRad(start_angle);
    end_angle = toRad(end_angle);
    
    for(double theta = start_angle; theta <= end_angle; theta += M_PI/1500){
        points[0].push_back(cx + cos(theta)*radio);
        points[1].push_back(cy + sin(theta)*radio);
    }
    return points;
}

void marco(void){
    glColor3f(0.251,0.267,0.235);
    
    float x = -1;
    float y = -1;
    
    float flag = 1- (2*w + space);
    
    //marcos
    for(int i = 0; i<2; i++){
        while(x <= 1){
            //inferior
            glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+w,y);
            glVertex2f(x+w,y+w);
            glVertex2f(x,y+w);
            glEnd();
            
            //superior
            glBegin(GL_POLYGON);
            glVertex2f(-x,-y);
            glVertex2f(-(x+w),-y);
            glVertex2f(-(x+w),-(y+w));
            glVertex2f(-x,-(y+w));
            glEnd();
            
            if(x >= -flag and x <= flag - space){
                //izquierdo
                glBegin(GL_POLYGON);
                glVertex2f(y,x);
                glVertex2f(y,x+w);
                glVertex2f(y+w,x+w);
                glVertex2f(y+w,x);
                glEnd();
                
                //derecho
                glBegin(GL_POLYGON);
                glVertex2f(-y,-x);
                glVertex2f(-y,-(x+w));
                glVertex2f(-(y+w),-(x+w));
                glVertex2f(-(y+w),-x);
                glEnd();
            }
            
            x += w +space;
        }
        
        x = -1;
        y += w + space;
    }
}

void circulosExteriores(void){
    float c = 0.8;
    
    glColor3ub(225, 134, 103);
    
    std::array<std::vector<float>,2> vertex;
    std::vector<float> x, y;
    
    vertex = circulo(0.5, c, c, 180, 270);
    
    x = vertex[0];
    y = vertex[1];
        
    int n = (int)x.size();
        
    glBegin(GL_POLYGON);
    glVertex2f(c, c);
    for(int i = 0; i < n; i++){
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(-c, c);
    for(int i = 0; i < n; i++){
        glVertex2f(-x[i], y[i]);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-c, -c);
    for(int i = 0; i < n; i++){
        glVertex2f(-x[i], -y[i]);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(c, -c);
    for(int i = 0; i < n; i++){
        glVertex2f(x[i], -y[i]);
    }
    glEnd();
    
}

void arco(std::array<std::vector<float>,2> vertex, float R, float G, float B){
    glColor3ub(R, G, B);
    
    std::vector<float> x = vertex[0];
    std::vector<float> y = vertex[1];
    
    int n = (int)x.size();
    
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<n; i++){
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    
}

void contorno(void){
    glColor3ub(64, 68, 60);

    float c = 1 - m_width;
    
    std::array<std::vector<float>,2> vertex, vertex_2;
    std::vector<float> x, y;
    
    //grosor de línea
    glLineWidth(2.0);
    
    for (float r = c; r >= c - 0.02; r -= 0.001){
        vertex = circulo(r, c, c, 180, 270);
        
        x = vertex[0];
        y = vertex[1];
        
        int n = (int)x.size();
        
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < n; i++){
            glVertex2f(x[i], y[i]);
        }
        glEnd();
        
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < n; i++){
            glVertex2f(-x[i], y[i]);
        }
        glEnd();
        
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < n; i++){
            glVertex2f(-x[i], -y[i]);
        }
        glEnd();
        
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < n; i++){
            glVertex2f(x[i], -y[i]);
        }
        glEnd();
    }
}

void centro(){
    float v = 0.04;
    glColor3ub(255, 195, 103);
    
    glBegin(GL_POLYGON);
    glVertex2f(0, v);
    glVertex2f(v,0);
    glVertex2f(0, -v);
    glVertex2f(-v, 0);
    glEnd();
}

/*
    //***************************************************
    //                    TURQUESA
    //***************************************************
    float c1[4][3] = {{103, 225, 195}, {122, 229, 203}, {141, 232, 210},{141, 232, 210}};
    
    //***************************************************
    //                      ROSA
    //***************************************************
    float c2[4][3] = {{225, 103, 133}, {229, 122, 148}, {232, 141, 164}, {236, 160, 179}};
    
    //***************************************************
    //                  VERDE
    //***************************************************
    
    float c3[4][3] = {{194, 225, 103}, {202, 229, 122}, {209, 232, 141}, {217, 236, 160}};

    //***************************************************
    //                  MORADO
    //***************************************************
    float c4[4][3] = {{134, 103, 225}, {149, 122, 229}, {164, 141, 232}, {179, 160, 236}};

 */

float getS(float t){
    float s;
    
    if(t <= 48){
        s = 0.02*t;
    }else{
        s = 0;
    }
    
    return s;
}

float getAngle(float t){
    float theta;
    
    if(t <= 48){
        theta = 45*t;
    }else{
        theta = 0;
    }
    
    return theta;
}

void figura(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    float R, G, B;
    float r, r_aux;
    
    float r_space = 0.01; // espacio entre círculos
    float a_width = 0.02; // ancho de arco
    float c = 1 - m_width;
    
    std::array<std::vector<float>,2> vertex;
    
    marco();
    circulosExteriores();
    
    glLineWidth(2.0);
    
//    glColor3ub(200, 100, 50);
//    glBegin(GL_LINES);
//    glVertex3f(0, 1, -1);
//    glVertex3f(0, -1, -1);
//
//    glVertex3f(1, 0, -1);
//    glVertex3f(-1, 0, -1);
//    glEnd();
//
    if (t <= 48){
        glPushMatrix();
            glScalef(0.02*t, 0.02*t, 1);
            glRotatef(45*t, 0, 0, 1);
            centro();
        glPopMatrix();
        
        
    }else if(t > 48 and t<= 98){
        centro();
        
        for (r = c - 0.02; r <= c; r += 0.001){
            vertex = circulo(r, 0, 0, 0, 90);
            
            glPushMatrix();
            glTranslatef(c, c, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(0.02*(t-48), 0.02*(t-48), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(-c, c, 0);
            glRotatef(270, 0, 0, 1);
            glScalef(0.02*(t-48), 0.02*(t-48), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(-c, -c, 0);
            glScalef(0.02*(t-48), 0.02*(t-48), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(c, -c, 0);
            glRotatef(90, 0, 0, 1);
            glScalef(0.02*(t-48), 0.02*(t-48), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();
        }
        
    }else if( t <= 278){
        
        r_aux = r + r_space;
        
        centro();
        contorno();
        
        for(r = c ; r <= c + a_width; r += 0.001){
            vertex = circulo(r, 0, 0, 0, 90);
            
            glPushMatrix();
            glRotatef(t-98, 0, 0, 1);
            //glTranslatef(c, c, 0);
            arco(vertex, 134, 103, 225);
            glPopMatrix();
        }
        
    }else{
        
        for(r = c + r_space; r <= c + r_space + a_width; r += 0.001){
            vertex = circulo(r, 0, 0, 7, 83);
            glPushMatrix();
            glTranslatef(c, c, 0);
            glRotatef(180, 0, 0, 1);
            arco(vertex, 134, 103, 225);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(-c, c, 0);
            glRotatef(270, 0, 0, 1);
            arco(vertex, 134, 103, 225);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(-c, -c, 0);
            glRotatef(0, 0, 0, 1);
            arco(vertex, 134, 103, 225);
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(c, -c, 0);
            glRotatef(90, 0, 0, 1);
            arco(vertex, 134, 103, 225);
            glPopMatrix();
        }
        
        centro();
        contorno();
    }
    
    t += 2; //0.07;
    

    
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(900,900);
    glutCreateWindow("Mosaico");
    init();
    
    t = 0.0;
    glutDisplayFunc(figura);
    glutIdleFunc(figura);
    glutMainLoop();
}

