#include <iostream>
using namespace std;

int main() {
    int mainChoice, userChoice, priceChoice, houseChoice, adminChoice;
    string pass;

    // Hardcoded Data
    string city = "Islamabad";
    string priceRange = "Less than 30000";
    string house = "2 Marla House # 18 ST 5-25000 G-13";
    int rent = 25000; 

    do {
        cout << "\n=== Welcome to SM House Rental Company ===\n";
        cout << "1. User Panel\n";
        cout << "2. Admin Panel\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        
        // ========= USER PANEL =========
        case 1:
            do {
                cout << "\n--- USER PANEL ---\n";
                cout << "1. " << city << endl;
                cout << "2. Back\n";
                cout << "Enter choice: ";
                cin >> userChoice;

                if (userChoice == 1) {
                    cout << "\nPrice Range:\n";
                    cout << "1. " << priceRange << endl;
                    cout << "2. Back\n";
                    cout << "Enter choice: ";
                    cin >> priceChoice;

                    if (priceChoice == 1) {
                        cout << "\nAvailable Houses:\n";
                        cout << "1. " << house << endl;
                        cout << "2. Back\n";
                        cout << "Enter choice: ";
                        cin >> houseChoice;

                        if (houseChoice == 1) {
                            // Total cost calculation
                            int security = rent;               
                            double tax = rent * 0.05;             
                            double total = rent + security + tax; 

                            cout << "\n--- RENT AGREEMENT SUMMARY ---\n";
                            cout << "Monthly Rent: " << rent << endl;
                            cout << "1 Month Security: " << security << endl;
                            cout << "Government Tax (5%): " << tax << endl;
                            cout << "Total Payable Amount: " << total << endl;
                            cout << "Agreement: 1 Year Stamp Paper (As per Pakistan Law)\n";
                            cout << "Status: Booking Confirmed!\n";

                            cout << "\nType any key and press Enter to go back...";
                            cin >> pass;
                        }
                    }
                }
            } while (userChoice != 2);
            break;

        // ========= ADMIN PANEL =========
        case 2:
            {
                
                int attempts = 0;
                bool accessGranted = false;

                while (attempts < 3) {
                    cout << "\nEnter Admin Password: ";
                    cin >> pass;

                    if (pass == "Shan123") {
                        accessGranted = true;
                        break;
                    } else {
                        attempts++;
                        cout << "Incorrect Password! You have " << (3 - attempts) << " attempts left.\n";
                    }
                }

                if (accessGranted) {
                    do {
                        cout << "\n--- ADMIN PANEL ---\n";
                        cout << "1. Add New City\n";
                        cout << "2. Add New Price Range\n";
                        cout << "3. Add New Area / House Listing\n";
                        cout << "4. Update Existing House Details\n";
                        cout << "5. Delete City / Price Range / Area / House\n";
                        cout << "6. View All Houses\n";
                        cout << "7. View All Cities & Price Ranges\n";
                        cout << "8. View Booking History\n";
                        cout << "9. Back\n";
                        cout << "Enter choice: ";
                        cin >> adminChoice;

                        if (adminChoice >= 1 && adminChoice <= 8) {
                            cout << "\n(Project is under construction)\n";
                            cout << "Type any key and press Enter to go back...";
                            cin >> pass;
                        }

                    } while (adminChoice != 9);
                } else {
                    cout << "\nAccess Denied! Returning to Main Menu.\n";
                }
            }
            break;

        // ========= EXIT =========
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid Choice! Please try again.\n";
        }

    } while (mainChoice != 3);

    return 0;
}