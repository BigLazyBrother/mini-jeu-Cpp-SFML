#ifndef MECHANT_H_
#define MECHANT_H_
#include <string>
#include <sstream>
#include "Gentil.h"

using namespace std;

class Gentil; //DÉCLARATION AVANCÉE.
class Mechant {
protected:
	string nom;
	int lachete;
	bool cacheOeil;
    Gentil * cible = 0; // Ne jamais déclarer un pointeur sans lui donner d'adresse !

	string exporterChamps();
public:
	Mechant();
	virtual ~Mechant();

	void setNom(string);
	string getNom();

	void setLachete(int);
	int getLachete();

	void prendUnCacheOeil();
	void perdSonCacheOeil();
	bool aUnCacheOeil();

    virtual void prendSaMitraillette();
    virtual void perdSaMitraillette();
    virtual bool aSaMitraillette();

    //void prendUneCible(Gentil&);
    Gentil * aPourCible();

    void prendUneCible(Gentil*);

	virtual string exporter();

	//surcharge d'opérateur
    virtual void operator++();
};

#endif /* MECHANT_H_ */
