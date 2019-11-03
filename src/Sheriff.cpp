#include "Sheriff.h"

Sheriff::Sheriff() {
	this->etoile = false;
}

Sheriff::~Sheriff() {
	delete cible;
}

void Sheriff::metSonEtoile() {
	this->etoile = true;
}

void Sheriff::perdSonEtoile() {
	this->etoile = false;
}

bool Sheriff::aSonEtoile() {
	return this->etoile;
}

//Surcharge d'opérateur
//Sheriff& Sheriff::operator++(int) {
//    this->courage++;
//    return (*this);
//}

//On a hérité de exporterChamps() de Gentil

string Sheriff::exporter() {
	stringstream futurXml;
	futurXml << "\t<Sheriff>\n";
	futurXml << "\t\t<etoile>" << this->etoile << "</etoile>\n";
	futurXml << Gentil::exporterChamps();
	futurXml << "\t</Sheriff>\n";
	return futurXml.str();
}
