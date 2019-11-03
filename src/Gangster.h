#ifndef GANGSTER_H_
#define GANGSTER_H_
#include "Mechant.h"
#include "Gentil.h"

using namespace std;

class Gangster : public Mechant { //Relation d'héritage
protected:
	bool mitraillette;

	Gentil * cible = 0; // Ne jamais déclarer un pointeur sans lui donner d'adresse !

public:
	Gangster();
	virtual ~Gangster();

	void prendSaMitraillette();
	void perdSaMitraillette();
	bool aSaMitraillette();

	string exporter();

	//Surcharge d'opérateur
	//Gangster& operator++(int);
};

#endif /* GANGSTER_H_ */
