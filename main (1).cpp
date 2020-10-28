
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

//Declaracion de variables
//...
//Variables dimensiones de la pantalla
int WIDTH=1280;
int HEIGTH=720;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
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
float Z_MIN=-100;
float Z_MAX=20;

//Se declara el objeto para utilizar las operaciones 3D
Operaciones3D Op3D;
Cube myCb1(&Op3D);
Cube myCb2(&Op3D);
Cube myCb3(&Op3D);
Cube myCb4(&Op3D);
Sphere mySp(&Op3D);
XWing myXW1(&Op3D);
XWing myXW2(&Op3D);
Acclamator myAcc(&Op3D);

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
       glColor3f(0.0f,0.0f,0.5f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();

    //Draw acclamator
    Op3D.push();
    glColor3f(1.0f,1.0f,1.0f);
    Op3D.translate(20.0,0.0,0.0);
    Op3D.scale(1.0,1.5,1.5);
    myAcc.draw();
    Op3D.pop();

    //Laser 1
    Op3D.push();
    glColor3f(1.0f,0.0f,0.0f);
    Op3D.translate(2.0,0.0,50.0);
    Op3D.scale(3.5,0.2,0.2);
    myCb1.draw();
    Op3D.pop();

    //Laser 2
    Op3D.push();
    glColor3f(1.0f,0.0f,0.0f);
    Op3D.translate(7,0.0,7.0);
    Op3D.scale(2.0,0.2,0.2);
    myCb2.draw();
    Op3D.pop();

    Op3D.push();
    glColor3f(1.0f,0.0f,1.0f);
    Op3D.translate(-30.0,0.0,10.0);
    myXW1.draw();
    Op3D.pop();

    //Laser 3
    Op3D.push();
    glColor3f(0.0f,1.0f,0.0f);
    Op3D.translate(-10.0,0.0,40.0);
    Op3D.scale(1.5,0.2,0.2);
    myCb3.draw();
    Op3D.pop();

    Op3D.push();
    glColor3f(1.0f,0.0f,1.0f);
    Op3D.translate(-60.0,5.0,-10.0);
    myXW2.draw();
    Op3D.pop();

    //Laser 4
    Op3D.push();
    glColor3f(0.0f,1.0f,0.0f);
    Op3D.translate(-3.0,0.0,-50.0);
    Op3D.scale(5,0.2,0.2);
    myCb4.draw();
    Op3D.pop();

    Op3D.push();
    glColor3f(0.5f,0.5f,0.5f);
    mySp.draw();
    Op3D.pop();

    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
	//prepara los parametros de ajuste del objeto
    //myShip.setDeltaDegRotation(30.0);
    //myShip.setRotation(TRUE);
    //myShip.setDeltaAxisTranslation(vT);
    //myShip.setTranslation(TRUE);
    //myShip.setAnimation(TRUE);
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
    glutIdleFunc(idle);
    //glutKeyboardFunc(keys);
    //glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

