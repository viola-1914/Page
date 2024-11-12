#include<iostream>
int compare(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
        if (*chaine1 < *chaine2) {
            return -1; // chaine1 est plus petite que chaine2
        } else if (*chaine1 > *chaine2) {
            return 1; // chaine1 est plus grande que chaine2
        }
        chaine1++;
        chaine2++;
    }

    if (*chaine1 == '\0' && *chaine2 == '\0') {
        return 0; // les chaînes sont égales
    } else if (*chaine1 == '\0') {
        return -1; // chaine1 est plus petite que chaine2
    } else {
        return 1; // chaine1 est plus grande que chaine2
    }
}
void inverser_chaine(char* chaine) {
    char* debut = chaine;
    char* fin = chaine;

    // Trouver la fin de la chaîne
    while (*fin != '\0') {
        fin++;
    }
    fin--;

    // Inverser la chaîne
    while (debut < fin) {
        char temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}
int main() {
    char chaine1[] = "Hello";
    char chaine2[] = "World";

    int resultat = compare(chaine1, chaine2);
    if (resultat < 0) {
        std::cout << "chaine1 est plus petite que chaine2" << std::endl;
    } else if (resultat > 0) {
        std::cout << "chaine1 est plus grande que chaine2" << std::endl;
    } else {
        std::cout << "les chaînes sont égales" << std::endl;
    }

    char* trouve = cherche_char(chaine1, 'l');
    if (trouve != NULL) {
        std::cout << "Caractère trouvé à l'adresse : " << (void*)trouve << std::endl;
    } else {
        std::cout << "Caractère non trouvé" << std::endl;
    }

    char chaine3[] = "Bonjour";
    inverser_chaine(chaine3);
    std::cout << "Chaîne inversée : " << chaine3 << std::endl;

    return 0;
}