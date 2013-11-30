#ifndef TESTSUNITAIRES_H_
#define TESTSUNITAIRES_H_
#include <gtest/gtest.h>
#include "elements/Carte.h"
#include "elements/Ressources.h"
#include "elements/Projectiles/Missile.h"
#include "elements/Personnages/SuperPersonnage.h"
#include "App.h"
#include "elements/Vague.h"

// test Coordonnees
TEST(CoordonneesTest, InputNumber) {
	Coordonnees *coord = new Coordonnees(5,3);
	EXPECT_EQ(5, coord->getPosX()); 
	EXPECT_EQ(3, coord->getPosY());
	coord->setPosX(4);
	coord->setPosY(8);
	EXPECT_EQ(4, coord->getPosX()); 
	EXPECT_EQ(8, coord->getPosY());
	delete coord;
}

// test Carte et Case
TEST(NettoyerCarteTest, InputNumber2) {
	Carte *carte = new Carte();
	EXPECT_FALSE(carte->imageCarte[3][4]->isParcourue());
	EXPECT_FALSE(carte->imageCarte[3][4]->isParcourue());
	EXPECT_EQ(0, carte->imageCarte[3][4]->getDistanceEntree());
	EXPECT_EQ(12, carte->imageCarte[14][5]->getHeuristique()); 
	carte->nettoyerCarte();
	EXPECT_FALSE(carte->imageCarte[3][4]->isParcourue()); 
	EXPECT_EQ(0, carte->imageCarte[5][1]->getDistanceEntree()); 
	EXPECT_NE(1, carte->imageCarte[1][1]->getDistanceEntree());
	delete carte;
}

//test Ressources
TEST(RessourcesTest, InputNumber3){
	Ressources* ressources = new Ressources();
	EXPECT_EQ(200,ressources->getArgent());
	ressources->gagnerArgent(100);
	ressources->perdreArgent(40);
	EXPECT_EQ(260,ressources->getArgent());
	EXPECT_EQ(30,ressources->getVie());
	ressources->perdreVie();
	EXPECT_EQ(29,ressources->getVie());
	EXPECT_EQ(0,ressources->getScore());
	ressources->augmenterScore(99);
	EXPECT_EQ(99,ressources->getScore());
	delete ressources;
}

// test Missile
TEST(MissileToucherTest,InputNumber){
	Coordonnees coordonneesBoss(40,40);
	Coordonnees coordonneesMissile(50,40);
	SuperPersonnage * boss = new SuperPersonnage(300,2,8,300,coordonneesBoss);
	Missile * missile = new Missile(coordonneesMissile,boss,10,40);
	ResourceManager* resourceManager = ResourceManager::getInstance();
	resourceManager->addPersonnage(boss);
	EXPECT_EQ(40,boss->getCoordonnees().getPosX());
	EXPECT_EQ(40,boss->getCoordonnees().getPosY());
	EXPECT_EQ(50,missile->getCoordonnees().getPosX());
	EXPECT_EQ(40,missile->getCoordonnees().getPosY());
	missile->agir();
	missile->agir();
	missile->agir();
	missile->agir();
	EXPECT_EQ(298,boss->getVie());
	EXPECT_EQ(40,boss->getCoordonnees().getPosX());
	EXPECT_EQ(40,boss->getCoordonnees().getPosY());
	resourceManager->removePersonnage(boss);
	delete boss,resourceManager;
}

// test de l'algo mis en con
TEST(AlgoTest,algo1){
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	App * app =new App();
	app->window.close();
	EtatJeu * etatJeu = new EtatJeu(app);
	Vague * vague = new Vague(8);
	vague->genererPersonnage();
	EXPECT_EQ(31, ((ResourceManager->getPersonnage())[0])->getTailleChemin());
	EXPECT_EQ(300, ((ResourceManager->getPersonnage())[0])->getVie());
	// on verifie au passage, que le personnage fonctionne correctement. Ici qu'il perd bien sa vie
	((ResourceManager->getPersonnage())[0])->perdrePV(50);
	EXPECT_EQ(258, ((ResourceManager->getPersonnage())[0])->getVie());
	// on verifie aussi que son chemin efface bien les cases qu'il a parcourues
	for (int i=0;i<21;i++){
		((ResourceManager->getPersonnage())[0])->avancer();
	}
	EXPECT_EQ(30, ((ResourceManager->getPersonnage())[0])->getTailleChemin());
	// enfin, on verifie sa mort
	Ressources * ressources = new Ressources();
	ResourceManager->addRessources(ressources);
	((ResourceManager->getPersonnage())[0])->mourir();
	EXPECT_EQ(0,(ResourceManager->getPersonnage()).size());
	delete vague,etatJeu,app,ResourceManager;
}
// test simple sur l'algo
TEST(AlgoTest,algo2){
	Coordonnees coordonneesBoss(0,0);
	SuperPersonnage * boss = new SuperPersonnage(300,2,8,300,coordonneesBoss);
	Carte *carte = new Carte();
	(carte->imageCarte[0][3])->setOccupee(true);
	(carte->imageCarte[1][2])->setOccupee(true);
	(carte->imageCarte[2][1])->setOccupee(true);
	(carte->imageCarte[3][0])->setOccupee(true);
	EXPECT_FALSE(boss->trouverChemin(carte));
	delete carte, boss;
}
// test simple sur l'algo
TEST(AlgoTest,algo3){
	Coordonnees coordonneesBoss(0,0);
	SuperPersonnage * boss = new SuperPersonnage(300,2,8,300,coordonneesBoss);
	Carte *carte = new Carte();
	(carte->imageCarte[0][3])->setOccupee(true);
	(carte->imageCarte[1][2])->setOccupee(true);
	(carte->imageCarte[2][1])->setOccupee(true);
	EXPECT_TRUE(boss->trouverChemin(carte));
	delete carte, boss;
}
// test simple sur l'algo
TEST(AlgoTest,algo4){
	Coordonnees coordonneesBoss(680,40);
	SuperPersonnage * boss = new SuperPersonnage(300,2,8,300,coordonneesBoss);
	Carte *carte = new Carte();
	(carte->imageCarte[16][1])->setOccupee(true);
	(carte->imageCarte[16][2])->setOccupee(true);
	bool isitpossible = boss->trouverChemin(carte);
	EXPECT_TRUE(isitpossible);
	boss->ecrireChemin(carte);
	EXPECT_EQ(13,boss->getTailleChemin());
	(carte->imageCarte[17][3])->setOccupee(true);
	isitpossible = boss->trouverChemin(carte);
	boss->ecrireChemin(carte);
	EXPECT_TRUE(isitpossible);
	EXPECT_EQ(19,boss->getTailleChemin());
	delete carte, boss;
}

#endif /* TESTSUNITAIRES_H_ */