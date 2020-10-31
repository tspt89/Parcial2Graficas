/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef ESCENARIO_H
#define ESCENARIO_H

class Escenario{
public:
	int ship1 = 10;
	Escenario();
	void draw();
private:
	void accAnim1();
	void fireLaser1();
	void rotateSphere();
	void rotateNave1();
	void fireLaser2();

};



#endif
