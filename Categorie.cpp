#include "Categorie.h"
#include <algorithm>

// Constructeur
Categorie::Categorie(const std::string& nomCategorie) : nom(nomCategorie) {}

const std::string& Categorie::getNom() const { return nom; }

// Méthodes

void Categorie::ajouterImage(int id, const std::string& nomFichier, const std::string& titre, const std::string& description, bool publique){
    Image nouvelleImage(id, nomFichier, titre,  description, publique);
    std::vector<Image> images;
    images.push_back(nouvelleImage);
    //std::cout<< "Nouvelle image: '"<<titre<<"' creee et ajoutee a la categorie '"<<nom<<"'.\n";
}

void Categorie::supprimerImage(int imageId) {
    for (auto it=images.begin(); it !=images.end(); ++it){
        if(it->id == imageId){
            std::cout<<"L'image '"<<it->titre<< "' a ete supprimee de la categorie '"<<nom<<"'." <<std::endl;
            images.erase(it);
            //return true;
        }
    }
    std::cout << "Aucune image avec l'ID " << imageId <<"n'a ete trouvee dans la categorie '" << nom << "'." << std::endl;
    //return false;
    //images.erase(std::remove_if(images.begin(), images.end(),
        //            [imageId](const Image& img) { return img.getId() == imageId; }), images.end());
}

void Categorie::listerImages() const {
    for (const auto& image : images) {
        std::cout << "Image ID: " << image.getId() << ", Titre: " << image.getTitre() << std::endl;
    }
}
