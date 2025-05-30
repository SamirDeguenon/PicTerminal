#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include <string>
#include <vector>
#include "Galerie.h"
#include "Image.h"

class Utilisateur {
protected:
    int id;
    std::string nom;
    std::string email;
    std::string password;
    bool isAdmin;
    Galerie galerie;
    std::vector<Image> favoris;

public:
    static std::vector<Image> imagesEnAttente; //Liste statique des images en attente d'approbation
    Utilisateur() = default; //Constructeur par défaut
    Utilisateur(int id, const std::string& nom, const std::string& email, const std::string& password, bool isAdmin);
    virtual ~Utilisateur()= default;

    //Mutateurs
    void setNom(const std::string& nom);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);

    // Accesseurs
    int getId() const;
    const std::string& getNom() const;
    const std::string& getEmail() const;
    const std::string& getPassword() const;
    bool getIsAdmin() const;

    //Methode pour modifier un utilisateur
    modifierUtilisateur(std::string nouveauNom, std::string nouvelEmail, std::string nouveauPassword);

    // Méthodes
    void switchToAdmin();
    void ajouterFavoris(const std::vector<Image>& image);
    //void setGalerie(Galerie* g);
    void ajouterImage(const Image& image);
    void telechargerImage(Image& image);
    void likerImage(Image& image);
    void consulterGalerie() const;
    void consulterFavoris() const;
};

#endif // UTILISATEUR_H
