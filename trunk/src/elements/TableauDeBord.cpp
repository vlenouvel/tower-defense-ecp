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
	typeSelection = AUCUN;

	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	spriteTableauDeBord.setTexture(pResourcesLoader->textureRessources);
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
	spriteTourAttaqueBasique.setPosition(755,300);

	spriteTourDeGlace.setTexture(pResourcesLoader->textureTourDeGlace);
	spriteTourDeGlace.setScale(0.5,0.5);
	spriteTourDeGlace.setPosition(710,260);

	spriteMur.setTexture(pResourcesLoader->textureMur);
	spriteMur.setScale(0.75,0.75);
	spriteMur.setPosition(735,220);

	spriteTourSupport.setTexture(pResourcesLoader->textureTourSupport);
	spriteTourSupport.setScale(0.5,0.5);
	spriteTourSupport.setPosition(750, 260);

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

	spriteLevelUpBouton.setTexture(pResourcesLoader->textureLevelUpBouton);
	spriteLevelUpBouton.setScale(0.75, 0.75);
	spriteLevelUpBouton.setPosition(710, 400);

	spriteSellBouton.setTexture(pResourcesLoader->textureSellBouton);
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

	spriteTourSelectionnee.setTexture(pResourcesLoader->textureSelection);

	texteComportementPremier.setFont(font);
	texteComportementPremier.setCharacterSize(7);
	texteComportementPremier.setColor(sf::Color::White);
	texteComportementPremier.setStyle(sf::Text::Bold);
	texteComportementPremier.setPosition(710, 470);
	texteComportementPremier.setString("Plus ancien");

	texteComportementMoinsVie.setFont(font);
	texteComportementMoinsVie.setCharacterSize(7);
	texteComportementMoinsVie.setColor(sf::Color::White);
	texteComportementMoinsVie.setStyle(sf::Text::Bold);
	texteComportementMoinsVie.setPosition(710, 480);
	texteComportementMoinsVie.setString("Moins de vie");

	texteComportementZone.setFont(font);
	texteComportementZone.setCharacterSize(7);
	texteComportementZone.setColor(sf::Color::White);
	texteComportementZone.setStyle(sf::Text::Bold);
	texteComportementZone.setPosition(710, 490);
	texteComportementZone.setString("Plus de touches");


	texteComportementRandom.setFont(font);
	texteComportementRandom.setCharacterSize(7);
	texteComportementRandom.setColor(sf::Color::White);
	texteComportementRandom.setStyle(sf::Text::Bold);
	texteComportementRandom.setPosition(710, 500);
	texteComportementRandom.setString("Ciblage aleatoire");

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
	pWindow.draw(spriteTourSupport);
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
				TourAttaque* tourAttaqueSelectionnee = (TourAttaque*)tourSelectionnee;
				texteComportementPremier.setColor(sf::Color::White);
				texteComportementMoinsVie.setColor(sf::Color::White);
				texteComportementZone.setColor(sf::Color::White);
				texteComportementRandom.setColor(sf::Color::White);
				switch(tourAttaqueSelectionnee->getComportement())
				{
				case ComportementCiblage::Premier:
					texteComportementPremier.setColor(sf::Color::Red);
					break;
				case ComportementCiblage::PlusFaible:
					texteComportementMoinsVie.setColor(sf::Color::Red);
					break;
				case ComportementCiblage::Zone:
					texteComportementZone.setColor(sf::Color::Red);
					break;
				case ComportementCiblage::Random:
					texteComportementRandom.setColor(sf::Color::Red);
					break;
				}

				ostringstream stringDommagesTour;
				stringDommagesTour << (tourAttaqueSelectionnee)->getDommages();
				texteDommagesTour.setString("Dommages : " + stringDommagesTour.str());

				pWindow.draw(texteDommagesTour);
				pWindow.draw(texteComportementPremier);
				pWindow.draw(texteComportementMoinsVie);
				pWindow.draw(texteComportementZone);
				pWindow.draw(texteComportementRandom);
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
	spriteCanonLourd.setColor(couleurNormale);
	spriteTourAttaqueBasique.setColor(couleurNormale);
	spriteTourDeGlace.setColor(couleurNormale);
	spriteMur.setColor(couleurNormale);
	spriteTourSupport.setColor(couleurNormale);
	switch(typeSelection)
	{
	case CANON:
		spriteCanonLourd.setColor(couleurSelection);
		break;

	case BASIQUE:
		spriteTourAttaqueBasique.setColor(couleurSelection);
		break;

	case FROST:
		spriteTourDeGlace.setColor(couleurSelection);
		break;

	case SUPPORT:
		spriteTourSupport.setColor(couleurSelection);
		break;

	case MUR:
		spriteMur.setColor(couleurSelection);
		break;
	default:
		break;
	}
}
