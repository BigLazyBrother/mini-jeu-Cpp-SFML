#ifndef SHERIFF_H_
#define SHERIFF_H_
#include "Gentil.h"
#include "Mechant.h"

using namespace std;

class Sheriff : public Gentil { //Relation d'héritage
protected:
	bool etoile;

	Mechant * cible = 0; // Ne jamais déclarer un pointeur sans lui donner d'adresse !

public:
	Sheriff();
	virtual ~Sheriff();

	void metSonEtoile();
	void perdSonEtoile();
	bool aSonEtoile();

	string exporter();

	//Surcharge d'opérateur
	//Sheriff& operator++(int);
};

#endif /* SHERIFF_H_ */
