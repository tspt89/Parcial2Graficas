#include "XWing.h"

 //---------------------------------------------------------------
XWing::XWing(Operaciones3D *data)
 {
     Op3D = data;
     Op3D->LoadIdentity(Op3D->A);
     Op3D->LoadIdentity(myA);
	 //...
 }

XWing::~XWing()
 {
     Op3D = NULL;
 }

 void XWing::draw()
{
    Op3D->MatObject(Op3D->A,28,points);

    //Cara Mitad
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

    //Cara Superior
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

    //Cara Inferior
    glBegin(GL_LINES);
        glVertex3f(points[8][0],points[8][1],points[8][2]);
        glVertex3f(points[9][0],points[9][1],points[9][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[9][0],points[9][1],points[9][2]);
        glVertex3f(points[10][0],points[10][1],points[10][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[10][0],points[10][1],points[10][2]);
        glVertex3f(points[11][0],points[11][1],points[11][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[11][0],points[11][1],points[11][2]);
         glVertex3f(points[8][0],points[8][1],points[8][2]);
    glEnd();

    //Cara lateral
    glBegin(GL_LINES);
        glVertex3f(points[0][0],points[0][1],points[0][2]);
        glVertex3f(points[4][0],points[4][1],points[4][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[1][0],points[1][1],points[1][2]);
        glVertex3f(points[5][0],points[5][1],points[5][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[2][0],points[2][1],points[2][2]);
        glVertex3f(points[6][0],points[6][1],points[6][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[3][0],points[3][1],points[3][2]);
        glVertex3f(points[7][0],points[7][1],points[7][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[0][0],points[0][1],points[0][2]);
        glVertex3f(points[8][0],points[8][1],points[8][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[1][0],points[1][1],points[1][2]);
        glVertex3f(points[9][0],points[9][1],points[9][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[2][0],points[2][1],points[2][2]);
        glVertex3f(points[10][0],points[10][1],points[10][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[3][0],points[3][1],points[3][2]);
        glVertex3f(points[11][0],points[11][1],points[11][2]);
    glEnd();

    //Cara Ala Izq 1
    glBegin(GL_LINES);
        glVertex3f(points[12][0],points[12][1],points[12][2]);
        glVertex3f(points[13][0],points[13][1],points[13][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[13][0],points[13][1],points[13][2]);
        glVertex3f(points[14][0],points[14][1],points[14][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[14][0],points[14][1],points[14][2]);
        glVertex3f(points[15][0],points[15][1],points[15][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[15][0],points[15][1],points[15][2]);
         glVertex3f(points[12][0],points[12][1],points[12][2]);
    glEnd();

    //Cara Ala Der 1
    glBegin(GL_LINES);
        glVertex3f(points[16][0],points[16][1],points[16][2]);
        glVertex3f(points[17][0],points[17][1],points[17][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[17][0],points[17][1],points[17][2]);
        glVertex3f(points[18][0],points[18][1],points[18][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[18][0],points[18][1],points[18][2]);
        glVertex3f(points[19][0],points[19][1],points[19][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[19][0],points[19][1],points[19][2]);
         glVertex3f(points[16][0],points[16][1],points[16][2]);
    glEnd();

    //Cara Ala Izq 2
    glBegin(GL_LINES);
        glVertex3f(points[20][0],points[20][1],points[20][2]);
        glVertex3f(points[21][0],points[21][1],points[21][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[21][0],points[21][1],points[21][2]);
        glVertex3f(points[22][0],points[22][1],points[22][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[22][0],points[22][1],points[22][2]);
        glVertex3f(points[23][0],points[23][1],points[23][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[23][0],points[23][1],points[23][2]);
         glVertex3f(points[20][0],points[20][1],points[20][2]);
    glEnd();

    //Cara Ala Der 2
    glBegin(GL_LINES);
        glVertex3f(points[24][0],points[24][1],points[24][2]);
        glVertex3f(points[25][0],points[25][1],points[25][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[25][0],points[25][1],points[25][2]);
        glVertex3f(points[26][0],points[26][1],points[26][2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(points[26][0],points[26][1],points[26][2]);
        glVertex3f(points[27][0],points[27][1],points[27][2]);
    glEnd();

    glBegin(GL_LINES);
         glVertex3f(points[27][0],points[27][1],points[27][2]);
         glVertex3f(points[24][0],points[24][1],points[24][2]);
    glEnd();

}

void XWing::escala(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->E);

    Op3D->E[0][0]=puntos[0];
    Op3D->E[1][1]=puntos[1];
    Op3D->E[2][2]=puntos[2];

    Op3D->MultM(myA,Op3D->E,myA);
    Op3D->MatObject(myA,28,points);
}

void XWing::traslation(float puntos[3])
{
    Op3D->LoadIdentity(Op3D->T);

    Op3D->T[0][3]=puntos[0];
    Op3D->T[1][3]=puntos[1];
    Op3D->T[2][3]=puntos[2];

    Op3D->MultM(myA,Op3D->T,myA);
    Op3D->MatObject(myA,28,points);
}

 void XWing::rotation(float theta, float p1[3], float p2[3])
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
    Op3D->MatObject(myA,28,points);
}

void XWing::updateAnimation()
 {

 }



