//
// Created by tcous on 02/11/2019.
//

#ifndef PROJET_CPP_2019_BIGLAZYBROTHER_AFFICHAGE_H
#define PROJET_CPP_2019_BIGLAZYBROTHER_AFFICHAGE_H

#include <SFML/Graphics.hpp>

class Affichage {
protected:
    //FENÊTRE
    sf::RenderWindow * ptrWindow;
    //POUR LES TEXTURES
    sf::Texture texturePersonage;
    sf::Texture textureArrierePlan;
    sf::Texture textureAvantPlan;
    //POUR LES SPRITES
    float positionSpriteSheriff; // = 100
    sf::Sprite spriteSheriff;
    float positionSpriteGangster; // = 1020
    sf::Sprite spriteGangster;
    sf::Sprite arrierePlan;
    sf::Sprite avantPlan;

public:
    Affichage();
    virtual ~Affichage();
    void initialisation();
    void instancierPtrWindow(sf::RenderWindow& window);
    void sheriffAttaque();
    void gangsterAttaque();
    void sheriffFuit();
    void gangsterFuit();
    void sheriffAuRepos();
    void gangsterAuRepos();
    void sheriffMarche(float);
    void gangsterMarche(float);
    void affiche();
};


#endif //PROJET_CPP_2019_BIGLAZYBROTHER_AFFICHAGE_H
