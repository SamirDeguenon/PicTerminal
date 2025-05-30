#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"
#include "Categorie.h"

//std::vector<Image> images; // Liste d'images

class Administrateur : public Utilisateur {
private:
    std::vector<Categorie> categories;
    //std::vector<Utilisateur> utilisateurs;
public:
    Administrateur() = default; //Constructeur par défaut
    Administrateur(int id, const std::string& nom, const std::string& email, const std::string& password, bool isAdmin);

    // Méthodes
    void approuverImage(int imageId);
    void rejeterImage(int imageId);
    void creerCategorie(/*const std::string& nom*/);
    void ajouterImagesDansCategorie(Categorie& categorie);
    void modifierCategorie(/*const std::string& nom*/);
    void supprimerCategorie(std::vector<Categorie>& categories);
    void consulterStatistiques(const std::vector<Image>& images, const std::vector<Utilisateur>& utilisateurs);
    void supprimerUtilisateur(std::vector<Utilisateur>& utilisateurs, int utilisateurId);
    void ajouterUtilisateur(std::vector<Utilisateur>& utilisateurs);
    void modifierUtilisateur(std::vector<Utilisateur>& utilisateurs);
};

#endif // ADMINISTRATEUR_H
