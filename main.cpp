#include <iostream>
#include <vector>
#include "Utilisateur.h"
#include "Administrateur.h"
#include "Categorie.h"
#include "Image.h" // Inclure la classe Image

std::vector<Administrateur> administrateurs;
//std::vector<Categorie> categories; // Déclaration du vecteur de categories

//Simuler la liste des utilisateurs déjà inscrits
std::vector<Utilisateur> utilisateurs={
    Utilisateur(1, "Samir", "samirdeguenon@gmail.com", "sam@@@", false),
    Utilisateur(2, "Colombe", "colombemidjangninou@gmail.com", "coco!", false),
    Utilisateur(3, "User", "johndoe@gmail.com", "securepass", false)
};

bool authentifierUtilisateur(Utilisateur& utilisateur){
    std::string nom, email, password;
    std::cout << "Authentification requise.\n";
    std::cout << "Nom: ";
    std::cin>>nom;
    std::cout << "Email: ";
    std::cin>>email;
    std::cout << "Mot de passe: ";
    std::cin>>password;

    for(auto& user: utilisateurs){
        if(user.getNom() == nom && user.getEmail() == email && user.getPassword() == password){
            std::cout << "Authentification reussie" << std::endl<<std::endl;
            utilisateur = user; //Transférer les informations de l'utilisateur authentifié
            return true;
        }
    }
    std::cout << "Authentification echouee. Utilisateur introuvable.\n";
    return false;
}
void inscrireUtilisateur(){
    int newId = utilisateurs.size()+1;
    std::string nom, email, password;
    std::cout<<"Inscription d'un nouvel utilisateur...\n";
    std::cout << "Nom: ";
    std::cin>>nom;
    std::cout << "Email: ";
    std::cin>>email;
    std::cout << "Mot de passe: ";
    std::cin>>password;
    bool isAdmin;

    Utilisateur newUser(newId, nom, email, password, isAdmin= false);
    utilisateurs.push_back(newUser);
    std::cout<<"IUtilisateur ajoute a la plateforme!\n";
}

bool authentifierAdministrateur(Utilisateur& utilisateur){
    std::string nom, email, password;
    std::cout << "Authentification requise.\n";
    std::cout << "Nom: ";
    std::cin>>nom;
    std::cout << "Email: ";
    std::cin>>email;
    std::cout << "Mot de passe: ";
    std::cin>>password;

    for(auto& admin: administrateurs){
        if(admin.getNom() == nom && admin.getEmail() == email && admin.getPassword() == password){
            std::cout << "Authentification administrateur reussie" << std::endl<<std::endl;
            return true;
        }
    }
    std::cout << "Administrateur non trouve. Veuillez verifier vos identifiants\n";
    return false;
}

void afficherUtilisateur(const Utilisateur& utilisateur){
    std::cout<< "ID: "<<utilisateur.getId()<<std::endl;
    std::cout<< "Nom: "<<utilisateur.getNom()<<std::endl;
    std::cout<< "Email: "<<utilisateur.getEmail()<<std::endl;
    std::cout<< "Mot de passe: "<<utilisateur.getPassword()<<std::endl;
}

void afficherListeUtilisateurs(const std::vector<Utilisateur>& utilisateurs){
    for(const auto& utilisateur: utilisateurs){
        afficherUtilisateur(utilisateur);
        std::cout<<"---------------------------------"<<std::endl;
    }
}

