/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef SPHERE
#define SPHERE

#include "3D_bib.h"
#include <math.h>
#include <GL/glut.h>
class Sphere {

public:
    float radios[11];
	int r;
	float meridiano[180][3];
	float paralelos[11][180][3];

    Sphere(Operaciones3D *);
	void draw();
	void escala(float points[3]);

private:
	Operaciones3D *Op3D;
	float myA[4][4];
	float cp[180][3];
	void getRad();
	void getParalelos();
	void getMeridiano();
};

#endif
