#include <iostream>

// Prototype de la fonction
void copie(char *dest, const char *source) {
    while (*source != '\0') { // Tant que le caractère source n'est pas le terminateur de chaîne
        *dest = *source; // Copie le caractère de source à dest
        dest++; // Avance le pointeur de destination
        source++; // Avance le pointeur de source
    }
    *dest = '\0'; // Ajoute le caractère nul à la fin de la chaîne destination
}

int main() {
    const char* source = "Hello, World!"; // Chaîne source
    char dest[50]; // Chaîne de destination avec suffisamment d'espace

    copie(dest, source); // Appelle la fonction copie

    std::cout << "Chaîne copiée : " << dest << std::endl; // Affiche le résultat

    return 0;
}