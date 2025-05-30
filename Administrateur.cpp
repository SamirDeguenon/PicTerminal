#include "Administrateur.h"
#include <algorithm>
#include "Image.h"
#include "Categorie.h"
#include <iostream>
#include <vector>
#include <string>

//Liste pour stocker les catégories créées
std::vector<Categorie> categories;
//std::vector<Image> images; // Déclaration du vecteur d'images

// Constructeur
Administrateur::Administrateur(int id, const std::string& nom, const std::string& email, const std::string& password, bool isAdmin)
    : Utilisateur(id, nom, email, password, isAdmin=true) {}

// Méthodes
void Administrateur::approuverImage(int imageId) {
    std::vector<Image> images; // Déclaration du vecteur d'images
    auto it= std::find_if(imagesEnAttente.begin(), imagesEnAttente.end(), [imageId](const Image& img){return img.getId() == imageId;});
    if(it != imagesEnAttente.end()){
        images.push_back(*it);//Ajouter l'image sur PicTerminal
        std::cout<<"Voici la liste d'image après l'approbation: "<<std::endl;
        for (const auto& image : images) {
            image.afficherInformations();
            std::cout<<"-----------------------------------"<<std::endl;
        }
        //imagesEnAttente.pop_back(); //Enlever l'image de la liste d'attente
        std::cout<< "L'image '"<<it->getTitre()<< "' a ete approuvee.\n";
        imagesEnAttente.erase(it);
    }
    else{
        std::cout<< "Aucune image trouvee dans la liste d'attente pour cet ID." <<std::endl<<std::endl;
    }
}

void Administrateur::rejeterImage(int imageId) {
    auto it= std::find_if(imagesEnAttente.begin(), imagesEnAttente.end(), [imageId](const Image& img){return img.getId() == imageId;});
    if(it != imagesEnAttente.end()){
        imagesEnAttente.pop_back(); //Enlever l'image de la liste d'attente
        std::cout<< "L'image '"<<it->getTitre()<< "' a ete rejetee.\n";
        imagesEnAttente.erase(it);
    }
    else{
        std::cout<< "Aucune image trouvee dans la liste d'attente pour cet ID."<<std::endl<<std::endl;
    }
}

void Administrateur::creerCategorie(/*const std::string& nom*/) {
    std::string nomCategorie;
    std::cout<< "Entrer le nom de la nouvelle categorie: ";
    std::cin>>nomCategorie;
    Categorie nouvelleCategorie(nomCategorie);
    categories.push_back(nouvelleCategorie);
    //Ajout d'images a la categorie
    ajouterImagesDansCategorie(nouvelleCategorie);
}

void Administrateur::ajouterImagesDansCategorie(Categorie& categorie){
    std::cout<< "Vous devez ajouter une image a la categorie'"<<categorie.nom<< ".\n ";
    int id;
    std::string titre, nomFichier, description;
    bool publique;
    std::cout<< "Entrez l'ID de l' image:";
    std::cin>>id;
    std::cout<< "Entrez le nom du fichier de la l'image:";
    std::cin>>nomFichier;
    std::cout<< "Entrez le titre de l'image:";
    std::cin>>titre;
    std::cout<< "Entrez la description de l'image:";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout<< "L'image sera t-elle publique ? (1 pour oui, 0 pour non): ";
    std::cin>>publique;
    categorie.ajouterImage(id, nomFichier, titre, description, publique);
    std::cout<< "Image ajoutee.\n";
}

void Administrateur::modifierCategorie(/*const std::string& nom*/) {
        std::string nomCategorie;
        std::cout << "Entrez le nom de la categorie a modifier: ";
        std::cin.ignore();
        std::getline(std::cin, nomCategorie);

        // Trouver la catégorie à modifier
        for (auto& categorie : categories) {
            if (categorie.getNom() == nomCategorie) {
                std::string nouveauNom;
                std::cout << "Entrez le nouveau nom pour la categorie \"" << nomCategorie << "\": ";
                std::getline(std::cin, nouveauNom);

                // Vérifier si le nouveau nom existe déjà
                for (const auto& cat : categories) {
                    if (cat.getNom() == nouveauNom) {
                        std::cout << "Une categorie avec le nom \"" << nouveauNom << "\" existe deja.\n";
                        return;
                    }
                }

                // Modifier le nom de la catégorie
                categorie = Categorie(nouveauNom);
                std::cout << "La categorie \"" << nomCategorie << "\" a ete modifiee en \"" << nouveauNom << "\" avec succes.\n";
                return;
            }
        }

        std::cout << "La categorie \"" << nomCategorie << "\" n'existe pas.\n";
}

void Administrateur::supprimerCategorie(std::vector<Categorie>& categories){
    std::string nomCategorie;
    std::cout << "Entrez le nom de la categorie a supprimer: ";
    std::cin.ignore();
    std::getline(std::cin, nomCategorie);

    // Trouver la catégorie à supprimer
    for (auto& categorie : categories) {
        if (categorie.getNom() == nomCategorie) {

            // supprimer la catégorie
            std::vector<Categorie> categories;
            categories.pop_back();
            std::cout << "La categorie \"" << nomCategorie << "\" a ete supprimee.\n";
            return;
        }
    }

    std::cout << "La categorie \"" << nomCategorie << "\" n'existe pas.\n";
}

