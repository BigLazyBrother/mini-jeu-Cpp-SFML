#include "Gentil.h"

Gentil::Gentil() {
	//construsteur vide
	this->souriant = false;
	this->courage = 0;
	this->nom = "sansNom";
}

Gentil::~Gentil() {
	//destructeur vide
}

void Gentil::setNom(string nom) {
	this->nom = nom;
}

string Gentil::getNom() {
	return this->nom;
}

void Gentil::setCourage(int courage) {
	this->courage = courage;
}

int Gentil::getCourage() {
	return this->courage;
}

void Gentil::prendLeSourire() {
	this->souriant = true;
}

void Gentil::perdLeSourire() {
	this->souriant = false;
}

bool Gentil::aLeSourire() {
	return this->souriant;
}

string Gentil::exporterChamps() {
	stringstream futurXml;
	futurXml << "\t\t<nom>" << this->nom << "</nom>\n";
	futurXml << "\t\t<courage>" << this->courage << "</courage>\n";
	futurXml << "\t\t<souriant>" << this->souriant << "</souriant>\n";
	return futurXml.str();
}

string Gentil::exporter() {
	stringstream futurXml;
	futurXml << "\t<Gentil>\n";
	futurXml << this->exporterChamps();
	futurXml << "\t</Gentil>\n";
	return futurXml.str();
}

//void Gentil::prendUneCible(Mechant& mechant) {
//    this->cible = &mechant; //c'est déjà une adresse. Pourquoi a-t-on besoin de "&" ?
//}

//Surcharge d'opérateur
void Gentil::operator++() {
    this->courage++;
    //return (this);
}

Mechant * Gentil::aPourCible() {
    return this->cible;
}

void Gentil::prendUneCible(Mechant* mechant) {
    this->cible = mechant;
}

void Gentil::metSonEtoile() {
    //this->etoile = true;
}

void Gentil::perdSonEtoile() {
    //this->etoile = false;
}

bool Gentil::aSonEtoile() {
    //return this->etoile;
    return false;
}