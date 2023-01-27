#include "Application.hh"
//Initialisation de la fenêtre
Application::Application():ballon(1, NULL) 
{	
	sf::ContextSettings options;
	options.antialiasingLevel = 8;
	window.create(sf::VideoMode(int(WIN_WIDTH*COEF_ECRAN), int(WIN_HEIGHT*COEF_ECRAN)), "World Cup Ultimate Team", sf::Style::Default, options);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	LoadFont();
}

void Application::Run()
{    
	initSprite();
	// 20 cercles
	initCircleShape();
    //Initialisation de des score et des commentaire
	SetText(scoreEquipe1, fontScore, std::to_string(jeu.getScoreEquipe1()), 50);
	scoreEquipe1.setPosition(710*COEF_ECRAN, 15*COEF_ECRAN);
    scoreEquipe1.setScale(COEF_ECRAN, COEF_ECRAN);
	scoreEquipe1.setFillColor(sf::Color::White);
	SetText(scoreEquipe2, fontScore, std::to_string(jeu.getScoreEquipe2()), 50);
	scoreEquipe2.setPosition(855*COEF_ECRAN, 15*COEF_ECRAN);
    scoreEquipe2.setScale(COEF_ECRAN, COEF_ECRAN);
	scoreEquipe2.setFillColor(sf::Color::White);
    commentaire.setPosition(725*COEF_ECRAN, 800*COEF_ECRAN);
    commentaire.setScale(COEF_ECRAN, COEF_ECRAN);

    // Boucle qui tourne tant que la fen�tre est ouverte
    while (window.isOpen())
    {
        sf::Event event;
        // On boucle sur les �v�nements
        while (window.pollEvent(event))
        {
            // Gestion des inputs / events
            input.InputHandler(event, window);
			CheckBtn(event);
        }

        // Couleur de la fen�tre en gris clair
        window.clear(sf::Color(200, 200, 200));
        
		// Switch case pour les diff�rents ecrans du jeu
        switch (ecran) {
        
        case 0:
			// Ecran d'acceuil
			window.draw(menu);
            next = 1;
            break;
		case 1:
			// Initialisation du jeu
            jeu.initList();
            jeu.melangerListe();
			jeu.deleteEquipe();
            jeu.initScore();
            initPositionBlank();
			commentaire.setString("");
			equipe = 1;
			choix = 0;
			ecran = 2;
            break;
        case 2:
            window.draw(terrain_flou);
            // On dessine les 10 cartes draft
            for (int i = 0; i < 20; i++)
            {
                window.draw(blank[i]);
            }
            window.draw(choixCarte);
            if (choix == 20) {
                next = 1;
                window.draw(txtAvMatch);
            }
            else window.draw(txtDraft);
			break;
		case 3:
        //On initialise la position des joueurs et du ballon, puis on passe la balle au gardien de l'équipe 1
			jeu.deleteJoueurs();
            jeu.initPlacement();
			ballon.setJoueur(*jeu.getGardien(1));
			jeu.setBallon(&ballon);
            // Afficher les 2 equipes
            /*std::cout << "Equipe 1" << endl;
            for (auto& e : jeu.getAttaquant(1)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            for (auto& e : jeu.getMilieu(1)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            for (auto& e : jeu.getDefenseur(1)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            std::cout << jeu.getGardien(1)->getNom() << " : " << jeu.getGardien(1)->getPlacement() << ", " << jeu.getGardien(1)->getPosX() << ", " << jeu.getGardien(1)->getPosY() << std::endl;
            std::cout << endl;
            std::cout << "Equipe 2" << endl;
            for (auto& e : jeu.getAttaquant(2)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            for (auto& e : jeu.getMilieu(2)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            for (auto& e : jeu.getDefenseur(2)) {
                std::cout << e->getNom() << " : " << e->getPlacement() << ", " << e->getPosX() << ", " << e->getPosY() << std::endl;
            }
            std::cout << jeu.getGardien(2)->getNom() << " : " << jeu.getGardien(2)->getPlacement() << ", " << jeu.getGardien(2)->getPosX() << ", " << jeu.getGardien(2)->getPosY() << std::endl;
            std::cout << endl;*/
            // On dessine le terrain    
            window.draw(terrain);
            // On dessine les circleShape
            for (int i = 0; i < 20; i++)
            {
                window.draw(circle[i]);
            }
			ecran = 4;
			break;
        case 4:
        //On fixe l'état du jeu à true, si il passe à false le jeu est fini puis on regarde chaque action et on redessine en fonction de l'action
            if (jeu.getEtatJeu() == true) {
                CheckAction(event);
                drawGame();
            }
			else {
				ecran = 5;
			}
            break;
		case 5:
        //On affiche le gagnant et propose de rejouer
			drawEnd();
        }
        

        // Afficher � l'�cran tous les �l�ments
        window.display();
    }
}

