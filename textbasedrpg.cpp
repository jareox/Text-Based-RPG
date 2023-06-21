#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number within a range
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerDamage;
    int enemyDamage;
    string playerName;
    
    cout << "Welcome to the Text RPG!" << endl;
    cout << "Enter your name: ";
    cin >> playerName;
    
    cout << "Hello, " << playerName << "! Get ready to battle!" << endl;
    
    // Game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        playerDamage = getRandomNumber(10, 20);
        enemyDamage = getRandomNumber(5, 15);
        
        cout << endl << "Player Health: " << playerHealth << "\tEnemy Health: " << enemyHealth << endl;
        
        // Player's turn
        cout << "Player's turn. Choose your action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Run" << endl;
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            enemyHealth -= playerDamage;
            cout << "You attacked the enemy for " << playerDamage << " damage!" << endl;
        } else {
            cout << "You ran away!" << endl;
            break; // Exit the game loop
        }
        
        // Enemy's turn
        cout << "Enemy's turn." << endl;
        playerHealth -= enemyDamage;
        cout << "The enemy attacked you for " << enemyDamage << " damage!" << endl;
    }
    
    // Game over
    if (playerHealth <= 0) {
        cout << "Game Over! You were defeated." << endl;
    } else {
        cout << "Congratulations! You defeated the enemy." << endl;
    }
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}
