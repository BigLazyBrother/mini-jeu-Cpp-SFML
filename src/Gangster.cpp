#include "Gangster.h"

Gangster::Gangster() {
	this->mitraillette = false;
}

Gangster::~Gangster() {
	delete cible;
}

void Gangster::prendSaMitraillette() {
	this->mitraillette = true;
}

void Gangster::perdSaMitraillette() {
	this->mitraillette = false;
}

bool Gangster::aSaMitraillette() {
	return this->mitraillette;
}

// Surcharge d'opérateur
//Gangster& Gangster::operator++(int) {
//    this->lachete++;
//    return (*this);
//}

//On a hérité de exporterChamps() de Mechant

string Gangster::exporter() {
	stringstream futurXml;
	futurXml << "\t<Gangster>\n";
	futurXml << "\t\t<mitraillette>" << this->mitraillette << "</mitraillette>\n";
	futurXml << Mechant::exporterChamps();
	futurXml << "\t</Gangster>\n";
	return futurXml.str();
}