void Application::LoadFont()
// Chargement des polices
{
	if (!fontCom.loadFromFile("font/poppins.ttf"))
	{
		std::cout << "Erreur lors du chargement de la police" << std::endl;
	}
	if (!fontScore.loadFromFile("font/score.ttf"))
	{
		std::cout << "Erreur lors du chargement de la police" << std::endl;
	}
}

void Application::CheckBtn(sf::Event event)
{
    if (input.GetButton().escape == true)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && ecran == 2)
    {
        //Lorsque le joueur clique sur une carte ça choisit un joueur aléatoirement en fonction de la carte sur laquelle il clique (Attaquant, Milieu, Defenseur, Gardien)
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (blank[choix].getGlobalBounds().contains(float(mousePosition.x), float(mousePosition.y))) {
			//std::cout << "Clic sur la carte " << choix << endl;
            
            if (choix % 10 == 9) {
				Gardien* gardien = jeu.choixGardien();
				//std::cout << "Gardien : " << gardien->getNom() << endl;
				jeu.supprimerJoueur(gardien->getNom());
				jeu.setGardien(gardien, equipe);
                textureJoueur[choix].loadFromFile(gardien->getPath());
            }
			else if (choix % 10 == 0 || choix % 10 == 1 || choix % 10 == 2) {
				Attaquant* attaquant = jeu.choixAttaquant();
				//std::cout << "Attaquant : " << attaquant->getNom() << endl;
				jeu.supprimerJoueur(attaquant->getNom());
				jeu.ajoutAttaquant(attaquant, equipe);
                textureJoueur[choix].loadFromFile(attaquant->getPath());
			}
			else if (choix % 10 == 3 || choix % 10 == 4 || choix % 10 == 5) {
				Milieu* milieu = jeu.choixMilieu();
				//std::cout << "Milieu : " << milieu->getNom() << endl;
				jeu.supprimerJoueur(milieu->getNom());
				jeu.ajoutMilieu(milieu, equipe);
                textureJoueur[choix].loadFromFile(milieu->getPath());
			}
			else if (choix % 10 == 6 || choix % 10 == 7 || choix % 10 == 8) {
				Defenseur* defenseur = jeu.choixDefenseur();
				//std::cout << "Defenseur : " << defenseur->getNom() << endl;
				jeu.supprimerJoueur(defenseur->getNom());
				jeu.ajoutDefenseur(defenseur, equipe);
                textureJoueur[choix].loadFromFile(defenseur->getPath());
			}

			choix++;
            if (choix == 20) { choixCarte.setPosition(-1000, -1000); }//On cache la carte si on a fini de choisir les joueurs
            else choixCarte.setPosition(blank[choix].getPosition());
			if (choix == 10) {//On passe à l'équipe 2
				jeu.initList();
				jeu.melangerListe();
                equipe = 2;
			}
        }
    }
	if (input.GetButton().next == true)//On passe à l'écran suivant
	{
        if (next){
            ecran++;
            next = 0;
        }
	}
    if (input.GetButton().restart == true && ecran == 5) ecran = 1;
}

