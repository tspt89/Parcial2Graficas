/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "Escenario.h"
#include "3D_bib.h"
#include "Cube.h"
#include "Sphere.h"
#include "XWing.h"
#include "Acclamator.h"
#include <unistd.h>

//Variables de Control para Acclamator
float dyAcc=0,dzAcc=0,gradAcc=0;
bool sube = true;

//Variables de Control para Laser1
bool drawLaser = false;
float dyLaser1=0,dxLaser1=0,gradLaser1=0;

//Variables para Sphere
float angSphere=0;

//Variables para xWing
float angNave1 = 0;

//Variables para lasers en xWing2
float dzLasers2 = 0;

Escenario::Escenario(){
}

void Escenario::accAnim1(){
	if(dyAcc < ship1 && sube){
		dyAcc+= 0.1;
		dzAcc+=0.05;
		gradAcc++;
	}else if(dyAcc > 0 && !sube){
		dyAcc-= 0.1;
		dzAcc-=0.05;
		gradAcc--;
	} else
		sube = !sube;

	if(dyAcc <=0 && !sube)
		drawLaser = true;
}

void Escenario::fireLaser1(){
	if(dyLaser1 < 20){
		dyLaser1 +=0.7;
		dxLaser1 +=0.2;
	} else {
		dyLaser1 = 0;
		dxLaser1 = 0;
		drawLaser = false;
	}

}

void Escenario::rotateSphere(){
	if(angSphere < 360)
		angSphere++;
	else
		angSphere = 0;
}

void Escenario::rotateNave1(){
	if(angNave1<360)
		angNave1+=2;
	else
		angNave1 = 0;
}

void Escenario::fireLaser2(){
	if(dzLasers2 < 20)
		dzLasers2+=0.2;
	else
		dzLasers2 = 0;
}

void Escenario::draw(){
	float points3 []= {0.0,0.0,0.0};
	float points4 []= {1.0,1.0,1.0};
    float points5 [] = {0.0, dyAcc, dzAcc};
	//Se declara el objeto para utilizar las operaciones 3D
	Operaciones3D Op3D;
	Cube myCb1(&Op3D);
	Cube myCb2(&Op3D);
	Cube myCb3(&Op3D);
	Cube myCb4(&Op3D);
	Cube myCb5(&Op3D);
	Cube myCb6(&Op3D);
	Sphere mySp(&Op3D);
	XWing myXW1(&Op3D);
	XWing myXW2(&Op3D);
	Acclamator myAcc(&Op3D);

	accAnim1();



    //Draw acclamator
    Op3D.push();
    glColor3f(1.0f,1.0f,1.0f);
    Op3D.rotateXYZ(gradAcc,points3,points4);
    Op3D.translate(20.0,0.0,0.0);
    //printf("DY: %5.5f, DZ: %5.5f, GRAD: %5.5f\n",dyAcc,dzAcc,gradAcc);
    myAcc.traslation(points5);
    Op3D.scale(1.0,1.5,1.5);
    myAcc.draw();
    Op3D.pop();

    //Laser 1
    Op3D.push();
    glColor3f(0.0f,1.0f,0.0f);

    Op3D.rotateXYZ(15,points3,points4);
    Op3D.translate(dxLaser1,10+dyLaser1,0.0);
    Op3D.scale(3.5,0.2,0.2);
    if(drawLaser){
		fireLaser1();
		myCb1.draw();

    }

    Op3D.pop();

    rotateNave1();
    Op3D.push();
    glColor3f(1.0f,0.0f,1.0f);

    float ptNave1[] = {0,0,0};
    float ptNave2[] = {0,1,0};
    float tNav[] = {-20.0,0.0,10.0};
    myXW1.traslation(tNav);
    Op3D.rotateXYZ(angNave1,ptNave1,ptNave2);
	Op3D.scale(0.4,0.4,0.4);
    myXW1.draw();
    Op3D.pop();

    //Laser 3
    Op3D.push();
    glColor3f(0.0f,1.0f,0.0f);
    Op3D.translate(-10.0,0.0,40.0);
    Op3D.scale(1.5,0.2,0.2);
    Op3D.pop();

    Op3D.push();
    glColor3f(1.0f,0.0f,1.0f);
    Op3D.translate(-60.0,5.0,-10.0);
    myXW2.draw();
    Op3D.pop();

    //Laser 4 - de XWING 2
    Op3D.push();
    glColor3f(1.0f,0.0f,0.0f);
    Op3D.scale(0.2,0.2,3);
    Op3D.translate(-62,7,-7+dzLasers2);
    myCb3.draw();
    Op3D.translate(0,-4,0);
    myCb4.draw();
    Op3D.translate(12,0,0);
    myCb5.draw();
    Op3D.translate(0,4,0);
    myCb6.draw();
    Op3D.pop();
    fireLaser2();


    Op3D.push();
    glColor3f(0.5f,0.5f,0.5f);
    float pt3[] = {0.0,0.0,0.0};
    float pt4[] = {0.0,1.0,0.0};
    rotateSphere();
    Op3D.rotateXYZ(angSphere,pt3,pt4);
    mySp.draw();
    Op3D.pop();

    glutSwapBuffers();
}
