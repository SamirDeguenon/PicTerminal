#include "Galerie.h"
#include <algorithm>

// Méthodes
void Galerie::ajouterImage(const Image& image) {
    images.push_back(image);
}

void Galerie::supprimerImage(int imageId) {
    images.erase(std::remove_if(images.begin(), images.end(),
                 [imageId](const Image& img) { return img.getId() == imageId; }), images.end());
}

void Galerie::consulterImages() const {
    if(images.empty()){
        std::cout<<"La galerie est vide"<<std::endl<<std::endl;
    }
    else{
        std::cout<<"Voici les images de la galerie: "<<std::endl;
        for (const auto& image : images) {
            image.afficherInformations();
            std::cout<<"-----------------------------------"<<std::endl;
        }
    }

}
