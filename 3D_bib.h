/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef BIB
#define BIB

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stack>
#include "iostream"

using namespace std;

class Matriz{

public:
    float M[4][4];

    void setMatriz(float A[][4]);   //*
    void getMatriz();               //*
    float getValue(int i, int j);   //*
};

class Operaciones3D{
  private:
      //*
        //Funcion que carga el vector de traslacion en la matriz T
        //void translate_R(float x, float y, float z);
        //Funcion que define la matriz de rotacion con rspecto al eje X
        //void rotateX_R(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Y
        //void rotateY_R(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Z
        //void rotateZ_R(float deg);
		//...

  public:
        //Variables para matrices de rotacion y traslación
        float T[4][4], R[4][4], E[4][4], A[4][4];
        //
        //Variables para operaciones trigonometricas
        float pi;
        //Pila para el manejo de estados
        //*
        stack<Matriz> mystack;

        Operaciones3D();
        //Transformacion de grados a radianes
        //recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
        //se aplica la formula r
        float RadToDeg(float r);
        float DegToRad(float g);
        //obtencion de valores para la rotacion libre
        float getA(float P1[3], float P2[3], float n);  //*
        float getB(float P1[3], float P2[3], float n);  //*
        float getC(float P1[3], float P2[3], float n);  //*
        float getD(float b, float c);                   //*
        float normal(float P1[3], float P2[3]);         //*
        //Funcion para cargar la matriz identidad en la matriz que se recibe como parametro
        void LoadIdentity(float M[][4]);
        //Funcion que carga el vector de traslacion en la matriz T
        void translate(float x, float y, float z);
        //Funcion que define la matriz de rotacion con rspecto al eje X
        void rotateX(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Y
        void rotateY(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Z
        void rotateZ(float deg);
        //Rotacion libre a partir del eje de rotacion definido por los puntos
        //p1 y p2 y theta grados en sentido contrario a las manecillas del reloj
        //La matriz resultante queda almacenada en la matriz A
        void rotateXFree(float d, float b, float c);        //*
        void rotateYFree(float a, float norma);             //*
        //Rotacion libre
        void rotateXYZ(float theta, float p1[3], float p2[3]);
        //Funcion que carga la matriz de escala en la matriz E
        void scale(float x, float y, float z);

        //Funcion que multiplica la matriz M1 con la matriz M2, donde el resultado es Res
        void MultM(float M1[][4], float M2[][4], float Res[][4]);
		//...
        //multiplica la matriz m por el punto p y regresa el resultado en el punto p
        void MatPoint(float m[][4], float p[3]);
        //multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
        void MatObject(float m[][4], int size, float p[][3]);

		//Rotacion paralela a uno de los ejes
        //eje: eje de referencia
        //theta: angulo de rotacion
        void RotacionParalela(char eje, float theta, float distA, float distB);
        //(distA,distB): distancia del eje de rotacion al eje refrencia del sistema
        //La matriz resultante queda almacenada en la matriz A
        //void RotacionParalela(char eje, float theta, float distA, float distB);

        //manejo de una pila
        void push();
        void pop();
        void Temp();

        //
        void LoadIdentity();
};

#endif // BIB