void Application::CheckAction(sf::Event event)
{//On regarde si le joueur a appuyé sur une touche et on fait l'action correspondante
    if (input.GetButton().tirer == true) {//Si le joueur appuie sur la touche tirer
        actionTirer(jeu.getBallon()->getJoueur()->poste());
        passeON = false;
        sf::sleep(sf::milliseconds(200));
    }
    //Si le joueur appuie sur la touche passer
    if (input.GetButton().passer == true && passeON == 0) {
        passeON = true;
    }
    if (passeON)
    {
        //Si le joueur est un attaquant en face du but il ne peut pas faire de passe
        if (jeu.getBallon()->getJoueur()->getPlacement() >= 35 || jeu.getBallon()->getJoueur()->getPlacement() <= -35) {
            SetText(commentaire, fontCom, "Vas-y tout seul mon grand les autres sont trop lents", 26);
        }
        
        else {
            //On affiche les options de passe
            SetText(commentaire, fontCom, "Choisissez a quel joueur vous faites la passe", 26);
            
            if (input.GetButton().right == true) {
                //Si le joueur appuie sur la touche droite on fait la passe à droite
                actionPasserCote(jeu.getBallon()->getJoueur()->poste(), 1);
                passeON = false;
            }
            
            if (input.GetButton().left == true) {
                //Si le joueur appuie sur la touche gauche on fait la passe à gauche
                actionPasserCote(jeu.getBallon()->getJoueur()->poste(), -1);
                passeON = false;
            }

            if (input.GetButton().devant == true) {
                //Si le joueur appuie sur la touche devant on fait la passe devant
                actionPasserDevant(jeu.getBallon()->getJoueur()->poste());
                passeON = false;
            }
 
        }

    }

	if (input.GetButton().dribbler == true) {
        //Si le joueur appuie sur la touche dribbler on dribble
        actionDribbler(jeu.getBallon()->getJoueur()->poste());
        passeON = false;
        sf::sleep(sf::milliseconds(200));
    }
}
//Fonction qui fait le tir
void Application::actionTirer(std::string poste)
{
    int team = 2;
    int opp = 1;
	std::string txt = "Tir de " + jeu.getBallon()->getJoueur()->getNom();
    //On vérifie le poste du joueur, son placement et son équipe pour savoir si il peut tirer ou non
    if (poste == "Attaquant" || poste == "Milieu") {
        if (jeu.getBallon()->getJoueur()->getPlacement() == 35 || jeu.getBallon()->getJoueur()->getPlacement() == 36 || jeu.getBallon()->getJoueur()->getPlacement() == 37 || jeu.getBallon()->getJoueur()->getPlacement() == -35 || jeu.getBallon()->getJoueur()->getPlacement() == -36 || jeu.getBallon()->getJoueur()->getPlacement() == -37 || jeu.getBallon()->getJoueur()->getPlacement() == 25 || jeu.getBallon()->getJoueur()->getPlacement() == 26 || jeu.getBallon()->getJoueur()->getPlacement() == 27 || jeu.getBallon()->getJoueur()->getPlacement() == -25 || jeu.getBallon()->getJoueur()->getPlacement() == -26 || jeu.getBallon()->getJoueur()->getPlacement() == -27) {
            
            if (jeu.getBallon()->getJoueur()->getPlacement() > 0) {
                team = 1;
                opp = 2;
            }
            //Si il peut tirer on tire et on regarde si il marque ou non
            if (dynamic_cast<Attaquant*>(jeu.getBallon()->getJoueur())->tirer(*jeu.getGardien(opp), *jeu.getBallon()) == 2) {
                jeu.marquerEquipe(team);
				jeu.majEtatJeu();
                txt = txt + " et BUT\n GOOAAAAALLL !";
            }
            else {
				txt = txt + " et il rate \n Quel arret du gardien !";
			}
            jeu.initPlacement();//On remet les placement initiaux
        }
        else {
            txt = "Elimine ton adversaire avant de tirer";
        }
    }
    else if (poste == "Defenseur") {
        txt = "Un tir de 70m, on va pas te laisser faire ca quand meme";
    }
    else if (poste == "Gardien") {
        txt = "Pour faire un degagement c'est une passe qu'il faut faire, pourquoi paniquer ?\n Une passe tranquille ...";
    }
    SetText(commentaire, fontCom, txt, 26);
}
//Fonction qui fait le dribble
void Application::actionDribbler(std::string poste) {
    
    int go = -1;
    int valide = 0;
    int opp = 1;
    int i = -1;
	std::string txt;
    //On vérifie l'équipe du joueur
    if (jeu.getBallon()->getJoueur()->getPlacement() > 0) {
        opp = 2;
        i = 1;
    }
    // On va ensuite vérifier le poste du joueur pour savoir si il peut dribbler ou non
    if (poste == "Defenseur") {
        txt = "Un defenseur ca ne dribble pas";
        SetText(commentaire, fontCom, txt, 26);
        return;
    }
    else if (poste == "Gardien") {
        txt = "Le gardien degage la balle, il monte pas avec ...";
        SetText(commentaire, fontCom, txt, 26);
		return;
    }
    //Si il peut dribbler on vérifie si il a un joueur en face de lui puis on le dribble si c'est le cas
    else if (poste == "Attaquant") {
        for (auto& e : jeu.getDefenseur(opp)) {
            if (e->getPlacement() == ((jeu.getBallon()->getJoueur()->getPlacement()) * -1) + 20*i) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " essaie de dribbler " + e->getNom();
                go = dynamic_cast<Attaquant*>(jeu.getBallon()->getJoueur())->dribbler(*e);
                e->setPosX(e->getPosX() - 100*i);
                break;
            }
        }
    }
    else if (poste == "Milieu") {
        for (auto& e : jeu.getMilieu(opp)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) * -1) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " essaie de dribbler " + e->getNom();
                go = dynamic_cast<Milieu*>(jeu.getBallon()->getJoueur())->dribbler(*e);
                e->setPosX(e->getPosX() - 100*i);
                break;
            }
        }
    }
    //Si il a réussi , sa position augmente de 5 et son cercle avance
    if (go == 1) {
        jeu.getBallon()->getJoueur()->setPlacement(jeu.getBallon()->getJoueur()->getPlacement() + 5 * i);
        jeu.getBallon()->getJoueur()->setPosX(jeu.getBallon()->getJoueur()->getPosX() + 100 * i);
        txt = txt + " et reussit" + "\nTu l'as passe, tir ou passe devant";
        valide = 1;
    }
    //Sinon la balle va au gardien adverse
    else if (go == 0) {
        jeu.getBallon()->setJoueur(*jeu.getGardien(opp));
        txt = txt + " et rate" + "\nTu l'as perdu, le gardien a la balle";
        valide = 1;
        jeu.initPlacement();
    }
    else if (valide == 0) txt = "Tu ne peux plus dribbler l'artiste, essaie de passer ou de tirer";

    SetText(commentaire, fontCom, txt, 26);
}
//Fonction qui fait la passe de côté
void Application::actionPasserCote(std::string poste, int direction) {
    
    int valide = 0;
    int team = 2;
    std::string txt;
    //On vérifie l'équipe du joueur
    if (jeu.getBallon()->getJoueur()->getPlacement() > 0) team = 1;
    //On vérifie ensuite le poste pour voir si il peut faire la passe
    if (poste == "Gardien") {
        txt = "Il n'y a qu'un seul gardien,\ndonc personne a cote de toi :(";
        SetText(commentaire, fontCom, txt, 26);
		return;
    }
//On vérifie si il a un joueur du côté ou il veut faire la passe puis on fait la passe 
    else if (poste == "Attaquant") {
        for (auto& e : jeu.getAttaquant(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + direction) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " passe a " + e->getNom() + "\nBelle Passe !";
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                valide = 1;
                break;
            }
        }
    }
    
    else if (poste == "Milieu") {
        for (auto& e : jeu.getMilieu(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + direction) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " passe a " + e->getNom() + "\nBelle Passe !";
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                valide = 1;
                break;
            }
        }
    }
    
    else if (poste == "Defenseur") {
        for (auto& e : jeu.getDefenseur(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + direction) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " passe a " + e->getNom() + "\nBelle Passe !";
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                valide = 1;
                break;
            }
        }
    }

    if (valide == 0) txt = "Tu ne peux pas faire la passe aux supporters";
    
    SetText(commentaire, fontCom, txt, 26);
}
//Fonction qui fait la passe devant
void Application::actionPasserDevant(std::string poste) {

    int valide = 0;
    int team = 2;
    int i = -1;
	std::string txt;
    //On vérifie l'équipe du joueur
    if (jeu.getBallon()->getJoueur()->getPlacement() > 0) {
        team = 1;
        i = 1;
    }

    if (poste == "Attaquant") {
        SetText(commentaire, fontCom, "Le gardien adverse n'est pas dans ton equipe", 26);
        return;
    }
    //On vérifie si il a un joueur devant lui et on lui fait la passe si il n'a aucun adversaire à éliminer
    else if (poste == "Gardien") {
        for (auto& e : jeu.getDefenseur(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + 10 * i) {
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                txt = "Le goal fait la passe";
                break;
            }
        }
        return;
    }
    //Si le Milieu est avancé de 5, il a donc éliminer son joueur et peut faire la passe
    else if (poste == "Milieu") {
        for (auto& e : jeu.getAttaquant(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + 5*i) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " passe a " + e->getNom() + "\nBelle Passe !";
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                valide = 1;
                break;
            }
        }
    }
    else if (poste == "Defenseur") {
        for (auto& e : jeu.getMilieu(team)) {
            if (e->getPlacement() == (jeu.getBallon()->getJoueur()->getPlacement()) + 10*i) {
                txt = jeu.getBallon()->getJoueur()->getNom() + " passe a " + e->getNom() + "\nBelle Passe !";
                jeu.getBallon()->getJoueur()->passer(*e, *jeu.getBallon());
                valide = 1;
                break;
            }
        }
    }

    if (valide == 0) txt = "ET LA PASSE EN LOUCHE, et non tu peux pas en fait, elimine ton adversaire d'abord";

    SetText(commentaire, fontCom, txt, 26);
}
//Fonction qui gêre les textes
void Application::SetText(sf::Text& txt, sf::Font& font, std::string str, int size)
{
    // On lui indique quelle police utiliser
    txt.setFont(font);
    // On indique la cha�ne de caract�res � afficher
    txt.setString(str);
    // On indique la taille de la police d'�criture
    txt.setCharacterSize(size);
    // On donne la couleur
    txt.setFillColor(sf::Color::Black);
    // Modification du style
    txt.setStyle(sf::Text::Bold);
}
//Fonction qui charge les images
void Application::LoadSprite(sf::Sprite& sprite, sf::Texture& texture, std::string path)
{
	if (!texture.loadFromFile(path)) std::cout << "Erreur chargement image" << std::endl;
	//std::cout << "Chargement image :" << path << endl;
	sprite.setTexture(texture);
}
//Fonctioh qui initalise les images
void Application::initSprite()
{
    LoadSprite(terrain_flou, textureFlou, "images/terrain_flou_1.png");
    terrain_flou.setPosition(0, 0);
    terrain_flou.setScale(COEF_ECRAN, COEF_ECRAN);
    
    LoadSprite(choixCarte, textureChoix, "cartes/choix.png");
    // 10 Cartes draft avec la m�me texture
    for (int i = 0; i < 20; i++)
    {
        LoadSprite(blank[i], textureJoueur[i], "cartes/blank.png");
        blank[i].setScale(COEF_ECRAN, COEF_ECRAN);
    }

    initPositionBlank();
    
	LoadSprite(terrain, textureTerrain, "images/terrain.jpg");
	terrain.setPosition(0, 0);
    terrain.setScale(COEF_ECRAN, COEF_ECRAN);

	LoadSprite(ball, textureBall, "images/ballon_petit.png");
	ball.setPosition(0, 0);
    ball.setScale(COEF_ECRAN, COEF_ECRAN);
    
    LoadSprite(instruction, textureInstruction, "images/instruction.png");
    instruction.setPosition(0, 800*COEF_ECRAN);
    instruction.setScale(COEF_ECRAN, COEF_ECRAN);

	LoadSprite(terrainWin, textureWin, "images/terrainWin.png");
	terrainWin.setPosition(0, 0);
    terrainWin.setScale(COEF_ECRAN, COEF_ECRAN);
    
	LoadSprite(confetti, textureConfetti, "images/confetti.png");
	confetti.setPosition(0, 0);
    confetti.setScale(COEF_ECRAN, COEF_ECRAN);

	LoadSprite(menu, textureMenu, "images/menu.png");
	menu.setPosition(0, 0);
    menu.setScale(COEF_ECRAN, COEF_ECRAN);

	LoadSprite(txtDraft, textureTxtDraft, "images/txtdraft.png");
	txtDraft.setPosition(0, 760*COEF_ECRAN);
    txtDraft.setScale(COEF_ECRAN, COEF_ECRAN);
    
	LoadSprite(txtAvMatch, textureTxtAvMatch, "images/txtdraftfini.png");
	txtAvMatch.setPosition(0, 760*COEF_ECRAN);
    txtAvMatch.setScale(COEF_ECRAN, COEF_ECRAN);
}
// fonction qui initialise les cercles
void Application::initCircleShape(){
	// 10 cercles de draft
	for (int i = 0; i < 10; i++)
	{
		circle[i].setRadius(20);
		circle[i].setFillColor(sf::Color::Blue);
		circle[i].setOutlineThickness(5);
		circle[i].setOutlineColor(sf::Color::Blue);
        circle[i].setScale(COEF_ECRAN, COEF_ECRAN);
	}
    for (int i = 10; i < 20; i++)
    {
        circle[i].setRadius(20);
        circle[i].setFillColor(sf::Color::Red);
        circle[i].setOutlineThickness(5);
        circle[i].setOutlineColor(sf::Color::Red);
        circle[i].setScale(COEF_ECRAN, COEF_ECRAN);
    }
    
	circle[0].setPosition(670*COEF_ECRAN, 184*COEF_ECRAN);
    circle[1].setPosition(680*COEF_ECRAN, 374*COEF_ECRAN);
    circle[2].setPosition(670*COEF_ECRAN, 574*COEF_ECRAN);
    circle[3].setPosition(530*COEF_ECRAN, 204*COEF_ECRAN);
    circle[4].setPosition(530*COEF_ECRAN, 374*COEF_ECRAN);
    circle[5].setPosition(530*COEF_ECRAN, 544*COEF_ECRAN);
    circle[6].setPosition(375*COEF_ECRAN, 174*COEF_ECRAN);
    circle[7].setPosition(350*COEF_ECRAN, 374*COEF_ECRAN);
    circle[8].setPosition(375*COEF_ECRAN, 574*COEF_ECRAN);
    circle[9].setPosition(180*COEF_ECRAN, 374*COEF_ECRAN);

    circle[10].setPosition(910*COEF_ECRAN, 184*COEF_ECRAN);
    circle[11].setPosition(900*COEF_ECRAN, 374*COEF_ECRAN);
    circle[12].setPosition(910*COEF_ECRAN, 574*COEF_ECRAN);
    circle[13].setPosition(1050*COEF_ECRAN, 204*COEF_ECRAN);
    circle[14].setPosition(1050*COEF_ECRAN, 374*COEF_ECRAN);
    circle[15].setPosition(1050*COEF_ECRAN, 544*COEF_ECRAN);
    circle[16].setPosition(1205*COEF_ECRAN, 174*COEF_ECRAN);
    circle[17].setPosition(1230*COEF_ECRAN, 374*COEF_ECRAN);
    circle[18].setPosition(1205*COEF_ECRAN, 574*COEF_ECRAN);
    circle[19].setPosition(1400*COEF_ECRAN, 374*COEF_ECRAN);
}
//Fonction qui initialise les cartes vides
void Application::initPositionBlank() {
    choixCarte.setPosition(630*COEF_ECRAN, 104*COEF_ECRAN);
    choixCarte.setScale(COEF_ECRAN, COEF_ECRAN);

    blank[0].setPosition(630*COEF_ECRAN, 104*COEF_ECRAN);
    blank[1].setPosition(640*COEF_ECRAN, 304*COEF_ECRAN);
    blank[2].setPosition(630*COEF_ECRAN, 504*COEF_ECRAN);
    blank[3].setPosition(490*COEF_ECRAN, 134*COEF_ECRAN);
    blank[4].setPosition(490*COEF_ECRAN, 304*COEF_ECRAN);
    blank[5].setPosition(490*COEF_ECRAN, 474*COEF_ECRAN);
    blank[6].setPosition(335*COEF_ECRAN, 104*COEF_ECRAN);
    blank[7].setPosition(310*COEF_ECRAN, 304*COEF_ECRAN);
    blank[8].setPosition(335*COEF_ECRAN, 504*COEF_ECRAN);
    blank[9].setPosition(120*COEF_ECRAN, 304*COEF_ECRAN);

    blank[10].setPosition(840*COEF_ECRAN, 104*COEF_ECRAN);
    blank[11].setPosition(830*COEF_ECRAN, 304*COEF_ECRAN);
    blank[12].setPosition(840*COEF_ECRAN, 504*COEF_ECRAN);
    blank[13].setPosition(1000*COEF_ECRAN, 134*COEF_ECRAN);
    blank[14].setPosition(1000*COEF_ECRAN, 304*COEF_ECRAN);
    blank[15].setPosition(1000*COEF_ECRAN, 474*COEF_ECRAN);
    blank[16].setPosition(1155*COEF_ECRAN, 104*COEF_ECRAN);
    blank[17].setPosition(1170*COEF_ECRAN, 304*COEF_ECRAN);
    blank[18].setPosition(1155*COEF_ECRAN, 504*COEF_ECRAN);
    blank[19].setPosition(1350*COEF_ECRAN, 304*COEF_ECRAN);
    for (int i = 0; i < 20; i++)
    {
        LoadSprite(blank[i], textureJoueur[i], "cartes/blank.png");
        blank[i].setScale(COEF_ECRAN, COEF_ECRAN);
    }
}
//Fonction qui dessine le jeu lorsqu'il est en cours
void Application::drawGame(){
    window.draw(terrain);
    updatePositionCircle();
	for (int i = 0; i < 20; i++)
	{           
		window.draw(circle[i]);
        window.draw(nomJoueur[i]);
	}
    if (jeu.getBallon()->getJoueur()->getPlacement() > 0) ball.setPosition(float(jeu.getBallon()->getJoueur()->getPosX() + 30)*COEF_ECRAN, float(jeu.getBallon()->getJoueur()->getPosY() + 8)*COEF_ECRAN);
    else ball.setPosition(float(jeu.getBallon()->getJoueur()->getPosX() - 10)*COEF_ECRAN, float(jeu.getBallon()->getJoueur()->getPosY() + 8)*COEF_ECRAN);
    window.draw(ball);
    window.draw(instruction);
	scoreEquipe1.setString(std::to_string(jeu.getScoreEquipe1()));
	scoreEquipe2.setString(std::to_string(jeu.getScoreEquipe2()));
    window.draw(scoreEquipe1);
	window.draw(scoreEquipe2);
    window.draw(commentaire);
}
//Fonction qui affiche l'écran de fin
void Application::drawEnd() {
    window.draw(terrainWin);
	window.draw(confetti);
    window.draw(instruction);
	if (jeu.getScoreEquipe1() > jeu.getScoreEquipe2()) {
		commentaire.setString("Victoire de l'equipe BLUE");
	}
	else {
        commentaire.setString("Victoire de l'equipe RED");
	}
    scoreEquipe1.setString("-");
    scoreEquipe2.setString("-");
    window.draw(scoreEquipe1);
    window.draw(scoreEquipe2);
	window.draw(commentaire);
}
//Fonction qui met à jour les positions des cercles
void Application::updatePositionCircle(){
    int i = 0;
    for (auto& e : jeu.getAttaquant(1)) {
        circle[i].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i].setPosition(float(e->getPosX() - 25)*COEF_ECRAN, float(e->getPosY() + 50)*COEF_ECRAN);
		i++;
    }
    i = 0;
    for (auto& e : jeu.getAttaquant(2)) {
        circle[i+10].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i+10], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i+10].setPosition(float(e->getPosX() - 10)*COEF_ECRAN, float(e->getPosY() - 25)*COEF_ECRAN);
		i++;
    }
    i = 0;
    for (auto& e : jeu.getMilieu(1)) {
        circle[i+3].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i+3], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i+3].setPosition(float(e->getPosX() - 10)*COEF_ECRAN, float(e->getPosY() + 50)*COEF_ECRAN);
        i++;
    }
    i = 0;
    for (auto& e : jeu.getMilieu(2)) {
        circle[i+13].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i+13], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i+13].setPosition(float(e->getPosX() - 10)*COEF_ECRAN, float(e->getPosY() - 25)*COEF_ECRAN);
        i++;
    }
    i = 0;
    for (auto& e : jeu.getDefenseur(1)) {
        circle[i+6].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i+6], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i+6].setPosition(float(e->getPosX() - 10)*COEF_ECRAN, float(e->getPosY() + 50)*COEF_ECRAN);
        i++;
    }
    i = 0;
    for (auto& e : jeu.getDefenseur(2)) {
        circle[i+16].setPosition(float(e->getPosX())*COEF_ECRAN, float(e->getPosY())*COEF_ECRAN);
        SetText(nomJoueur[i+16], fontCom, e->getNom(), TAILLE_POLICE_JOUEUR);
        nomJoueur[i+16].setPosition(float(e->getPosX() - 10)*COEF_ECRAN, float(e->getPosY() - 25)*COEF_ECRAN);
        i++;
    }
    circle[9].setPosition(float(jeu.getGardien(1)->getPosX())*COEF_ECRAN, float(jeu.getGardien(1)->getPosY())*COEF_ECRAN);
    SetText(nomJoueur[9], fontCom, jeu.getGardien(1)->getNom(), TAILLE_POLICE_JOUEUR);
    nomJoueur[9].setPosition(float(jeu.getGardien(1)->getPosX() - 10)*COEF_ECRAN, float(jeu.getGardien(1)->getPosY() + 50)*COEF_ECRAN);
    circle[19].setPosition(float(jeu.getGardien(2)->getPosX())*COEF_ECRAN, float(jeu.getGardien(2)->getPosY())*COEF_ECRAN);
    SetText(nomJoueur[19], fontCom, jeu.getGardien(2)->getNom(), TAILLE_POLICE_JOUEUR);
    nomJoueur[19].setPosition(float(jeu.getGardien(2)->getPosX() - 10)*COEF_ECRAN, float(jeu.getGardien(2)->getPosY() - 25)*COEF_ECRAN);
}