#ifndef CUBE
#define CUBE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include "iostream"

#include "3D_bib.h"

using namespace std;

class Cube{
private:
	//Aquí van todas las variables y funciones de control del
	//Objeto
    float points[8][3] = {{0,0,0},{2,0,0},{2,0,2},{0,0,2},{0,2,0},{2,2,0},{2,2,2},{0,2,2}};   //Creacion del objeto unitario del tipo cubo
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
    Cube(Operaciones3D *);
    ~Cube();
    void draw();
    //void setRotation(bool);
    //void setTranslation(bool);
    //void setRotation(float axis[3], float deg);
    //void setAxisRotation(float axis[3]);
    //void setDeltaAxisRotation(float delta[3]);
    //void setDegRotation(float deg);
    //void setDeltaDegRotation(float delta);
    //void setAxisTranslation(float axis[3]);
    //void setDeltaAxisTranslation(float delta[3]);
    //void setAnimation(bool value);

    //
    //void escala(float points[3]);
    //void traslation(float points[3]);
    //void rotation(float theta, float P1[3], float P2[3]);
};

#endif