int main() {
    //Exemple d'ajout d'administrateurs pour le test
    administrateurs.push_back(Administrateur(4, "AdminUser", "admin@gmail.com", "adminpass", true));
    std::vector<Image> images; // Déclaration du vecteur d'images
    std::vector<Categorie> categories; // Déclaration du vecteur de categories

    //Exemples d'ajout de catégories
    Categorie Environnement("Environnement");
    Categorie Sport("Sport");
    categories.push_back(Categorie("Environnement"));
    categories.push_back(Categorie("Sport"));
    Environnement.ajouterImage(1, "image1.jpg", "Coucher du soleil", "Cette image montre le coucher du soleil", true);
    Sport.ajouterImage(2, "image2.jpg", "Footballeur", "Cette image montre un footballeur pret a tout pour gagner", false);

    // Exemple d'ajout d'images (vous devez remplacer cela par des images réelles)
    images.push_back(Image(1, "image1.jpg", "Coucher du soleil", "Cette image montre le coucher du soleil", false));
    images.push_back(Image(2, "image2.jpg", "Footballeur", "Cette image montre un footballeur pret a tout pour gagner", true));

    std::cout<< "Bienvenue sur PicTerminal, la plateforme qui revolutionne la gestion des images. Qui etes vous ?\n";
    Utilisateur utilisateur; //Crée un utilisateur pour stocker les les informations authentifiées
    if(!authentifierUtilisateur(utilisateur)){
        std::string regisChoice;
        std::cout<<"Voulez vous inscrire ? (oui/non): ";
        std::cin>>regisChoice;
        if(regisChoice == "oui"){
            inscrireUtilisateur();
        }
        else{
            std::cout<< "Vous devez etre authentifie avant de continuer. Fin du programme\n";
            return 0;
        }
    }
    //A ce stade l'utilisateur est authentifié et on peut lui proposer les autres options
    // Code pour les utilisateurs
    std::cout<< "Authentification reussie en tant qu'utilisateur ordinaire\n";
    int switchChoice;
    do{
        std::cout<< "Que voulez vous faire ?\n";
        std::cout<< "1. Rester en mode utilisateur\n";
        std::cout<< "2. Passer en mode administrateur (si vous avez les droits)\n";
        std::cout<< "3. Quitter\n";
        std::cout<< "Votre choix: ";
        std::cin>>switchChoice;
        switch(switchChoice){
        case 1:
            {
                std::cout<< "Vous restez en mode utilisateur.\n";
                int userChoice;
                do{
                    std::cout << "Choisissez une option : 1) Telecharger une image 2) Liker une image 3) Consulter votre galerie 4) Ajouter une image comme favori 5) Consulter vos images favoris 6) Ajouter une image sur PicTerminal 0) Quitter\n";
                    std::cin >> userChoice;

                    // Implémentez les fonctionnalités pour l'utilisateur selon le choix
                    switch (userChoice) {
                        case 1:{
                            // Code pour télécharger une image
                            std::cout << "Telechargement d'une image...\n";
                            std::cout << "Voici les images de la plateforme: \n";
                            for (auto& image : images){
                                image.afficherInformations();
                            }
                            int imageId;
                            std::cout << "Entrer l'id de l'image a telecharger\n";
                            std::cin >>imageId;
                            //Rechercher l'image par son id
                            bool found = false;
                            for (auto& image : images){
                                if (imageId == image.getId()) {
                                        if (image.peutAcceder(utilisateur.getId())) {
                                            std::cout << "Voici les informations de l'image que vous souhaitez telecharger\n";
                                            image.afficherInformations();
                                            // Demander la confirmation du téléchargement
                                            std::string confirmation;
                                            std::cout << "Etes-vous sur de vouloir telecharger cette image ? (oui/non) : ";
                                            std::cin >> confirmation;
                                            if (confirmation == "oui") {
                                                    utilisateur.telechargerImage(image);
                                            } else { std::cout << "Telechargement annule.\n" << std::endl << std::endl;}
                                            } else { std::cout << "Acces refuse : Cette image est privee.\n" << std::endl << std::endl; }
                                            found = true;
                                            break;
                                        }
                            }
                            if (!found){
                                std::cout<<"Image introuvable.\n"<<std::endl<<std::endl;
                            }
                            break;
                        }
                        case 2:{
                            // Code pour liker une image
                            std::cout << "Liking d'une image...\n";
                            int imageId;
                            std::cout << "Entrez l'ID de l'image a liker\n";
                            std::cin >> imageId;
                            // Rechercher l'image par son ID
                            bool found = false;
                            for (auto& image : images) {
                                    if (imageId == image.getId()) {
                                        if (image.peutAcceder(utilisateur.getId())) {
                                            utilisateur.likerImage(image);
                                            std::cout << "Liking effectue et l'ID enregistre dans la liste des likings de l'image.\n" << std::endl << std::endl;
                                            } else { std::cout << "Acces refuse : Cette image est privee.\n" << std::endl << std::endl;
                                            } found = true;
                                            break;
                                    }
                            }
                            if (!found){
                                std::cout<<"Image introuvable.\n"<<std::endl<<std::endl;
                            }
                            break;
                        }

                        case 3:
                            // Code pour consulter la galerie
                            std::cout << "Consultation de votre galerie...\n";
                            utilisateur.consulterGalerie();
                            break;
                        case 4:
                            // Code pour ajouter une image comme favori
                            std::cout << "Ajout d'une image aux favoris...\n" << std::endl;
                            utilisateur.ajouterFavoris(images);
                            break;
                        case 5:
                            //Code pour consulter les favoris
                            std::cout << "Consultation de vos images favorites...\n";
                            utilisateur.consulterFavoris();
                            break;
                        case 6:
                            {
                                //Code pour ajouter une image sur PicTerminal
                                std::cout << "Ajout d'une image sur PicTerminal...\n"<<std::endl;
                                int idImage;
                                std::string nomFichier, nomCategorie, titre, description;
                                bool publique;
                                std::cout<< "Entrer l'ID de l'image que vous voulez ajouter sur PicTerminal: ";
                                std::cin>>idImage;
                                std::cin.ignore(); //Ignorer le retour à la ligne en restant dans le buffer
                                std::cout<< "Entrer le nom du fichier de l'image: ";
                                std::getline(std::cin, nomFichier);
                                std::cout<< "Entrer le titre de l'image: ";
                                std::getline(std::cin, titre);
                                std::cout<< "Entrer une description de l'image: ";
                                std::getline(std::cin, description);
                                std::cout<< "L'image sera-elle publique ? (1 pour oui, 0 pour non)\n";
                                std::cin>>publique;
                                //Création de l'image et ajout à la liste d'attente pour approbation
                                Image nouvelleImage(idImage, nomFichier, titre, description, publique);
                                utilisateur.ajouterImage(nouvelleImage);

                                std::cout << "Patientez pour qu'un administrateur approuve votre image.\n"<<std::endl<<std::endl;
                                break;
                            }
                        case 0:
                            //Code pour quitter
                            std::cout << "Deconnexion de l'utilisateur...\n";
                            std::cout << "Utilisateur deconnecte\n";
                            break;
                        default:
                            std::cout << "Choix invalide, ressayer\n";
                            break;
                    }
                }while (userChoice !=0);
                break;
            }
        case 2:
            {
                // Code pour les administrateurs
                Administrateur administrateur; //Crée un administrateur pour stocker les les informations authentifiées
                if(authentifierAdministrateur(administrateur)){
                    int adminChoice;
                    do{
                        std::cout << "Choisissez une option : 1) Approuver une image 2) Rejeter une image 3) Creer categorie 4) Modifier categorie 5) Consulter Statistique 6) Supprimer utilisateur 7) Ajouter utilisateur 8) Modifier utilisateur 9) Supprimer une categorie d'image 10) Faire une recherche par filtrage 0) Quitter\n";
                        std::cin >> adminChoice;
                        switch (adminChoice) {
                            case 1:{
                                int idImage;
                                std::cout<< "Entrer l'ID de l'image a approuver: ";
                                std::cin>> idImage;
                                administrateur.approuverImage(idImage);
                                //std::cout<< "Image aprouvee."<<std::endl<<std::endl;
                                break;
                            }
                            case 2:{
                                int idImage;
                                std::cout<< "Entrer l'ID de l'image a rejeter: ";
                                std::cin>>idImage;
                                administrateur.rejeterImage(idImage);
                                std::cout<< "Image rejetee."<<std::endl<<std::endl;
                                break;
                            }
                            case 3:{
                                administrateur.creerCategorie();
                                break;
                            }
                            case 4:{
                                administrateur.modifierCategorie();
                                break;
                            }
                            case 5:{
                                administrateur.consulterStatistiques(images, utilisateurs);
                                break;
                            }
                            case 6:{
                                    std::cout<< "Voici la liste des utilisateurs existant: \n";
                                    afficherListeUtilisateurs(utilisateurs);
                                    int utilisateurId;
                                    std::cout<< "Entrer l'ID de l'utilisateur a supprimer: ";
                                    std::cin>>utilisateurId;

                                    administrateur.supprimerUtilisateur(utilisateurs, utilisateurId);
                                    break;
                            }
                            case 7:{
                                //Code pour ajouter un utilisateur sur PicTerminal
                                administrateur.ajouterUtilisateur(utilisateurs);
                                std::cout<< "Liste des utilisateurs apres ajout: "<<std::endl;
                                afficherListeUtilisateurs(utilisateurs);
                                break;
                            }
                            case 8:{
                                //Code pour modifier un utilisateur
                                administrateur.modifierUtilisateur(utilisateurs);
                                std::cout<< "Liste des utilisateurs apres modification: "<<std::endl;
                                afficherListeUtilisateurs(utilisateurs);
                                break;
                            }
                            case 9:{
                                administrateur.supprimerCategorie(categories);
                                break;
                            }
                            case 10:{
                                int ch;
                                std::cout<<"Quel type de filtrage voulez-vous faire? Par categorie(1) ou par ID d'image(2)? :";
                                std::cin>>ch;
                                if(ch==1){
                                    std::vector<Categorie> categories; // Déclaration du vecteur de categories
                                    std::string nomCategorie;
                                    std::cout<<"Entrer le nom de la categorie: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, nomCategorie);
                                    // Trouver la catégorie
                                    for (auto& categorie : categories) {
                                        if (categorie.getNom() == nomCategorie) {
                                            Categorie cat=categorie;
                                            cat.listerImages();
                                            return 1;
                                        }
                                    }
                                    std::cout << "La categorie \"" << nomCategorie << "\" n'existe pas.\n";
                                }
                                else if (ch == 2){
                                    int imId;
                                    std::cout << "Entrer l'id de l'image\n";
                                    std::cin >>imId;
                                    //Rechercher l'image par son id
                                    bool found = false;
                                    for (auto& image : images){
                                        if(imId == image.getId()){
                                            std::cout <<"Voici les informations de l'image entree"<<std::endl;
                                            image.afficherInformations();
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }while(adminChoice!=0);
                }
            }
            case 3:
            {
                std::cout<< "Deconnexion...\n";
                std::cout<< "Deconnecte\n";
                break;
            }
        default:
            std::cout<< "Choix invalide. Veuillez reessayer.\n";
    }
}while(switchChoice != 3);
return 0;
}
