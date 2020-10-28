#ifndef ACCLMATOR
#define ACCLMATOR

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include "iostream"

#include "3D_bib.h"

using namespace std;

class Acclamator{
private:
	//Aquí van todas las variables y funciones de control del
	//Objeto
    float points[20][3] = {{0,0,0},{0,0,3},{4.8,0,12},{5.2,0,12},{10,0,3},{10,0,0},{5.5,0,0},{5.1,0,-4},{4.9,0,-4},{4.5,0,0},
                            {3.8,1.5,0},{3.8,1.5,3.4},{4.8,0.4,12},{5.2,0.4,12},{6.2,1.5,3.4},{6.2,1.5,0},{5.5,1.5,0},{5.1,1.5,-4},{4.9,1.5,-4},{4.5,1.5,0}
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
    Acclamator(Operaciones3D *);
    ~Acclamator();
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

