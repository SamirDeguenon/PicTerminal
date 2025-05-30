#ifndef GALERIE_H
#define GALERIE_H

#include <iostream>
#include <vector>
#include "Image.h"

class Galerie {
public:
    std::vector<Image> images; // Liste d'images
    int proprietaire; // ID du propriétaire

    void ajouterImage(const Image& image);
    void supprimerImage(int imageId);
    void consulterImages() const;
};

#endif // GALERIE_H
