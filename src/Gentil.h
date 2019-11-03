#ifndef GENTIL_H_
#define GENTIL_H_
#include <string>
#include <sstream>
#include "Mechant.h"

using namespace std;

class Mechant; //DÉCLARATION AVANCÉE.
class Gentil {
protected:
	string nom;
	int courage;
	bool souriant;
    Mechant * cible = 0; // Ne jamais déclarer un pointeur sans lui donner d'adresse !

	string exporterChamps();
public:
	Gentil();
	virtual ~Gentil();

	void setNom(string);
	string getNom();

	void setCourage(int);
	int getCourage();

	void prendLeSourire();
	void perdLeSourire();
	bool aLeSourire();

    virtual void metSonEtoile();
    virtual void perdSonEtoile();
    virtual bool aSonEtoile();

    //void prendUneCible(Mechant&);
    Mechant * aPourCible();

    void prendUneCible(Mechant*);

	virtual string exporter();

	//surcharge d'opérateur
    virtual void operator++();
};


#endif /* GENTIL_H_ */
