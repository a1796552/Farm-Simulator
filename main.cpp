#include <iostream>
#include "Farm.h"
#include "Market.h"
#include "Inventory.h"
using namespace std;

// Function to get a valid numeric input
int getValidInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(1000, '\n'); // ignore invalid input
            cout << "Invalid input. Please enter a number: ";
        } else {
            return input;
        }
    }
}

// main menu function
void displayMenu() {
    cout << "Welcome to Farm Management Simulator!\n";
    cout << "1. Farm\n";
    cout << "2. Market\n";
    cout << "3. Advance day\n";
    cout << "4. Show Inventory\n";
    cout << "5. Save game\n";
    cout << "6. Load game\n";
    cout << "7. Exit\n";
}

// farm menu function
void displayFarmMenu() {
    cout << "\n--- Farm Management ---\n";
    cout << "1. Plant Crops\n";
    cout << "2. Harvest Crops\n";
    cout << "3. List Crops\n";
    cout << "4. Return to Main Menu\n";
}

// market menu function
void displayMarketMenu() {
    cout << "\n--- Market ---\n";
    cout << "1. Buy Seeds\n";
    cout << "2. Sell Produce\n";
    cout << "3. Check Market Prices\n";
    cout << "4. Return to Main Menu\n";
}

int main() {
    
    Farm myFarm;  // Farm object to manage the farm's state

    int choice;
    Market market; // Market object

    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        choice = getValidInput(); // Use input validation here
        cout << endl;

        switch (choice) {
            case 1: {
                int farmChoice;
                do {
                    displayFarmMenu();
                    cout << "\nEnter your choice: ";
                    farmChoice = getValidInput(); // Use input validation here;
                    cout << endl;

                    switch (farmChoice) {
                        case 1:
                            myFarm.plantCrops();
                            break;
                        case 2:
                            myFarm.harvestCrops();
                            break;
                        case 3:
                            myFarm.listAssets();  // List all crops
                            break;
                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (farmChoice != 4);  // Loops the farm menu until "Return to Main Menu" is selected
                break;
            }

            case 2: {
                int marketChoice;
                do {
                    // Display the player's current balance
                    cout << "\n--- Market ---\n";
                    cout << "Player's current balance: $" << myFarm.getBalance() << "\n";  // Show balance
                    
                    displayMarketMenu();  // Show the market options
                    cout << "\nEnter your choice: ";
                    marketChoice = getValidInput(); // Use input validation here;
                    cout << endl;

                    switch (marketChoice) {
                        case 1: {  // Buy seeds from the market
                            int seedChoice;
                            int quantity;

                            // Present options to the user
                            cout << "Which seed would you like to buy?\n";
                            cout << "1. Corn ($3.00 per seed)\n";
                            cout << "2. Wheat ($2.00 per seed)\n";
                            cout << "Enter your choice: ";
                            seedChoice = getValidInput(); // Use input validation here;

                            // Input validation to ensure valid choice
                            while (seedChoice != 1 && seedChoice != 2) {
                                cout << "Invalid choice. Please select 1 for Corn or 2 for Wheat: ";
                                cin >> seedChoice;
                            }

                            cout << "Enter quantity: ";
                            quantity = getValidInput(); // Use input validation here;

                            // Set the seed type based on user choice
                            string seedType;
                            if (seedChoice == 1) {
                                seedType = "Corn";
                            } else {
                                seedType = "Wheat";
                            }

                            // Add seeds to inventory and deduct balance inside Market::buySeeds
                            market.buySeeds(seedType + " Seeds", quantity, myFarm.getBalance(), myFarm.getInventory());

                            break;
                        }

                        case 2: {  // Sell crops
                            market.sellProduce(myFarm.getBalance(), myFarm.getInventory());
                            break;
                        }

                        case 3:
                            market.checkMarketPrices();  // Check market prices
                            break;
                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (marketChoice != 4);
                break;
            }


            case 3:
                myFarm.nextDay(market);   // Advance to next day
                break;

            case 4:
                myFarm.showInventory();  // Show the player's inventory
                break;

            case 5:
                myFarm.saveGame("savegame.txt");
                break;

            case 6:
                myFarm.loadGame("savegame.txt");
                break;

            case 7:
                cout << "Exiting the game. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
