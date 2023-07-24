#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>

// Skin structure
struct Skin {
    std::string name;
    int price;
};

// User structure
struct User {
    std::string username;
    std::vector<Skin> skinsOwned;
    int totalSpent;
};

// Database to store users
std::map<std::string, User> userDatabase;

// Function to display the main menu
void displayMainMenu() {
    std::cout << "-------------------------\n";
    std::cout << "1. Show skins owned\n";
    std::cout << "2. Buy skins\n";
    std::cout << "3. Total spent on skins\n";
    std::cout << "4. Exit\n";
    std::cout << "-------------------------\n";
    std::cout << "Enter your choice: ";
}

// Function to display available skins
void displaySkinsMenu() {
    std::cout << "-------------------------\n";
    std::cout << "Available skins:\n";
    std::cout << "1. Pistols\n";
    std::cout << "2. Rifles\n";
    std::cout << "3. Operators\n";
    std::cout << "4. Knives\n";
    std::cout << "-------------------------\n";
    std::cout << "Enter the weapon type: ";
}

// Function to create a new user
void createNewUser() {
    std::string username;
    std::cout << "Enter a username: ";
    std::cin >> username;

    // Check if the user already exists
    if (userDatabase.find(username) == userDatabase.end()) {
        User newUser;
        newUser.username = username;
        newUser.totalSpent = 0;
        userDatabase[username] = newUser;
        std::cout << "New user created successfully!\n";
    } else {
        std::cout << "User already exists!\n";
    }
}

// Function to show skins owned by a user
void showSkinsOwned(User& user) {
    std::cout << "Skins owned by " << user.username << ":\n";
    for (const auto& skin : user.skinsOwned) {
        std::cout << skin.name << " - $" << skin.price << "\n";
    }
    std::cout << "-------------------------\n";
}

// Function to buy a skin
void buySkin(User& user) {
    displaySkinsMenu();
    int choice;
    std::cin >> choice;

    std::vector<Skin> skins;
    switch (choice) {
        case 1:  // Pistols
            skins = {{"Prime Classic", 10}, {"Ruinantion Ghost", 20}, {"Reaver Sheriff", 30}};
            break;
        case 2:  // Rifles
            skins = {{"Oni Phantom", 50}, {"Reaver Vandal", 75}, {"Sentinels of Light Vandal", 60}};
            break;
        case 3:  // Operators
            skins = {{"Glitchpop Operator", 125}, {"Origin Operator", 100}, {"Reaver Operator", 150}};
            break;
        case 4:  // Knives
            skins = {{"Ion Melee", 200}, {"Prime Knife", 250}, {"Ruination Sword", 300}};
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    std::cout << "Available skins:\n";
    for (size_t i = 0; i < skins.size(); ++i) {
        std::cout << i + 1 << ". " << skins[i].name << " - $" << skins[i].price << "\n";
    }
    std::cout << "Enter the skin number: ";
    int skinChoice;
    std::cin >> skinChoice;

    if (skinChoice >= 1 && skinChoice <= static_cast<int>(skins.size())) {
        Skin selectedSkin = skins[skinChoice - 1];
        user.skinsOwned.push_back(selectedSkin);
        user.totalSpent += selectedSkin.price;
        std::cout << "Skin purchased successfully!\n";
    } else {
        std::cout << "Invalid skin choice!\n";
        return;
    }
}

// Function to display the total amount spent on skins
void displayTotalSpent(User& user) {
    std::cout << "Total spent by " << user.username << ": $" << user.totalSpent << "\n";
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "-------------------------\n";
        std::cout << "1. Choose an existing user\n";
        std::cout << "2. Create a new user\n";
        std::cout << "3. Exit\n";
        std::cout << "-------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) 
        {
            std::cout << "Invalid choice! Please enter a valid numeric choice.\n";
            std::cin.clear();                // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters
            continue;                        // Prompt the user for a valid choice again
        }

        if (choice == 1) {
            std::string username;
            std::cout << "Enter your username: ";
            std::cin >> username;

            if (userDatabase.find(username) != userDatabase.end()) {
                User& currentUser = userDatabase[username];
                while (true) {
                    displayMainMenu();
                    std::cin >> choice;


                    if (std::cin.fail()) 
        {
            std::cout << "Invalid choice! Please enter a valid numeric choice.\n";
            std::cin.clear();                // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters
            continue;                        // Prompt the user for a valid choice again
        }

                    switch (choice) {
                        case 1:
                            showSkinsOwned(currentUser);
                            break;
                        case 2:
                            buySkin(currentUser);
                            break;
                        case 3:
                            displayTotalSpent(currentUser);
                            break;
                        case 4:
                            break;
                        default:
                            std::cout << "Invalid choice!\n";
                            continue;
                    }

                    if (choice == 4) {
                        break;
                    }
                }
            } else {
                std::cout << "User does not exist!\n";
            }
        } else if (choice == 2) {
            createNewUser();
        } else if (choice == 3) {
            
            break;
        } else {
            std::cout << "Invalid choice!\n";
            continue;
        }
    }

    std::cout << "Exiting the program...\n";

    return 0;
}