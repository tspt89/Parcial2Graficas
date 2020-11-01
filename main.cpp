/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "3D_bib.h"
#include "Ship.h"
#include "Pyramid.h"
#include "Cube.h"
#include "Acclamator.h"
#include "XWing.h"
#include "Sphere.h"
#include "Escenario.h"

//Declaracion de variables
//...

//Variables dimensiones de la pantalla
int WIDTH=1280;
int HEIGTH=720;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=500.0;
//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=20;//10.0
float EYE_Y=15;//5.0
float EYE_Z=35;//10.0
float CENTER_X=0;//0
float CENTER_Y=0;//0
float CENTER_Z=0;//0
float UP_X=0;//0
float UP_Y=1;//1
float UP_Z=0;//0
//Variables para dibujar los ejes del sistema
float X_MIN=-100;//-20
float X_MAX=50;//20
float Y_MIN=-20;//-20
float Y_MAX=20;//20
float Z_MIN=-500;
float Z_MAX=500;



//funciones de control generales
//...
float p1[3]={0.0,0.0,0.0};                                      //
float p2[3]={5.0,0.0,0.0};                                     //
float p3[3]={0.0,0.0,1.0};
float p4[3]={1.0,0.0,0.9};
//-------------------------------------------------------------------------
//funciones callbacks
void idle(void)
{
    //glutPostRedisplay();
    Sleep(100);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     //gluOrtho2D(-320,320,-240,240);
     glMatrixMode(GL_MODELVIEW);
}

static void keys(unsigned char key, int x, int y)
{
    switch(key){

    }
    //glutPostRedisplay();
}
//--------------------------------------------------------------------------

void drawAxis()
{
     glShadeModel(GL_SMOOTH);
     glLineWidth(3.0);
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(0.5f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glColor3f(0.0f,1.0f,0.0f);
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,0.5f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    Escenario e;
    e.draw();

}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Parcial 2");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    //glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
