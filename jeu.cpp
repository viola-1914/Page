#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>

// Fonction pour récupérer un mot aléatoire dans une liste
std::string get_random_word(const std::vector<std::string>& words) {
    std::srand(std::time(nullptr));
    int index = std::rand() % words.size();
    return words[index];
}

// Fonction pour afficher l'état actuel du jeu
void display_game_state(const std::string& word, const std::vector<char>& guessed_letters) {
    for (char c : word) {
        if (std::find(guessed_letters.begin(), guessed_letters.end(), std::tolower(c)) != guessed_letters.end()) {
            std::cout << c << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

// Fonction pour jouer une partie de pendu
void play_hangman(const std::vector<std::string>& words) {
    std::string word = get_random_word(words);
    std::vector<char> guessed_letters;
    int remaining_attempts = 6;

    while (true) {
        display_game_state(word, guessed_letters);
        std::cout << "Tentatives restantes: " << remaining_attempts << std::endl;

        char guess;
        std::cout << "Entrez une lettre: ";
        std::cin >> guess;
        guess = std::tolower(guess);

        if (std::find(guessed_letters.begin(), guessed_letters.end(), guess) != guessed_letters.end()) {
            std::cout << "Vous avez déjà essayé cette lettre. Réessayez." << std::endl;
            continue;
        }

        guessed_letters.push_back(guess);

        if (word.find(guess) == std::string::npos) {
            remaining_attempts--;
            std::cout << "Mauvaise lettre. Vous perdez une tentative." << std::endl;
        } else {
            std::cout << "Bien joué ! La lettre " << guess << " est dans le mot." << std::endl;
        }

        if (remaining_attempts == 0) {
            display_game_state(word, guessed_letters);
            std::cout << "Vous avez perdu. Le mot était: " << word << std::endl;
            return;
        }

        bool won = true;
        for (char c : word) {
            if (std::find(guessed_letters.begin(), guessed_letters.end(), std::tolower(c)) == guessed_letters.end()) {
                won = false;
                break;
            }
        }
        if (won) {
            display_game_state(word, guessed_letters);
            std::cout << "Bravo, vous avez gagné !" << std::endl;
            return;
        }
    }
}

int main() {
    std::vector<std::string> words = {"pendu", "ordinateur", "programmation", "algorithmique", "variable"};
    play_hangman(words);
    return 0;
}