//
// Created by tcous on 02/11/2019.
//

#include "Affichage.h"

Affichage::Affichage() {

}

Affichage::~Affichage() {

}

void Affichage::initialisation() {
    //CHARGEMENT DES TEXTURES

    //sf::Texture texturePersonage;
    texturePersonage.loadFromFile("./sprites.png");

    //sf::Texture textureArrierePlan;
    textureArrierePlan.loadFromFile("./fond.png");

    //sf::Texture textureAvantPlan;
    textureAvantPlan.loadFromFile("./avant.png");

    //CRÉATION DES SPRITES

    //float positionSpriteSheriff = 100;
    //sf::Sprite spriteSheriff;
    spriteSheriff.setTexture(texturePersonage);
    spriteSheriff.setTextureRect(sf::IntRect(0,0,280,280));
    //spriteSheriff.setColor(sf::Color(255, 255, 255, 200));
    spriteSheriff.setPosition(positionSpriteSheriff, 500);

    //float positionSpriteGangster = 1020;
    //sf::Sprite spriteGangster;
    spriteGangster.setTexture(texturePersonage);
    spriteGangster.setTextureRect(sf::IntRect(0,281,280,280));
    //spriteGangster.setColor(sf::Color(255, 255, 255, 200));
    spriteGangster.setPosition(positionSpriteGangster, 500);

    //sf::Sprite arrierePlan;
    arrierePlan.setTexture(textureArrierePlan);
    arrierePlan.setTextureRect(sf::IntRect(0,0,1400,980));
    //arrierePlan.setColor(sf::Color(255, 255, 255, 200));
    arrierePlan.setPosition(0, 0);

    //sf::Sprite avantPlan;
    avantPlan.setTexture(textureAvantPlan);
    avantPlan.setTextureRect(sf::IntRect(0,0,1400,980));
    //avantPlan.setColor(sf::Color(255, 255, 255, 200));
    avantPlan.setPosition(0, 0);

    //Placement des éléments à l'écran :
    positionSpriteSheriff = 100;
    positionSpriteGangster = 1020;
}

void Affichage::instancierPtrWindow(sf::RenderWindow& window){
    ptrWindow = &window;
}

//SPRITES 0:sans rien; 281: pistolets; 561: étoile/cache-œil; 841: pistolets et étoile/cache-œil;

void Affichage::sheriffAttaque() {
    spriteSheriff.setTextureRect(sf::IntRect(841,0,280,280));
}

void Affichage::gangsterAttaque() {
    spriteGangster.setTextureRect(sf::IntRect(841,281,280,280));
}

void Affichage::sheriffFuit() {
    spriteSheriff.setTextureRect(sf::IntRect(561,0,280,280));
}

void Affichage::gangsterFuit() {
    spriteGangster.setTextureRect(sf::IntRect(561,281,280,280));
}

void Affichage::sheriffAuRepos() {
    spriteSheriff.setTextureRect(sf::IntRect(0,0,280,280));
}

void Affichage::gangsterAuRepos() {
    spriteGangster.setTextureRect(sf::IntRect(0,281,280,280));
}

void Affichage::sheriffMarche(float nbPas){
    positionSpriteSheriff+=nbPas;
}

void Affichage::gangsterMarche(float nbPas) {
    positionSpriteGangster+=nbPas;
}

void Affichage::affiche() {
    //on efface le contenu de la fenêtre
    ptrWindow->clear();

    //On repositionne les sprites du Sheriff et du Gangster selon leurs déplacements :
    spriteSheriff.setPosition(positionSpriteSheriff, 500);
    spriteGangster.setPosition(positionSpriteGangster, 500);

    //ici, on dessine tout le contenu à afficher
    //window.draw(shape);
    ptrWindow->draw(arrierePlan);
    ptrWindow->draw(spriteSheriff);
    ptrWindow->draw(spriteGangster);
    ptrWindow->draw(avantPlan);

    //et on l'affiche
    ptrWindow->display();
}