#include <iostream>
#include "Farm.h"
#include "Market.h"
using namespace std;

// main menu function
void displayMenu() {
    cout << "Welcome to Farm Management Simulator!\n";
    cout << "1. Farm\n";
    cout << "2. Market\n";
    cout << "3. Advance day\n";
    cout << "4. Save game\n";
    cout << "5. Load game\n";
    cout << "6. Exit\n";
}

// farm menu function
void displayFarmMenu() {
    cout << "\n--- Farm Management ---\n";
    cout << "1. Plant Crops\n";
    cout << "2. Harvest Crops\n";
    cout << "3. Feed Animals\n";
    cout << "4. Collect Animal Produce\n";
    cout << "5. List Crops and Animals\n";
    cout << "6. Return to Main Menu\n";
}

// market menu function
void displayMarketMenu() {
    cout << "\n--- Market ---\n";
    cout << "1. Buy Crops\n";
    cout << "2. Sell Produce\n";
    cout << "3. Check Market Prices\n";
    cout << "4. Return to Main Menu\n";
}

int main() {
    // declaring variables for player balance, harvested crops, and animal products
    float playerBalance = 100.0;  // example starting balance
    int harvestedCrops = 5;       // example number of harvested crops
    int animalProducts = 3;       // example number of animal products

    int choice;

    Farm myFarm;  // will have to change based on the name decided for the class
    Market market; // defining market

    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                int farmChoice;
                do {
                    displayFarmMenu();
                    cout << "\nEnter your choice: ";
                    cin >> farmChoice;
                    cout << endl;

                    switch (farmChoice) {
                        case 1:
                            myFarm.plantCrops();
                            break;
                        case 2:
                            myFarm.harvestCrops();
                            break;
                        case 3:
                            myFarm.feedAnimals();
                            break;
                        case 4:
                            myFarm.collectProduce();
                            break;
                        case 5:
                            myFarm.listAssets();  // This will now return to the farm menu after listing
                            break;
                        case 6:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (farmChoice != 6);  // Loops the farm menu until "Return to Main Menu" is selected
                break;
            }

            case 2: {
                int marketChoice;
                do {
                    displayMarketMenu();
                    cout << "\nEnter your choice: ";
                    cin >> marketChoice;
                    cout << endl;

                    switch (marketChoice) {
                        case 1:
                            market.buyCrops(playerBalance);  // Call Market method to buy crops
                            break;
                        case 2:
                            market.sellProduce(playerBalance, harvestedCrops, animalProducts);  // Call Market method to sell produce
                            break;
                        case 3:
                            market.checkMarketPrices();  // Call Market method to check prices
                            break;
                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (marketChoice != 4);  // Loops the market menu until "Return to Main Menu" is selected
                break;
            }

            case 3:
                myFarm.nextDay();   // Advance to next day
                break;

            case 4:
                // myFarm.saveGame();
                break;
            
            case 5:
                // myFarm.loadGame();
                break;

            case 6:
                cout << "Exiting the game. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
