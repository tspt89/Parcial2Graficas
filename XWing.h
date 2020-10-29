/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*//*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef XWING
#define XWING

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include "iostream"

#include "3D_bib.h"

using namespace std;

class XWing{
private:
	//Aquí van todas las variables y funciones de control del
	//Objeto
    float points[28][3] = {{0,0,0},{2.3,0,7},{2.7,0,7},{5,0,0}, //0-3 mitad
                            {1,1,0},{2.3,0.3,6.8},{2.7,0.3,6.8},{4,1,0},//4-7 supe
                            {1,-1,0},{2.3,-0.3,6.8},{2.7,-0.3,6.8},{4,-1,0}, //8-11 infe
                            {0,0,1},{-4,3,1.2},{-4,3,1.5},{1,0,3}, //12-15 Ala izq1
                            {5,0,1},{9.5,3,1.2},{9.5,3,1.5},{4.5,0,3}, //16-19 Ala der1
                            {0,0,1},{-4,-3,1.2},{-4,-3,1.5},{1,0,3}, //20-23 Ala izq12
                            {5,0,1},{9.5,-3,1.2},{9.5,-3,1.5},{4.5,0,3} //24-27 Ala der2
    };   //Creacion del objeto unitario del tipo cubo
    float p1[3] = {0.0,0.0,0.0};                                      //
    float p2[3] = {5.0,5.0,-3.0};                                     //
    float angulo = 10;
    //...

    //matriz de control local del objeto
    float myA[4][4];
	//variables de control local del objeto
    bool edo_rotate, edo_translate,state;
    float axis_rotation[3] = {0.0,0.0,1.0};
    float delta_axis_rotation[3] = {0.0,0.0,0.0};
    float deg_rotation = 0.0;
    float delta_deg_rotation = 0.0;
    float axis_translation[3] = {0,0,0};
    float delta_axis_translation[3] = {0.0,0.0,0.0};
	//...

    //control-state variable
    Operaciones3D *Op3D;

    //funciones de la clase
    void squeleton_reset(); //para reiniciar valores por default del objeto
    void updateAnimation(); //para actualizar cuadro por cuadro el edo del objeto
public:
    //funciones publicas de la clase
	//...

    //general functions
    XWing(Operaciones3D *);
    ~XWing();
    void draw();
    void setRotation(bool);
    void setTranslation(bool);
    void setRotation(float axis[3], float deg);
    void setAxisRotation(float axis[3]);
    void setDeltaAxisRotation(float delta[3]);
    void setDegRotation(float deg);
    void setDeltaDegRotation(float delta);
    void setAxisTranslation(float axis[3]);
    void setDeltaAxisTranslation(float delta[3]);
    void setAnimation(bool value);

    //
    void escala(float points[3]);
    void traslation(float points[3]);
    void rotation(float theta, float P1[3], float P2[3]);
};

#endif
