
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

void init(void) {
    //glClearColor(0.988, 0.984, 0.976, 1.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-1,1,-1,1);
    gluOrtho2D(0, 101, 0, 101);
}

float toRad(float grad){
    float rad;
    rad = (grad * M_PI)/180;
    return rad;
}

void circulo(float radio, float x, float y, float R, float G, float B, float start_angle, float end_angle){
    
    start_angle = toRad(start_angle);
    end_angle = toRad(end_angle);
    
    glColor3f(R, G, B);
    
    glBegin(GL_LINE_STRIP);
    for(double theta = start_angle; theta < end_angle; theta += M_PI/1000){
        glVertex2f(x + cos(theta)*radio, y + sin(theta)*radio);
    }
    
    glEnd();
}


void mosaico(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // ----------------------------------------------------------------- CIRCULOS -----------------------------------------------------------------------------------------------------------------------
    float r;
    
    //grosor de línea
    glLineWidth(3.0);
    
    glEnable(GL_LINE_STIPPLE);
    
    //glLineStipple(2, 0x00FF);
    glLineStipple(3, 0xFFFF);

    float start_1,start_2,start_3,start_4;
    float end_1,end_2,end_3,end_4;
    float R, G, B;
    
    //negro (?)
    R = 0.251;
    G = 0.267;
    B = 0.235;

    start_1 = 308;
    end_1 = 322;

    start_3 = 130;
    end_3 = 141.5;

    for(r = 70; r<= 71; r++){
        circulo(r, 0, 101, R, G, B,start_1,end_1);
        circulo(r, 101, 0, R, G, B, start_3, end_3);

        start_1 += 0.6;
        end_1 -= 0.5;

        start_3 += 0.3;
        end_3 -= 0.2;
    }

    start_2 = 224.5;
    end_2 = 227.5;

    start_4 = 45;
    end_4 = 46;

    for(r = 64; r <= 65; r ++){
        circulo(r, 101, 101, R, G, B, start_2, end_2);
        circulo(r, 0, 0, R, G, B, start_4, end_4);

        start_2 += 0.5;
        end_2 -= 0.5;

        start_4 += 1.6;
        end_4 -= 1.3;
    }
    
    //beige (3/1)
    R = 0.949;
    G = 0.937;
    B = 0.91;

    start_1 = 305;
    end_1 = 325;

    start_3 = 128;
    end_3 = 145;

    for(r = 67; r<= 69; r++){
        circulo(r, 0, 101, R, G, B,start_1,end_1);
        circulo(r, 101, 0, R, G, B, start_3, end_3);

        start_1 += 0.5;
        end_1 -= 0.5;

        start_3 += 0.3;
        end_3 -= 0.5;
    }

    start_2 = 222.5;
    end_2 = 231;

    start_4 = 42;
    end_4 = 48;

    for(r = 61; r <= 63; r ++){
        circulo(r, 101, 101, R, G, B, start_2, end_2);
        circulo(r, 0, 0, R, G, B, start_4, end_4);

        start_2 += 0.3;
        end_2 -= 0.5;

        start_4 += 0.5;
        end_4 -= 0.5;
    }
    
    //naranja (4/2)
    R = 0.776;
    G = 0.478;
    B = 0.184;

    start_1 = 302;
    end_1 = 328;

    start_3 = 124;
    end_3 = 148;

    for(r = 63; r<= 66; r++){
        circulo(r, 0, 101, R, G, B,start_1,end_1);
        circulo(r, 101, 0, R, G, B, start_3, end_3);

        start_1+=0.6;
        end_1-=0.5;

        start_3 += 0.4;
        end_3 -= 0.5;
    }

    start_2 = 219;
    end_2 = 236;

    start_4 = 39;
    end_4 = 51.5;

    for(r = 59; r <= 60; r ++){
        circulo(r, 101, 101, R, G, B, start_2, end_2);
        circulo(r, 0, 0, R, G, B, start_4, end_4);

        start_2+=0.7;
        end_2-=1.2;

        start_4 += 0.5;
        end_4 -= 1;
    }
    
    //rojo (5/3)
    start_1 = 296.5;
    end_1 = 334;

    start_3 = 120;
    end_3 = 154;

    for(r = 58; r<= 62; r++){
        circulo(r, 0, 101, 0.702,0.302,0.302,start_1,end_1);
        circulo(r, 101, 0, 0.702, 0.302, 0.302, start_3, end_3);

        start_1+=0.6;
        end_1-=0.7;

        start_3 += 0.5;
        end_3 -= 0.6;
    }

    start_2 = 213.5;
    end_2 = 243;

    start_4 = 33.5;
    end_4 = 57;

    for(r = 56; r <= 58; r ++){
        circulo(r, 101, 101, 0.702,0.302,0.302, start_2, end_2);
        circulo(r, 0 , 0, 0.702, 0.302, 0.302, start_4, end_4);

        start_2+=0.6;
        end_2-=1;

        start_4 += 0.5;
        end_4 -= 0.5;
    }
    
    
    //verde (6/4)
    start_1 = 282;
    end_1 = 348;
    
    start_2 = 204;
    end_2 = 260;
    
    start_3 = 110;
    end_3 = 168;
    
    start_4 = 24;
    end_4 = 67;
   
    for(r = 52; r <= 57; r++){
        circulo(r, 0, 101, 0.714,0.808,0.525,start_1,end_1);
        circulo(r,101, 0,0.714,0.808,0.525, start_3, end_3);
        
        start_1+=1.5;
        end_1-=1.5;
        
        start_3 += 1.2;
        end_3 -= 1.5;
    }
    
    for(r = 52; r <= 55; r++){
        circulo(r, 101, 101, 0.714,0.808,0.525,start_2,end_2);
        circulo(r, 0 , 0,0.714,0.808,0.525,start_4, end_4);
        
        start_2+=1;
        end_2-=2.5;
        
        start_4 += 1;
        end_4 -= 1;
    }
    

    
    //negro
    for(r = 51; r >= 50; r -= 0.1 ){
        circulo(r, 0, 101, 0.251,0.267,0.235, 272.5, 357.5);
        circulo(r, 101, 101, 0.251,0.267,0.235, 182.5, 267.5);
        circulo(r, 101, 0, 0.251,0.267,0.235, 92.5, 177.5);
        circulo(r, 0, 0, 0.251,0.267,0.235, 2.5, 87.5);
    }
    
    glLineStipple(3, 0xFFFF);
    
    // beige externo
    for(r = 49.6; r>= 1; r -= 0.1){
        circulo(r, 0, 101, 0.949,0.937,0.91, 272.5, 357.5);
        circulo(r, 101, 101, 0.949,0.937,0.91, 182.5, 267.5);
        circulo(r, 101, 0, 0.949,0.937,0.91, 92.5, 177.5);
        circulo(r, 0, 0, 0.949,0.937,0.91, 2.5, 87.5);
    }
    
    //--------------------------------------------------------------- CIRCULOS(?) EXTERIORES -----------------------------------------------------------------------------------------------------------------------------

    glLineStipple(3, 0xBBBB);
    
    start_1 = 285;
    end_1 = 345;
    
    start_2 = 195;
    end_2 = 255;
    
    start_3 = 105;
    end_3 = 165;
    
    start_4 = 15;
    end_4 = 75;
    
    for(r = 27; r >= 0; r -= 0.5){
        circulo(r, 10, 91, 0.702,0.302,0.302, 270, 360);
        circulo(r, 91, 91, 0.702,0.302,0.302, 180, 270);
        circulo(r, 91, 10, 0.702, 0.302,0.302, 90, 180);
        circulo(r, 10, 10, 0.702,0.302,0.302, 0, 90);
    }

    
    
    glDisable(GL_LINE_STIPPLE);
    //--------------------------------------------------------------- MARCO -----------------------------------------------------------------------------------------------------------------------------

    glColor3f(0.251,0.267,0.235);

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
    
//    glLineWidth(1.0);
//    glColor4ub(115, 105, 105,0.9);
//
//    glBegin(GL_LINES);
//    glVertex2f(0, 10);
//    glVertex2f(101, 10);
//    glVertex2f(10, 0);
//    glVertex2f(10, 101);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(50.5,101);
//    glVertex2f(50.5, 0);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(0,50.5);
//    glVertex2f(101, 50.5);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(0, 101);
//    glVertex2f(101, 0);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(0, 0);
//    glVertex2f(101, 101);
//    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(900,900);
    glutCreateWindow("Mosaico");
    init();
    glutDisplayFunc(mosaico);
    glutMainLoop();
}

