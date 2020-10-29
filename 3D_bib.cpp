/*
*	2do parcial de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "3D_bib.h"

Operaciones3D::Operaciones3D()
{
        //Variables para operaciones trigonometricas
        pi = 3.14159265359;
}


//recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
//se aplica la formula r
float Operaciones3D::RadToDeg(float r)
{
      return ((180*r)/pi);
}

float Operaciones3D::DegToRad(float g)
{
      return ((g*pi)/180);
}

//Return a dado por x2-x1/v
float Operaciones3D::getA(float P1[3], float P2[3], float v){
    //float a = 0;
    return ((P2[0]-P1[0])/v);
}

//Return a dado por y2-y1/v
float Operaciones3D::getB(float P1[3], float P2[3], float v){
    //float a = 0;
    return ((P2[1]-P1[1])/v);
}

//Return a dado por z2-z1/v
float Operaciones3D::getC(float P1[3], float P2[3], float v){
    //float a = 0;
    return ((P2[2]-P1[2])/v);
}

//Return a dado por x2-x1/v
float Operaciones3D::getD(float b, float c){
    //float a = 0;
    return sqrt(pow(b,2) + pow(c,2));
}

float Operaciones3D::normal(float P1[3], float P2[3]){
    float v = 0;
    for(int i = 0; i < 3; i++)
        v += pow(P2[i] - P1[i],2);
    return sqrt(v);
}

void Operaciones3D::LoadIdentity(float M[][4])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(i==j)
                M[i][j]=1;
            else
                M[i][j]=0;
 }

void Operaciones3D::translate(float x, float y, float z)
{
    LoadIdentity(T);
    T[0][3]=x;
    T[1][3]=y;
    T[2][3]=z;

    MultM(T,A,A);
 }

void Operaciones3D::rotateX(float deg)
{
    LoadIdentity(R);
    R[1][1] = cos(deg);
    R[1][2] = -1*sin(deg);
    R[2][1] = sin(deg);
    R[2][2] = cos(deg);
 }

 void Operaciones3D::rotateXFree(float d, float b, float c)
{
    LoadIdentity(R);
    R[1][1] = c/d;
    R[1][2] = (-1*b)/d;
    R[2][1] = b/d;
    R[2][2] = c/d;
}

void Operaciones3D::rotateY(float deg)
{
    LoadIdentity(R);
    R[0][0] = cos(deg);
    R[0][2] = sin(deg);
    R[2][0] = -1*sin(deg);
    R[2][2] = cos(deg);
 }

 void Operaciones3D::rotateYFree(float a, float normal)
 {
    LoadIdentity(R);
    R[0][0] = normal;
    R[0][2] = a;
    R[2][0] = -1*a;
    R[2][2] = normal;
 }

void Operaciones3D::rotateZ(float deg)
{
    LoadIdentity(R);
    R[0][0] = cos(deg);
    R[0][1] = -1*sin(deg);
    R[1][0] = sin(deg);
    R[1][1] = cos(deg);
 }

 void Operaciones3D::scale(float x, float y, float z)
 {
    LoadIdentity(E);
    E[0][0]=x;
    E[1][1]=y;
    E[2][2]=z;

    MultM(E,A,A);
 }

void Operaciones3D::MultM(float M1[][4], float M2[][4], float Res[][4])
{
  float tmp[4][4];
  int i,j,k;
  for(i=0; i<4;i++)
     for(j=0;j<4;j++){
        tmp[i][j]=0;
        for(k=0;k<4;k++)
           tmp[i][j]+=M1[i][k]*M2[k][j];
     }
  for(i=0;i<4;i++)
     for(j=0;j<4;j++)
        Res[i][j] = tmp[i][j];
}

//multiplica la matriz m por el punto p y regresa el resultado en el punto p
void Operaciones3D::MatPoint(float m[][4], float p[3])
{
  float tmp[4];
  int i,j;
  for(i=0; i<3; i++)
    { tmp[i] = p[i];
      p[i] = 0;
    }
  tmp[3]=1;
  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
        p[i] += m[i][j]*tmp[j];
}

//multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
void Operaciones3D::MatObject(float m[][4], int size, float p[][3])
{
     int i;
     for(i=0; i<size; i++)
       MatPoint(m,p[i]);
}

//rotacion paralela a uno de los ejes
//theta: angulo de rotacion;
//distA,distB: vector (distA,distB) que separa al eje de rotacion del objeto
//con respecto a uno de los ejes del sistema carteciano. Si el eje es:
//X: (distA,distB) es el vector (0,distA,distB)
//Y: (distA,distB) es el vector (distA,0,distB)
//Z: (distA,distB) es el vector (distA,distB,0)
void Operaciones3D::RotacionParalela(char eje, float theta, float distA, float distB)
{
     switch(eje){
        case 'X':
             //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(0,-distA,-distB);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateX(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(0,distA,distB);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
        case 'Y':
             //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(-distA,0,-distB);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateY(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(distA,0,distB);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
        case 'Z':
             //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(-distA,-distB,0);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateZ(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(distA,distB,0);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
     }
}

//Proceso de rotacion libre por la multiplicacion de las 7 matrices necesarias
void Operaciones3D::rotateXYZ(float theta, float p1[3], float p2[3])
{
    float point1, point2, point3;

    for(int i = 0;i < 3;i++){
        point1 = p1[0];
        point2 = p1[1];
        point3 = p1[2];
    }

    float v = normal(p1, p2);
    float a = getA(p1,p2,v);
    float b = getB(p1,p2,v);
    float c = getC(p1,p2,v);
    float d = getD(b,c);

    translate(-1*point1,-1*point2,-1*point3);
    rotateXFree(d,b,c);
    MultM(R,T,A);
    rotateYFree(a,d);
    MultM(R,A,A);
    rotateZ(DegToRad(theta));
    MultM(R,A,A);
    rotateYFree(-1*a,d);
    MultM(R,A,A);
    rotateXFree(d,-1*b,c);
    MultM(R,A,A);
    translate(point1,point2,point3);
    MultM(T,A,A);
}

void Matriz::setMatriz(float A[][4])
{
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            M[i][j] = A[i][j];
        }
    }
}

void Operaciones3D::push()
{
    Matriz temp;

    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            temp.M[i][j] = A[i][j];
        }
    }
    mystack.push(temp);
}

void Operaciones3D::pop(){
    Matriz temp;

    temp = mystack.top();
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            A[i][j] = temp.M[i][j];
        }
    }
    mystack.pop();
}
