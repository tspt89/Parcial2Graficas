/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "Cube.h"

 //---------------------------------------------------------------
Cube::Cube(Operaciones3D *data)
 {
     Op3D = data;
     Op3D->LoadIdentity(Op3D->A);
     Op3D->LoadIdentity(myA);
	 //...
 }

Cube::~Cube()
 {
     Op3D = NULL;
 }


void Cube::updateAnimation()
 {

 }

 void Cube::draw()
{
    Op3D->MatObject(Op3D->A,8,points);
    //Cara superior
    glBegin(GL_LINES);
        glVertex3f(points[0][0],points[0][1],points[0][2]);
        glVertex3f(points[4][0],points[4][1],points[4][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[4][0],points[4][1],points[4][2]);
        glVertex3f(points[5][0],points[5][1],points[5][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[5][0],points[5][1],points[5][2]);
         glVertex3f(points[6][0],points[6][1],points[6][2]);
    glEnd();

    glBegin(GL_LINES);
       glVertex3f(points[6][0],points[6][1],points[6][2]);
       glVertex3f(points[7][0],points[7][1],points[7][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[7][0],points[7][1],points[7][2]);
        glVertex3f(points[4][0],points[4][1],points[4][2]);
    glEnd();

    //caras radiales
    glBegin(GL_LINES);
         glVertex3f(points[5][0],points[5][1],points[5][2]);
        glVertex3f(points[1][0],points[1][1],points[1][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[6][0],points[6][1],points[6][2]);
          glVertex3f(points[2][0],points[2][1],points[2][2]);
    glEnd();
    glBegin(GL_LINES);
         glVertex3f(points[7][0],points[7][1],points[7][2]);
          glVertex3f(points[3][0],points[3][1],points[3][2]);
    glEnd();

    //cara inferior
    glBegin(GL_LINES);
        glVertex3f(points[0][0],points[0][1],points[0][2]);
        glVertex3f(points[1][0],points[1][1],points[1][2]);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(points[1][0],points[1][1],points[1][2]);
        glVertex3f(points[2][0],points[2][1],points[2][2]);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(points[2][0],points[2][1],points[2][2]);
        glVertex3f(points[3][0],points[3][1],points[3][2]);
    glEnd();
    glBegin(GL_LINES);
      glVertex3f(points[3][0],points[3][1],points[3][2]);
        glVertex3f(points[0][0],points[0][1],points[0][2]);
    glEnd();
}

/*void Cube::escala(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->E);

    Op3D->E[0][0]=puntos[0];
    Op3D->E[1][1]=puntos[1];
    Op3D->E[2][2]=puntos[2];

    Op3D->MultM(myA,Op3D->E,myA);
    Op3D->MatObject(myA,8,points);
}

void Cube::traslation(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->T);

    Op3D->T[0][3]=puntos[0];
    Op3D->T[1][3]=puntos[1];
    Op3D->T[2][3]=puntos[2];

    Op3D->MultM(myA,Op3D->T,myA);
    Op3D->MatObject(myA,8,points);
}

 void Cube::rotation(float theta, float p1[3], float p2[3])
{
    float point1, point2, point3;

    for(int i=0;i<3;i++){
        point1=p1[0];
        point2=p1[1];
        point3=p1[2];
    }

    float v = Op3D->normal(p1, p2);
    float a = Op3D->getA(p1,p2,v);
    float b = Op3D->getB(p1,p2,v);
    float c = Op3D->getC(p1,p2,v);
    float d = Op3D->getD(b,c);

    Op3D->LoadIdentity(Op3D->T);

    Op3D->T[0][3]=-1*point1;
    Op3D->T[1][3]=-1*point2;
    Op3D->T[2][3]=-1*point3;

    Op3D->rotateXFree(d,b,c);
    Op3D->MultM(Op3D->R,Op3D->T,myA);
    Op3D->rotateYFree(a,d);
    Op3D->MultM(Op3D->R,myA,myA);
    Op3D->rotateZ(Op3D->DegToRad(theta));
    Op3D-> MultM(Op3D->R,myA,myA);
    Op3D->rotateYFree(-1*a,d);
    Op3D->MultM(Op3D->R,myA,myA);
    Op3D->rotateXFree(d,-1*b,c);
    Op3D->MultM(Op3D->R,myA,myA);
    Op3D->LoadIdentity(Op3D->T);
    Op3D->T[0][3]=point1;
    Op3D->T[1][3]=point2;
    Op3D->T[2][3]=point3;
    Op3D->MultM(Op3D->T,myA,myA);
    Op3D->MatObject(myA,8,points);
}*/
