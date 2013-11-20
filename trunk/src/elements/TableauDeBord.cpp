/*
 * TableauDeBord.cpp
 *
 *  TowerDefense ECP
 *
 *  Gere l'affichage des elements du menu de droite pour la gestion des batiments
 *
 *      
 */

#include "TableauDeBord.h"

TableauDeBord::TableauDeBord() {
	typeSelection = 0;

	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	textureTableauDeBord = pResourcesLoader->textureRessources;
	spriteTableauDeBord.setTexture(textureTableauDeBord);
	spriteTableauDeBord.setScale(1,3);
	spriteTableauDeBord.setPosition(720,100);
	font = pResourcesLoader->policeTableauDeBord;
	texteTableauDeBord.setFont(font);
	texteTableauDeBord.setCharacterSize(48);
	texteTableauDeBord.setColor(sf::Color::White);
	texteTableauDeBord.setStyle(sf::Text::Bold);
	texteTableauDeBord.setPosition(720,0);

	spriteCanonLourd.setTexture(pResourcesLoader->textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(710,300);

	spriteTourAttaqueBasique.setTexture(pResourcesLoader->textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition(760,300);

	spriteTourDeGlace.setTexture(pResourcesLoader->textureTourDeGlace);
	spriteTourDeGlace.setScale(0.5,0.5);
	spriteTourDeGlace.setPosition(710,260);

	spriteMur.setTexture(pResourcesLoader->textureMur);
	spriteMur.setPosition(760,260);

	texteNiveauTour.setFont(font);
	texteNiveauTour.setCharacterSize(7);
	texteNiveauTour.setColor(sf::Color::White);
	texteNiveauTour.setStyle(sf::Text::Bold);
	texteNiveauTour.setPosition(710, 360);

	texteDommagesTour.setFont(font);
	texteDommagesTour.setCharacterSize(7);
	texteDommagesTour.setColor(sf::Color::White);
	texteDommagesTour.setStyle(sf::Text::Bold);
	texteDommagesTour.setPosition(710, 370);

	textureLevelUpBouton = pResourcesLoader->textureLevelUpBouton;
	spriteLevelUpBouton.setTexture(textureLevelUpBouton);
	spriteLevelUpBouton.setScale(0.75, 0.75);
	spriteLevelUpBouton.setPosition(710, 400);

	textureSellBouton = pResourcesLoader->textureSellBouton;
	spriteSellBouton.setTexture(textureSellBouton);
	spriteSellBouton.setPosition(750, 400);

	texteCoutAmelioration.setFont(font);
	texteCoutAmelioration.setCharacterSize(7);
	texteCoutAmelioration.setColor(sf::Color::White);
	texteCoutAmelioration.setStyle(sf::Text::Bold);
	texteCoutAmelioration.setPosition(710, 440);

	textePrixDeVente.setFont(font);
	textePrixDeVente.setCharacterSize(7);
	textePrixDeVente.setColor(sf::Color::White);
	textePrixDeVente.setStyle(sf::Text::Bold);
	textePrixDeVente.setPosition(710,450);

	textureTourSelectionnee = pResourcesLoader->textureSelection;
	spriteTourSelectionnee.setTexture(textureTourSelectionnee);
}

TableauDeBord::~TableauDeBord() {
	// TODO Auto-generated destructor stub
}

void TableauDeBord::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();

	pWindow.draw(spriteTableauDeBord);
	pWindow.draw(texteTableauDeBord);
	pWindow.draw(spriteCanonLourd);
	pWindow.draw(spriteTourAttaqueBasique);
	pWindow.draw(spriteTourDeGlace);
	pWindow.draw(spriteMur);

	if (manager->getBatimentSelectionne()!=0)
	{
		int coordTourX = manager->getBatimentSelectionne()->getCoordonnees().getPosX()-20;
		int coordTourY = manager->getBatimentSelectionne()->getCoordonnees().getPosY()-20;
		spriteTourSelectionnee.setPosition(coordTourX, coordTourY);
		if(manager->getBatimentSelectionne()->isTour())
		{
			Tour* tourSelectionnee = (Tour*)manager->getBatimentSelectionne();
			ostringstream stringNiveauTour;
			stringNiveauTour << tourSelectionnee->getNiveau();
			texteNiveauTour.setString("Niveau tour : " + stringNiveauTour.str());
			pWindow.draw(texteNiveauTour);
			pWindow.draw(spriteLevelUpBouton);

			ostringstream stringCoutAmelioration;
			stringCoutAmelioration << (int)(tourSelectionnee->getPrix()*0.75); // TODO Verifier coherence avec "verifierAmelioration()"
			texteCoutAmelioration.setString("Ameliorer : " + stringCoutAmelioration.str() + "$");
			pWindow.draw(texteCoutAmelioration);

			if(tourSelectionnee->isTourAttaque())
			{
				ostringstream stringDommagesTour;
				stringDommagesTour << ((TourAttaque*)tourSelectionnee)->getDommages();
				texteDommagesTour.setString("Dommages : " + stringDommagesTour.str());

				pWindow.draw(texteDommagesTour);
			}

		}
		ostringstream stringPrixDeVente;
		stringPrixDeVente << (int)(manager->getBatimentSelectionne()->getPrix()*0.75); //TODO Coherence avec "vendreTour()"
		textePrixDeVente.setString("Vendre : " + stringPrixDeVente.str() + "$");
		pWindow.draw(spriteSellBouton);

		pWindow.draw(textePrixDeVente);
		pWindow.draw(spriteTourSelectionnee);
	}
}

void TableauDeBord::setSelectionBat(typeBatiment type) {
	typeSelection = type;

	sf::Color couleurSelection = sf::Color::White;
	sf::Color couleurNormale = sf::Color::White;
	couleurNormale.a = 125;
	if(typeSelection == CANON)
	{
		spriteCanonLourd.setColor(couleurSelection);
		spriteTourAttaqueBasique.setColor(couleurNormale);
		spriteTourDeGlace.setColor(couleurNormale);
		spriteMur.setColor(couleurNormale);
	}
	else if(typeSelection == BASIQUE)
	{
		spriteTourAttaqueBasique.setColor(couleurSelection);
		spriteTourDeGlace.setColor(couleurNormale);
		spriteCanonLourd.setColor(couleurNormale);
		spriteMur.setColor(couleurNormale);
	}
	else if(typeSelection == FROST)
	{
		spriteTourAttaqueBasique.setColor(couleurNormale);
		spriteTourDeGlace.setColor(couleurSelection);
		spriteCanonLourd.setColor(couleurNormale);
		spriteMur.setColor(couleurNormale);
	}
	else if(typeSelection == AUCUN)
	{
		spriteTourAttaqueBasique.setColor(couleurNormale);
		spriteTourDeGlace.setColor(couleurNormale);
		spriteCanonLourd.setColor(couleurNormale);
		spriteMur.setColor(couleurNormale);
	}
	else if(typeSelection == MUR)
	{
		spriteTourAttaqueBasique.setColor(couleurNormale);
		spriteTourDeGlace.setColor(couleurNormale);
		spriteCanonLourd.setColor(couleurNormale);
		spriteMur.setColor(couleurSelection);
	}

}
