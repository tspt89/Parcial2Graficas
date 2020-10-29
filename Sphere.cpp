/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/


#include "Sphere.h"

Sphere::Sphere(Operaciones3D *data){
	Op3D = data;
	Op3D->LoadIdentity(Op3D->A);
    Op3D->LoadIdentity(myA);

	this->r = 5;
	this->getRad();
	this->getParalelos();
	this->getMeridiano();
}

//Funcion para obtener los radios de cada paralelo que se encuentra
//dentro de la esfera
void Sphere::getRad(){
	float dRadios = ((float) this->r)/5;
	float rtmp = 0, dr = this->r;
	//Parte central de la esfera
	for(int i=5, j=0; i >= -5; i--, j++){
		rtmp = sqrt(pow(r,2) - pow(dr,2));
		radios[j] = rtmp;
		dr-=dRadios;
	}
}

//Se obtienen los paralelos de acuerdo a los radios previamente calculados
// por la funcion getRad()
void Sphere::getParalelos(){
	float ang = (2 * M_PI) / 180;
	int dr = this->r;
	for(int i=0; i < 11; i++){
		for(int j=0; j < 180; j++){
			paralelos[i][j][0] = radios[i] * cos(j*ang); // Coordenada x
			paralelos[i][j][1] = dr; //Coordenadas en y
			paralelos[i][j][2] = radios[i] * sin(j*ang); // Coordenada z
		}
		dr -= this->r/5;
	}

}

//Se obtiene un meridiano para la esfera
void Sphere::getMeridiano(){

	float ang = (2 * M_PI) / 180;

	for(int i=0; i<180; i++){
		meridiano[i][0] = this->r * cos(i*ang); // Coordenada x
		meridiano[i][1] = this->r * sin(i*ang); // Coordenada y
		meridiano[i][2] = 0;
	}

}

void Sphere::draw(){

	//Se realizan las operaciones para cada paralelo
	for(int i=0; i < 11; i++)
		Op3D->MatObject(Op3D->A,180,this->paralelos[i]);

	//Dibujado de los Paralelos
	for(int j=0; j < 11; j++){
		for(int i=0; i < 179;  i++){
			glBegin(GL_LINES);
				glVertex3f(paralelos[j][i][0],paralelos[j][i][1],paralelos[j][i][2]);
				glVertex3f(paralelos[j][i+1][0],paralelos[j][i+1][1],paralelos[j][i+1][2]);
			glEnd();
		}


	}

	//Se copian meridianos a un arreglo temporal
	for(int j=0; j < 180; j++){
			cp[j][0] = meridiano[j][0];
			cp[j][1] = meridiano[j][1];
			cp[j][2] = meridiano[j][2];
	}
	//Se aplica la matriz al objeto
	Op3D->MatObject(Op3D->A,180,cp);

	//Se dibuja el primer meridiano
	for(int i=0; i<180-1; i++){
			glBegin(GL_LINES);
				glVertex3f(cp[i][0],cp[i][1],cp[i][2]);
				glVertex3f(cp[i+1][0],cp[i+1][1],cp[i+1][2]);
			glEnd();
	}


	//////////////////// Prueba con Meridianos con rotacion libre
	Operaciones3D tmp;
	int nMerid = 5; //Cuantos meridianos se desean graficar
	float angMeridiano = (180) / nMerid; //Division de angulos de 180 entre nMerid para incrementarlo
	float da = angMeridiano; //Variable de control para aumentar los meridianos

	float pt1[3]= {0,0,0};
	float pt2[3]= {0,1,0};

	//Se dibujan los siguientes meridianos de la esfera
	for(int i=0; i < nMerid; i++){
		for(int j=0; j < 180; j++){
			cp[j][0] = meridiano[j][0];
			cp[j][1] = meridiano[j][1];
			cp[j][2] = meridiano[j][2];
		}
		tmp.rotateXYZ(da,pt1,pt2);
		tmp.MatObject(tmp.A,180,cp);
		Op3D->MatObject(Op3D->A,180,cp);
		for(int j=0; j<179; j++){
			glBegin(GL_LINES);
				glVertex3f(cp[j][0],cp[j][1],cp[j][2]);
				glVertex3f(cp[j+1][0],cp[j+1][1],cp[j+1][2]);
			glEnd();
		}

		da += angMeridiano;
	}










}


