//============================================================================
// Name        : ProjetLuckyLukeLocal.cpp
// Author      : Théo Cousson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string> //peut-être déjà dans des fichiers .h ?

#include "Gentil.h"
#include "Mechant.h"
#include "Sheriff.h"
#include "Gangster.h"

#include "Affichage.h"

using namespace std;

int main() {

    //TEST GRAPHIQUE

    //On crée les éléments graphiques
    Affichage ecran;
    ecran.initialisation();

    //on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(1400, 980), "Projet \"Lucky Luke\" – Programmation de mondes virtuels");
    ecran.instancierPtrWindow(window);

    //On crée les éléments de jeu
    //Sheriff sheriff;
    Gentil * sheriff = new Sheriff();
    sheriff->setNom("Don Camillo");

    //Gangster gangster;
    Mechant * gangster = new Gangster();
    gangster->setNom("Péppone");

    sheriff->prendUneCible(gangster);
    gangster->prendUneCible(sheriff);

    //normalement, ces deux valeur doivent être identiques :
    //cout << "&sheriff : "<< &sheriff << "; gangster.aPourCible() : " << gangster.aPourCible() << endl;
    //idem ici :
    //cout << "&gangster :" << &gangster << "; sheriff.aPourCible() : " << sheriff.aPourCible() << endl;

    cout << "La cible de " << sheriff->getNom() << " est " << sheriff->aPourCible()->getNom() << endl;
    cout << "La cible de " << gangster->getNom() << " est " << gangster->aPourCible()->getNom() << endl;

    int personnageSelectionne = 0; //perso de gauche : Sheriff == 0, perso de droite : Gangster == 1;

    //Boucle de jeu, "tant que la fenêtre est ouverte"
    while (window.isOpen()) {
        //vérif de tous les events qui ont eu lieu depuis la dernière itération
        sf::Event event;
        while (window.pollEvent(event)) {
            //L'action effectuée dépend du type de l'event
            switch (event.type) {
                //fermeture de la fenêtre
                case sf::Event::Closed:
                    window.close();
                    break;

                    //https://en.sfml-dev.org/tutorials/2.5/window-events.php
                //pression d'une touche
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::A:
                            if (personnageSelectionne == 0) {
                                sheriff->perdLeSourire();
                                sheriff->metSonEtoile();

                                cout << sheriff->getNom() << " attaque " << sheriff->aPourCible()->getNom() << "\n"
                                     << sheriff->aPourCible()->getNom() << " ne se laisse pas faire." << endl;

                                ecran.sheriffAttaque();
                            } else {
                                gangster->prendUnCacheOeil();
                                gangster->prendSaMitraillette();

                                cout << gangster->getNom() << " attaque " << gangster->aPourCible()->getNom() << "\n"
                                     << gangster->aPourCible()->getNom() << " cède à la violence." << endl;

                                ecran.gangsterAttaque();
                            }

                            //sheriff++; //Depuis la mise en place de pointeurs vers Gentil et Mechant, la surcharge d'opérateur fait planter le programme.
                            sheriff->setCourage(sheriff->getCourage()+1);

                            break;

                        case sf::Keyboard::E:
                            //on ne change pas l'état, on l'affiche.
                            if(sheriff->aSonEtoile()) cout << sheriff->getNom() << " a son étoile." << endl;
                            else cout << sheriff->getNom() << " n'a pas son étoile." << endl;
                            if(gangster->aSaMitraillette()) cout << gangster->getNom() << " a sa mitraillette." << endl;
                            else cout << gangster->getNom() << " n'a pas sa mitraillette." << endl;

                            cout << sheriff->getNom() << " a " << sheriff->getCourage() << " points de courage." << endl
                                 << gangster->getNom() << ", quant à lui, a " << gangster->getLachete() << " points de lacheté." << endl;

                            //Pas de changement des sprites
                            //D'ailleurs, cette fonction est obsolète avec l'interface graphique…
                            break;

                        case sf::Keyboard::F:
                            if (personnageSelectionne == 0) {
                                cout << sheriff->getNom() << " fuis " << sheriff->aPourCible()->getNom() << "! \n"
                                     << sheriff->aPourCible()->getNom() << " l'aura une prochaine fois." << endl;
                                ecran.sheriffFuit();
                            } else {
                                cout << gangster->getNom() << " fuis " << gangster->aPourCible()->getNom() << "! \n"
                                     << gangster->aPourCible()->getNom() << " l'aura une prochaine fois." << endl;
                                ecran.gangsterFuit();
                            }

                            //gangster++; //Depuis la mise en place de pointeurs vers Gentil et Mechant, la surcharge d'opérateur fait planter le programme.
                            gangster->setLachete(gangster->getLachete()+1);

                            break;

                        case sf::Keyboard::R:
                            if (personnageSelectionne == 0) {
                                sheriff->prendLeSourire();
                                sheriff->perdSonEtoile();
                                ecran.sheriffAuRepos();
                            } else {
                                gangster->perdSonCacheOeil();
                                gangster->perdSaMitraillette();
                                ecran.gangsterAuRepos();
                            }

                            cout << gangster->getNom() << " et " << gangster->aPourCible()->getNom() << " font une trève." << endl;

                            break;

                        case sf::Keyboard::Space:
                            //Changement de personnage pour le contrôle du déplacement.
                            if (personnageSelectionne == 0) personnageSelectionne = 1;
                            else personnageSelectionne = 0;
                            break;

                        case sf::Keyboard::Left:
                            //Déplacement du personnage sélectionné vers la gauche.
                            if (personnageSelectionne == 0) {
                                ecran.sheriffMarche(-3);
                                //spriteSheriff.setPosition(positionSpriteSheriff, 500);
                            } else {
                                ecran.gangsterMarche(-3);
                                //spriteGangster.setPosition(positionSpriteGangster, 500);
                            }
                            break;

                        case sf::Keyboard::Right:
                            //Déplacement du personnage sélectionné vers la droite.
                            if (personnageSelectionne == 0) {
                                ecran.sheriffMarche(3);
                                //spriteSheriff.setPosition(positionSpriteSheriff, 500);
                            } else {
                                ecran.gangsterMarche(3);
                                //spriteGangster.setPosition(positionSpriteGangster, 500);
                            }
                            break;

                        case sf::Keyboard::Q:
                            window.close();
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }

        //on actualise l'affichage.
        ecran.affiche();
    }

	//on se prépare à l'écriture de nos éléments XML dans un fichier de sauvegarde
	string cheminFichier = "fichier.txt";
	ofstream fichierSortie;

	fichierSortie.open(cheminFichier, ofstream::out | ofstream::app);

	fichierSortie << "<Personnages>\n" << sheriff->exporter() << gangster->exporter() << "</Personnages>\n";

	fichierSortie.close();

	cout << "La partie a été sauvegardée dans le fichier " << cheminFichier << endl;

	//Il faura voir pour éviter les fuites mémoire.

	return 0;
}

