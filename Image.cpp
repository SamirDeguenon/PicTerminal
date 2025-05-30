#include "Image.h"
#include <iostream>
#include <algorithm>

// Constructeur
Image::Image(int id, const std::string& nomFichier, const std::string& titre, const std::string& description, bool publique)
    : id(id), nomFichier(nomFichier), titre(titre), description(description), publique(publique) {}

// Accesseurs
int Image::getId() const { return id; }
std::string Image::getNomFichier() const { return nomFichier; }
std::string Image::getTitre() const { return titre; }
std::string Image::getDescription() const { return description; }
bool Image::isPublique() const { return publique; }
const std::vector<int>& Image::getTelechargements() const { return telechargements; }
const std::vector<int>& Image::getLikes() const { return likes; }

// Méthodes
void Image::setPublique(bool publique) {
    this->publique = publique;
    if(publique){
        std::cout<<"L'image est maintenant publique."<<std::endl;
    }
    else{
        std::cout<<"L'image est maintenant privee."<<std::endl;
    }
}

//void Image::setCategorie(const std::string& categorie) {
  //  this->categorie = categorie;
    //std::cout<<"L'image '"<<titre<< "' a ete assignee a la categorie '"<<categorie<<"'."<<std::endl;
//}

void Image::ajouterTelechargement(int utilisateurId) {
    telechargements.push_back(utilisateurId);
}

void Image::ajouterLike(int utilisateurId) {
    likes.push_back(utilisateurId);

}



void Image::afficherInformations() const {
    std::cout<<"ID: "<<id<<std::endl;
    std::cout<<"Titre: "<<titre<<std::endl;
    std::cout<<"Description: "<<description<<std::endl;
    std::cout<<"Visibilite: "<<(publique ? "Publique" : "Privee")<<std::endl;
    std::cout<<"Nombre de likes: "<<likes.size()<<std::endl;
    std::cout<<"Nombre de telechargements: "<<telechargements.size()<<std::endl;
}
bool Image::peutAcceder(int utilisateurId) const { // Seuls les utilisateurs peuvent accéder à une image publique ou si leur ID est dans les téléchargements.
    return publique || std::find(telechargements.begin(), telechargements.end(), utilisateurId) != telechargements.end();
}
