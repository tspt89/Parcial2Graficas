#include "Pyramid.h"

 //---------------------------------------------------------------
Pyramid::Pyramid(Operaciones3D *data)
 {
     Op3D = data;
     Op3D->LoadIdentity(Op3D->A);
     Op3D->LoadIdentity(myA);
	 //...
 }

Pyramid::~Pyramid()
 {
     Op3D = NULL;
 }


void Pyramid::updateAnimation()
 {

 }

void Pyramid::draw()
{
    Op3D->MatObject(Op3D->A,5,points);
    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<4;i++)
        glVertex3f(points[i][0],points[i][1],points[i][2]);
    glEnd();
    glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3f(points[4][0],points[4][1],points[4][2]);
        glVertex3f(points[i][0],points[i][1],points[i][2]);
        }
    glEnd();
}

/*void Pyramid::escala(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->E);

    Op3D->E[0][0]=puntos[0];
    Op3D->E[1][1]=puntos[1];
    Op3D->E[2][2]=puntos[2];

    Op3D->MultM(myA,Op3D->E,myA);
    Op3D->MatObject(myA,5,points);
}

void Pyramid::traslation(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->T);

    Op3D->T[0][3]=puntos[0];
    Op3D->T[1][3]=puntos[1];
    Op3D->T[2][3]=puntos[2];

    Op3D->MultM(myA,Op3D->T,myA);
    Op3D->MatObject(myA,5,points);
}

 void Pyramid::rotation(float theta, float p1[3], float p2[3])
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
    Op3D->MatObject(myA,5,points);
}*/

