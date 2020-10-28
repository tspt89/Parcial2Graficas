#ifndef ESCENARIO_H
#define ESCENARIO_H

class Escenario{
public:
	int ship1 = 10;
	Escenario();
	draw();
private:
	void accAnim1();
	void fireLaser1();
	void rotateSphere();
	void rotateNave1();
	void fireLaser2();

};



#endif
