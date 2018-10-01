
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

std::array<std::vector<std::array<std::vector<float>,2>>,7> points;
std::array<std::vector<float>,7> angles;

float w = 0.025;
float space = 0.00243;
float m_width = 2*w + space; // ancho total del marco
float c = 1 - m_width;
float t;

float purples[7][3] = {{134, 103, 225}, {149, 122, 229}, {164, 141, 232}, {179, 160, 236}, {195, 179, 240}, {210, 198, 244}, {225, 217, 247}};
float green[7][3] = {{194, 225, 103}, {202, 229, 122}, {209, 232, 141}, {217, 236, 160}, {225, 240, 179}, {232, 244, 198}, {240, 247, 217}};
float pink[7][3] = {{225, 103, 133}, {229, 122, 148}, {232, 141, 164}, {236, 160, 179},{240, 179, 194},{244, 198, 209},{247, 217, 225}};
float turquoise[7][3] = {{103, 225, 195}, {122, 229, 203}, {141, 232, 210},{160, 236, 218},{179, 240, 225},{198, 244, 233}, {217, 247, 240}};

//-------------------------------------------------------------------------------------------------------------------------------------

void init(void) {
    float R = 255/255;
    float G = 253/255;
    float B = 231/255;
    
    glClearColor(1, 0.9960, 0.9647, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

// Convierte grados a radianes
float toRad(float grad){
    float rad;
    rad = (grad * M_PI)/180;
    return rad;
}

float getAngle(float point){
    return (atan(point)*180) / M_PI;
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

void slice(int cuad, float R, float G, float B){
    float center = 0.8;
    
    glColor3ub(R, G, B);
    
    std::array<std::vector<float>,2> vertex;
    std::vector<float> x, y;
    
    vertex = circulo(0.5, center, center, 180, 270);
    x = vertex[0];
    y = vertex[1];
    
    int n = (int)x.size();
    
    glBegin(GL_POLYGON);
    
    switch (cuad) {
        case 0:
            glVertex2f(center, center);
            for(int i = 0; i < n; i++){
                glVertex2f(x[i], y[i]);
            }
            break;
            
        case 1:
            glVertex2f(-center, center);
            for(int i = 0; i < n; i++){
                glVertex2f(-x[i], y[i]);
            }
            break;
            
        case 2:
            glVertex2f(-center, -center);
            for(int i = 0; i < n; i++){
                glVertex2f(-x[i], -y[i]);
            }
            break;
            
        case 3:
            glVertex2f(center, -center);
            for(int i = 0; i < n; i++){
                glVertex2f(x[i], -y[i]);
            }
            break;
            
        default:
            break;
    }

    glEnd();
}

void circulosExteriores(float center){
    std::array<std::vector<float>,2> vertex;
    std::vector<float> x, y;
    
    vertex = circulo(0.5, center, center, 180, 270);
    x = vertex[0];
    y = vertex[1];
    
    int n = (int)x.size();
    
    if(t > 172){
        glColor3ub(purples[0][0], purples[0][1], purples[0][2]);
    }else{
        glColor3ub(225, 134, 103);
    }
    
    glBegin(GL_POLYGON);
    glVertex2f(center, center);
    for(int i = 0; i < n; i++){
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    
    if(t > 262){
        glColor3ub(green[0][0], green[0][1], green[0][2]);
    }else{
        glColor3ub(225, 134, 103);
    }
    
    glBegin(GL_POLYGON);
    glVertex2f(-center, center);
    for(int i = 0; i < n; i++){
        glVertex2f(-x[i], y[i]);
    }
    glEnd();
    
    if(t > 352){
        glColor3ub(pink[0][0], pink[0][1], pink[0][2]);
    }else{
        glColor3ub(225, 134, 103);
    }
    
    glBegin(GL_POLYGON);
    glVertex2f(-center, -center);
    for(int i = 0; i < n; i++){
        glVertex2f(-x[i], -y[i]);
    }
    glEnd();
    
    if(t >= 441){
        glColor3ub(turquoise[0][0], turquoise[0][1], turquoise[0][2]);
    }else{
        glColor3ub(225, 134, 103);
    }
    
    glBegin(GL_POLYGON);
    glVertex2f(center, -center);
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

void cuadI(float angle, std::array<std::vector<float>, 2> vertex, int i){
    glPushMatrix();
    glTranslatef(c, c, 0);
    glRotatef(angle, 0, 0, 1);
    arco(vertex, purples[i][0], purples[i][1], purples[i][2]);
    glPopMatrix();
    
}

void cuadII(float angle, std::array<std::vector<float>, 2> vertex, int i){
    glPushMatrix();
    glTranslatef(-c, c, 0);
    glRotatef(angle, 0, 0, 1);
    arco(vertex, green[i][0], green[i][1], green[i][2]);
    glPopMatrix();
    
}

void cuadIII(float angle, std::array<std::vector<float>, 2> vertex, int i){
    glPushMatrix();
    glTranslatef(-c, -c, 0);
    glRotatef(angle, 0, 0, 1);
    arco(vertex, pink[i][0], pink[i][1], pink[i][2]);
    glPopMatrix();
    
}

void cuadIV(float angle, std::array<std::vector<float>, 2> vertex, int i){
    glPushMatrix();
    glTranslatef(c, -c, 0);
    glRotatef(angle, 0, 0, 1);
    arco(vertex, turquoise[i][0], turquoise[i][1], turquoise[i][2]);
    glPopMatrix();
    
}

void mosaico(){
    centro();
    contorno();
    for(int i = 0; i < 7; i++){
        for(std::array<std::vector<float>, 2> v: points[i]){
            cuadI(180, v, i);
            cuadII(270, v, i);
            cuadIII(0, v, i);
            cuadIV(90, v, i);
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------

void figura(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    int j;
    float R, G, B;
    float r, r_aux, theta, p;
    
    float r_space = 0.008; // espacio entre círculos
    float a_width = 0.04; // ancho de arco
    float c = 1 - m_width; // posición de la esquina del marco
    
    std::array<std::vector<float>,2> vertex;
    
    marco();
    
    if(t > 32 and t < 442){
        centro();
    }
    
    if( t > 32 and t < 455){
        circulosExteriores(0.8);
    }
    
    if(t >= 82 and t < 442){
        contorno();
    }
    
    if(t >= 442 and t < 447){
        mosaico();
    }
    
    glLineWidth(2.0);

    if (t <= 32){
        glPushMatrix();
        glScalef(0.03125*t, 0.03125*t, 1);
        glRotatef(45*t, 0, 0, 1);
        centro();
        glPopMatrix();
    }else if(t > 32 and t<= 82){
        for (r = c - 0.02; r <= c; r += 0.001){
            vertex = circulo(r, 0, 0, 0, 90);

            glPushMatrix();
            glTranslatef(c, c, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(0.02*(t-32), 0.02*(t-32), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-c, c, 0);
            glRotatef(270, 0, 0, 1);
            glScalef(0.02*(t-32), 0.02*(t-32), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-c, -c, 0);
            glScalef(0.02*(t-32), 0.02*(t-32), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(c, -c, 0);
            glRotatef(90, 0, 0, 1);
            glScalef(0.02*(t-32), 0.02*(t-32), 1);
            arco(vertex, 64, 68, 60);
            glPopMatrix();
        }
    }else if( t <= 172){
        r_aux = c + r_space;
        for(int i = 0; i < 7; i++){
            for(r = r_aux ; r <= r_aux + a_width; r += 0.001){
                p = sqrt(pow(r,2)-pow(c,2));
                theta = getAngle(p/c);
                
                vertex = circulo(r, 0, 0, theta, 90 - theta);
                
                points[i].push_back(vertex);
                angles[i].push_back(theta);
                
                cuadI(t + 8, vertex, i);
            }
            
            r_aux = r + r_space;
        }
    }else if(t <= 262){
        r_aux = c + r_space;
        
        for(int i = 0; i<7; i++){
            j = 0;
            for(r = r_aux ; r <= r_aux + a_width; r += 0.001){
                theta = angles[i][j];
                vertex = circulo(r, 0, 0, theta, 90 - theta);
                
                cuadI(180, vertex, i);
                cuadII(t + 8, vertex, i);
                
                j++;
            }
            r_aux = r + r_space;
        }
    }else if (t <= 352){
        r_aux = c + r_space;
        for(int i = 0; i<7; i++){
            j = 0;
            for(r = r_aux ; r <= r_aux + a_width; r += 0.001){
                theta = angles[i][j];
                vertex = circulo(r, 0, 0, theta, 90 - theta);
                
                cuadI(180, vertex, i);
                cuadII(270, vertex, i);
                cuadIII(t + 8, vertex, i);
                
                j++;
            }
            r_aux = r + r_space;
        }
    }else if(t <= 442){
        r_aux = c + r_space;
        
        for(int i = 0; i<7; i++){
            j = 0;
            for(r = r_aux ; r <= r_aux + a_width; r += 0.001){
                theta = angles[i][j];
                vertex = circulo(r, 0, 0, theta, 90 - theta);
                
                cuadI(180, vertex, i);
                cuadII(270, vertex, i);
                cuadIII(0, vertex, i);
                cuadIV(t - 352, vertex, i);
                
                j++;
            }
            r_aux = r + r_space;
        }
    }else if(t >= 448 and  t <= 635){
        glPushMatrix();
        glRotatef(45*(t - 448), 0, 0, 1);
        glScalef(1.0-0.005347*(t - 448), 1.0-0.005347*(t - 448), 1);
        mosaico();
        glPopMatrix();
        
        if(t > 455){
            float tx = 0.8/180;
            
            glPushMatrix();
            glRotatef(t - 455, 0, 0, 1);
            glTranslatef(-tx*(t - 455),-tx*(t - 455), 0);
            slice(0, purples[0][0], purples[0][1], purples[0][2]);
            glPopMatrix();
            
            glPushMatrix();
            glRotatef(t - 455, 0, 0, 1);
            glTranslatef(tx*(t - 455),-tx*(t - 455), 0);
            slice(1, green[0][0], green[0][1], green[0][2]);
            glPopMatrix();
            
            glPushMatrix();
            glRotatef(t - 455, 0, 0, 1);
            glTranslatef(tx*(t - 455),tx*(t - 455), 0);
            slice(2, pink[0][0], pink[0][1], pink[0][2]);
            glPopMatrix();
            
            glPushMatrix();
            glRotatef(t - 455, 0, 0, 1);
            glTranslatef(-tx*(t - 455),tx*(t - 455), 0);
            slice(3, turquoise[0][0], turquoise[0][1], turquoise[0][2]);
            glPopMatrix();
        }
        
    }else if(t > 635){
        glPushMatrix();
            glRotatef(180, 0, 0, 1);
            circulosExteriores(0);
        glPopMatrix();
    }
    
    if(t <= 82){
        t += 0.2;
    }else if(t <= 352){
        t += 2;
    }else if (t <= 447){
        t += 3;
    }else{
        t += 11;
    }
    
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