void Administrateur::consulterStatistiques(const std::vector<Image>& images, const std::vector<Utilisateur>& utilisateurs) {
    std::cout << "=== Statistiques de la plateforme ===\n";

    // Nombre total d'images
    std::cout << "Nombre total d'images sur la plateforme: " << images.size() << "\n";

    // Images populaires (en fonction du nombre de likes)
    std::cout << "\nImages populaires (par nombre de likes):\n";
    for (const auto& image : images) {
        std::cout << "- " << image.getTitre() << " (Likes: " << image.getLikes().size() << ")\n";
    }

    // Nombre d'images téléchargées par catégorie
    /*std::unordered_map<std::string, int> imagesParCategorie;
    for (const auto& image : images) {
        imagesParCategorie[image.getCategorie()]++;
    }

    std::cout << "\nNombre d'images téléchargées par catégorie:\n";
    for (const auto& [categorie, count] : imagesParCategorie) {
        std::cout << "- " << categorie << ": " << count << "\n";
    }*/

    // Analyse de l'activité des utilisateurs
    std::cout << "\nAnalyse de l'activite des utilisateurs ordinaires:\n";
    for (const auto& utilisateur : utilisateurs) {
        int telechargements = 0;
        int likes = 0;

        // Parcourir les images pour compter les téléchargements et likes de chaque utilisateur
        for (const auto& image : images) {
            if (std::find(image.getTelechargements().begin(), image.getTelechargements().end(), utilisateur.getId()) != image.getTelechargements().end()) {
                telechargements++;
            }
            if (std::find(image.getLikes().begin(), image.getLikes().end(), utilisateur.getId()) != image.getLikes().end()) {
                likes++;
            }
        }

        std::cout << "Utilisateur: " << utilisateur.getNom() << " (ID: " << utilisateur.getId() << ")\n";
        std::cout << " - Telechargements: " << telechargements << "\n";
        std::cout << " - Likes: " << likes << "\n";
    }

    std::cout << "=== Fin des statistiques ===\n";
}

void Administrateur::supprimerUtilisateur(std::vector<Utilisateur>& utilisateurs, int utilisateurId){
    //Trouver et supprimer l'utilisateur de la liste
    //std::vector<Utilisateur> utilisateurs;
    auto it = std::find_if(utilisateurs.begin(), utilisateurs.end(), [&utilisateurId](const Utilisateur& u) {return u.getId() == utilisateurId;});
    if(it != utilisateurs.end()){
        utilisateurs.erase(it);
        std::cout<< "L'utilisateur ayant l'ID \""<<utilisateurId<< "\" a ete supprime avec succes.\n";
    }
    else{
        std::cout<< "L'utilisateur ayant l'ID \""<<utilisateurId<< "\" n'a pas ete trouve.\n";
    }
}
void Administrateur::ajouterUtilisateur(std::vector<Utilisateur>& utilisateurs) {
    int newId = utilisateurs.size()+1;
    std::string nom, email, password;
    std::cout<<"Ajout d'un nouvel utilisateur...\n";
    std::cout << "Entrer le nom de l'utilisateur: ";
    std::cin.ignore();
    std::getline(std::cin, nom);
    std::cout << "Entrer l'adresse mail de l'utilisateur: ";
    std::getline(std::cin, email);
    std::cout << "Entrer un mot de passe pour l'utilisateur: ";
    std::getline(std::cin, password);

    Utilisateur newUser(newId, nom, email, password, isAdmin= false);
    utilisateurs.push_back(newUser);
    std::cout<<"Utilisateur ajoute a la plateforme!\n";
}

void Administrateur::modifierUtilisateur(std::vector<Utilisateur>& utilisateurs) {
    int id;
    std::cout << "Entrez l'id de l'utilisateur a modifier : ";
    std::cin >> id;
    std::cin.ignore();

    // Rechercher l'utilisateur par id
    for (auto& utilisateur: utilisateurs){
        if(utilisateur.getId()==id){
            std::string nom, email, password;
            std::cout<< "Entrez le nouveau nom de l'utilisateur: ";
            std::getline(std::cin, nom);
            utilisateur.setNom(nom); //Modification de l'attribut par une methode setter

            std::cout<< "Entrez le nouvel email de l'utilisateur: ";
            std::getline(std::cin, email);
            utilisateur.setEmail(email); //Modification de l'attribut par une methode setter

            std::cout<< "Entrez le nouveau mot de passe de l'utilisateur: ";
            std::getline(std::cin, password);
            utilisateur.setPassword(password); //Modification de l'attribut par une methode setter

            std::cout<< "L'utilisateur a ete modifie avec succes! "<<std::endl<<std::endl;
            return;
        }
    }
    std::cout<< "Aucun utilisateur avec l'ID "<<id<< "n'a ete trouve."<<std::endl<<std::endl;
}
