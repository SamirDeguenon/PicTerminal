#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include <vector>


class Image {
public:
    int id;
    std::string nomFichier;
    std::string titre;
    std::string description;
    bool publique;
    std::vector<int> telechargements; // Liste d'IDs d'utilisateurs ayant téléchargé l'image
    std::vector<int> likes; // Liste d'IDs d'utilisateurs ayant liké l'image

public:
    Image(int id, const std::string& nomFichier, const std::string& titre, const std::string& description, bool publique);

    // Accesseurs
    int getId() const;
    std::string getNomFichier() const;
    std::string getTitre() const;
    std::string getDescription() const;
    bool isPublique() const;
    const std::vector<int>& getTelechargements() const;
    const std::vector<int>& getLikes() const;

    // Méthodes
    void setPublique(bool publique);
    void ajouterTelechargement(int utilisateurId);
    void ajouterLike(int utilisateurId);
    void afficherInformations() const;
    bool peutAcceder(int utilisateurId) const;
};

#endif // IMAGE_H
