/*
 * Coordonnees.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef COORDONNEES_H_
#define COORDONNEES_H_

class Coordonnees {
public:
	Coordonnees(int x,int y);
	virtual ~Coordonnees();

	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);

private:
	int posX;
	int posY;
};

#endif /* COORDONNEES_H_ */
