#include "Mechant.h"

Mechant::Mechant() {
    //construsteur vide
    this->cacheOeil = false;
    this->lachete = 0;
    this->nom = "sansNom";
}

Mechant::~Mechant() {
	//destructeur vide
}

void Mechant::setNom(string nom) {
	this->nom = nom;
}

string Mechant::getNom() {
	return this->nom;
}

void Mechant::setLachete(int lachete) {
	this->lachete = lachete;
}

int Mechant::getLachete() {
	return this->lachete;
}

void Mechant::prendUnCacheOeil() {
	this->cacheOeil = true;
}

void Mechant::perdSonCacheOeil() {
	this->cacheOeil = false;
}

bool Mechant::aUnCacheOeil() {
	return this->cacheOeil;
}

string Mechant::exporterChamps() {
	stringstream futurXml;
	futurXml << "\t\t<nom>" << this->nom << "</nom>\n";
	futurXml << "\t\t<lachete>" << this->lachete << "</lachete>\n";
	futurXml << "\t\t<cacheOeil>" << this->cacheOeil << "</cacheOeil>\n";
	return futurXml.str();
}

string Mechant::exporter() {
	stringstream futurXml;
	futurXml << "\t<Mechant>\n";
	futurXml << this->exporterChamps();
	futurXml << "\t</Mechant>\n";
	return futurXml.str();
}

//void Mechant::prendUneCible(Gentil& gentil) {
//    this->cible = &gentil; //c'est déjà une adresse. Pourquoi a-t-on besoin de "&" ?
//}

// Surcharge d'opérateur
void Mechant::operator++() {
    this->lachete++;
}

Gentil * Mechant::aPourCible() {
    return this->cible;
}

void Mechant::prendUneCible(Gentil* gentil) {
    this->cible = gentil;
}

void Mechant::prendSaMitraillette() {
    //this->mitraillette = true;
}

void Mechant::perdSaMitraillette() {
    //this->mitraillette = false;
}

bool Mechant::aSaMitraillette() {
    //return this->mitraillette;
    return false;
}