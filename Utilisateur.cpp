#include "Utilisateur.h"
#include <algorithm>
#include "Image.h"
#include "Galerie.h"
#include <vector>
#include <iostream>

//Initialisation de la liste statique des images en attente
std::vector<Image> Utilisateur::imagesEnAttente;

std::vector<Image> images; // Déclaration du vecteur d'images

// Constructeur
Utilisateur::Utilisateur(int id, const std::string& nom, const std::string& email, const std::string& password, bool isAdmin = false)
    : id(id), nom(nom), email(email), password(password), isAdmin(isAdmin) {}

// Accesseurs
int Utilisateur::getId() const { return id; }
const std::string& Utilisateur::getNom() const { return nom; }
const std::string& Utilisateur::getEmail() const { return email; }
const std::string& Utilisateur::getPassword() const { return password; }
bool Utilisateur::getIsAdmin() const{return isAdmin;}

//Mutateurs
void Utilisateur::setNom(const std::string& nom){this->nom=nom;}
void Utilisateur::setEmail(const std::string& email){this->email=email;}
void Utilisateur::setPassword(const std::string& password){this->password=password;}

// Méthodes
void Utilisateur::switchToAdmin(){
    if(isAdmin){
        std::cout<<"Vous etes maintenant connecte en tant qu'administrateur.\n";
    }
    else{
        std::cout<<"Vous n'avez pas les droits pour passer en mode administrateur.\n";
    }
}

void Utilisateur::ajouterFavoris(const std::vector<Image>& image) {
    // Exemple d'ajout d'images (vous devez remplacer cela par des images réelles)
    images.push_back(Image(1, "image1.jpg", "Coucher du soleil", "Cette image montre le coucher du soleil", true));
    images.push_back(Image(2, "image2.jpg", "Footballeur", "Cette image montre un footballeur pret a tout pour gagner", false));

    int imageId;
    std::cout <<"Entrer l'ID de l'image a ajouter aux favoris: ";
    std::cin >> imageId;
    //Rechercher l'image par son id dans la liste des images disponibles
    bool found = false;
    for (auto& image : images){
        if(imageId == image.getId()){
            favoris.push_back(image);
            std::cout<<"Image ajoutee aux favoris.\n";
            found = true;
            break;
        }
    }
    if (!found){
        std::cout<<"Image introuvable.\n";
    }
}

void Utilisateur::ajouterImage(const Image& image) {
    //Ajouter l'image à la liste d'attente pour l'approbation
    imagesEnAttente.push_back(image);
    std::cout<<"Image '"<<image.getTitre()<< "' a ete ajoutee a la liste d'attente pour approbation.\n";
}

//void Utilisateur::setGalerie(Galerie* g) {
  //  galerie = g;
//}

void Utilisateur::telechargerImage(Image& image) {
    image.ajouterTelechargement(id);
    std::cout << "Telechargement reussi pour l'image: " <<
    image.getNomFichier() << "\n";
    //Ajouter l'image télécharée à la galerie de l'utilisateur
    galerie.ajouterImage(image);
    std::cout << "Image ajoutee a votre galerie.\n"<<std::endl<<std::endl;
}

void Utilisateur::likerImage(Image& image) {
    image.ajouterLike(id);
}

void Utilisateur::consulterGalerie() const {
    galerie.consulterImages();
}

void Utilisateur::consulterFavoris() const {
    for (const auto& image : favoris) {
        std::cout << "Favori ID: " << image.getId() << ", Titre: " << image.getTitre() << std::endl<<std::endl;
    }
}
