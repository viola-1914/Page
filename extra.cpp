#include<iostream>
void sous_chaine(const char* source, char* dest, int debut, int longueur) {
    int i = 0;
    for (int j = debut; j < debut + longueur && source[j] != '\0'; j++) {
        dest[i++] = source[j];
    }
    dest[i] = '\0'; // Terminer la chaîne
}
void supprime_caractere(char* chaine, char caractere) {
    int i = 0, j = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] != caractere) {
            chaine[j++] = chaine[i];
        }
        i++;
    }
    chaine[j] = '\0'; // Terminer la chaîne
}
int compte_mots(const char* phrase) {
    int compteur = 0;
    bool estDansUnMot = false;

    while (*phrase != '\0') {
        if (*phrase == ' ' || *phrase == '\t' || *phrase == '\n') {
            if (estDansUnMot) {
                compteur++;
                estDansUnMot = false;
            }
        } else {
            estDansUnMot = true;
        }
        phrase++;
    }

    if (estDansUnMot) {
        compteur++;
    }

    return compteur;
}
int main() {
    char source[] = "Hello, world!";
    char dest[20];
    sous_chaine(source, dest, 7, 5);
    std::cout << "Sous-chaîne : " << dest << std::endl; // Affiche "world"

    char chaine[] = "Hello, world! Hi, there!";
    supprime_caractere(chaine, ',');
    std::cout << "Chaîne sans ',' : " << chaine << std::endl; // Affiche "Hello world! Hi there!"

    const char* phrase = "  Hello,   world!   Hi,   there!  ";
    int mots = compte_mots(phrase);
    std::cout << "Nombre de mots : " << mots << std::endl; // Affiche 8

    return 0;
}