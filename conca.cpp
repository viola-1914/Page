#include <iostream>

// Fonction qui concatène src à dest
char* my_strcat(char* dest, const char* src) {
    // Trouver la fin de la chaîne dest
    char* ptr = dest; // Pointeur pour parcourir dest
    while (*ptr != '\0') { // Tant que nous ne sommes pas à la fin de dest
        ptr++; // Avance le pointeur
    }

    // Copie src à la fin de dest
    while (*src != '\0') { // Tant que nous ne sommes pas à la fin de src
        *ptr = *src; // Copie le caractère
        ptr++; // Avance le pointeur de dest
        src++; // Avance le pointeur de src
    }

    *ptr = '\0'; // Ajoute le caractère nul à la fin de la chaîne concaténée
    return dest; // Retourne la chaîne concaténée
}

int main() {
    char dest[50] = "Bonjour, "; // Chaîne de destination avec suffisamment d'espace
    const char* src = "monde!"; // Chaîne source

    my_strcat(dest, src); // Appelle la fonction my_strcat
    std::cout << "Chaîne concaténée : " << dest << std::endl; // Affiche le résultat

    return 0;
}