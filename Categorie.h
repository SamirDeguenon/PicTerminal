#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <iostream>
#include <string>
#include <vector>
#include "Image.h"

class Categorie {
public:
    std::string nom;
    std::vector<Image> images; // Liste d'images dans la catégorie

    const std::string& getNom() const;

    Categorie(const std::string& nomCategorie);
    void ajouterImage(int id, const std::string& nomFichier, const std::string& titre, const std::string& description, bool publique);
    void supprimerImage(int imageId);
    void listerImages() const;
};

#endif // CATEGORIE_H
