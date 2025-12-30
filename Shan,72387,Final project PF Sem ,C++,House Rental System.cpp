
#include <iostream>
#include <string>

using namespace std;

// ---------------- STRUCTURES ----------------
struct House {
    string city;
    string area;
    string houseName;
    int price;
};

// ----------------  ARRAYS ----------------

House houses[100]; 
int houseCount = 0; 

string cityList[20]; 
int cityCount = 0;

int priceRanges[20]; 
int priceCount = 0;

string bookingHistory[50]; 
int historyCount = 0;

// ---------------- FUNCTION DECLARATIONS ----------------
void mainMenu();
void userMenu();
void adminMenu();

void searchRent(); 
void processPayment(int houseIndex);

//....... Admin Functions........
void adminAddCity();
void adminAddPrice();
void adminAddHouse();
void adminUpdateHouse();
void adminDeleteMenu();
void adminDeleteCity();
void adminDeleteHouse();
void adminViewAll();
void adminHistory();

void wait() {
    cout << "\nPress any key and Enter to continue...";
    char temp;
    cin >> temp; 
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    // 1. Initialize
    cityList[cityCount++] = "Islamabad";
    cityList[cityCount++] = "Rawalpindi";
    cityList[cityCount++] = "Lahore";
    cityList[cityCount++] = "Karachi";

    // 2. Initialize 
    priceRanges[priceCount++] = 30000;
    priceRanges[priceCount++] = 50000;
    priceRanges[priceCount++] = 100000;

    // 3. Initialize Houses
    houses[houseCount++] = {"Islamabad", "G-13", "House-21", 35000};
    houses[houseCount++] = {"Islamabad", "F-7", "House-12", 90000};
    houses[houseCount++] = {"Islamabad", "I-14", "House-7", 25000}; 

    houses[houseCount++] = {"Rawalpindi", "Saddar", "House-44", 30000};
    houses[houseCount++] = {"Rawalpindi", "Wah_Cantt", "House-90", 46000};
    houses[houseCount++] = {"Rawalpindi", "Shamsabad", "House-55", 75000};

    houses[houseCount++] = {"Lahore", "AJP_Road", "House-14", 28000};     
    houses[houseCount++] = {"Lahore", "Ghanta_Ghar", "House-30", 40000};  
    houses[houseCount++] = {"Lahore", "DHA", "House-99", 85000};          

    houses[houseCount++] = {"Karachi", "Liaquatabad", "House-10", 25000}; 
    houses[houseCount++] = {"Karachi", "Gulshan", "House-5", 45000};      
    houses[houseCount++] = {"Karachi", "Clifton", "House-80", 95000};     

    mainMenu();
    return 0;
}

// ---------------- MAIN MENU --------------------
void mainMenu() {
    int choice;
    do {
        cout << "\n=============================\n";
        cout << "   HOUSE RENTAL SYSTEM \n";
        cout << "=============================\n";
        cout << "1. User Panel\n";
        cout << "2. Admin Panel\n";
        cout << "3. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) userMenu();
        else if (choice == 2) {
            string pass;
            cout << "Enter Password: ";
            cin >> pass;
            if (pass == "shan123" ) adminMenu();
            else { cout << "Wrong Password!\n"; wait(); }
        }
        else if (choice == 3) cout << "Goodbye!\n";
        else { cout << "Invalid.\n"; wait(); }

    } while (choice != 3);
}

// ---------------- USER MENU --------------------
void userMenu() {
    int choice;
    while(true) {
        cout << "\n---- USER PANEL ----\n";
        cout << "1. Search for Rent\n";
        cout << "2. Back to Main Menu\n";
        cout << "Select: ";
        cin >> choice;

        if(choice == 1) searchRent();
        else if(choice == 2) return;
    }
}

// ---------------- SEARCH  ----------------

void searchRent() {
    if(cityCount == 0) { cout << "No cities available.\n"; return; }

    cout << "\n--- Select City ---\n";
    for(int i = 0; i < cityCount; i++) {
        cout << i+1 << ". " << cityList[i] << endl;
    }
    cout << "Select City Number: ";
    int cityChoice;
    cin >> cityChoice;

    if(cityChoice < 1 || cityChoice > cityCount) {
        cout << "Invalid City.\n";
        return;
    }
    string selectedCity = cityList[cityChoice - 1];

    cout << "\nAvailable Houses in " << selectedCity << ":\n";
    
    int count = 0;
    for(int i = 0; i < houseCount; i++) {
        if(houses[i].city == selectedCity) {
            count++;
            cout << count << ". " << houses[i].area << " - " << houses[i].houseName 
                 << " (Rent: " << houses[i].price << ")\n";
        }
    }

    if(count == 0) {
        cout << "No houses found here.\n";
        return;
    }

    cout << "\nSelect House Number to Book: ";
    int houseChoice;
    cin >> houseChoice;

    if(houseChoice < 1 || houseChoice > count) {
        cout << "Invalid Selection.\n";
        return;
    }

    int currentSearch = 0;
    for(int i = 0; i < houseCount; i++) {
        if(houses[i].city == selectedCity) {
            currentSearch++;
            if(currentSearch == houseChoice) {
                processPayment(i);
                return;
            }
        }
    }
}

// ---------------- PAYMENT ----------------

void processPayment(int index) {
    cout << "\nSelected Property: " << houses[index].houseName << endl;
    cout << "Location: " << houses[index].area << ", " << houses[index].city << endl;
    cout << "Base Rent: Rs. " << houses[index].price << endl;

    int months;
    cout << "\nEnter Duration (Months): ";
    cin >> months;
    if (months < 1) { cout << "Invalid.\n"; return; }

    long totalRent = houses[index].price * months;
    long security = houses[index].price; 
    long tax = (houses[index].price * 0.05) * months;
    long grandTotal = totalRent + security + tax;

    cout << "\n--- BILL BREAKDOWN ---\n";
    cout << "Rent: " << totalRent << "\nSecurity: " << security << "\nTax (5%): " << tax << endl;
    cout << "GRAND TOTAL: " << grandTotal << endl;

    cout << "\nView Agreement (1. Yes / 2. No): ";
    int agree; cin >> agree;
    
    if (agree == 1) {
        cout << "\n======================================================\n";
        cout << "      RENTAL AGREEMENT TERMS (Pakistani Law)          \n";
        cout << "======================================================\n";
        cout << "1. [Rent Payment]: Rent must be paid by the 5th of every month.\n";
        cout << "2. [Security]: One month deposit is held as refundable security.\n";
        cout << "3. [Bills]: Electricity, Gas & Water bills are paid by Tenant.\n";
        cout << "4. [Maintenance]: Structural repairs are Landlord's duty.\n";
        cout << "5. [Usage]: Illegal activities are strictly prohibited.\n";
        cout << "6. [Notice Period]: 30-day notice required before vacating.\n";
        cout << "======================================================\n";
        
        cout << "\nDo you accept these terms? (1. Yes / 2. No): ";
        int confirm; cin >> confirm;
        
        if (confirm == 1) {
            cout << "\n[SUCCESS] Agreement Signed. Booking Confirmed!\n";
            
            if (historyCount < 50) {
                bookingHistory[historyCount] = "Booked: " + houses[index].houseName + " by User.";
                historyCount++;
            }
        } else {
            cout << "\n[CANCELLED] You declined the agreement.\n";
        }
    }
    wait(); 
}

// ---------------- ADMIN PANEL ------------------
void adminMenu() {
    int choice;
    while(true) {
        cout << "\n==== ADMIN PANEL ====\n";
        cout << "1. Add City\n2. Add Price\n3. Add House\n";
        cout << "4. Update House\n5. Delete Items\n6. View All\n7. History\n8. Back\nSelect: ";
        cin >> choice;

        if(choice == 1) adminAddCity();
        else if(choice == 2) adminAddPrice();
        else if(choice == 3) adminAddHouse();
        else if(choice == 4) adminUpdateHouse();
        else if(choice == 5) adminDeleteMenu();
        else if(choice == 6) { adminViewAll(); wait(); }
        else if(choice == 7) { adminHistory(); wait(); }
        else if(choice == 8) return;
    }
}

void adminAddCity() {
    if(cityCount >= 20) { cout << "Memory Full!\n"; return; }
    cout << "City Name: ";
    cin >> cityList[cityCount];
    cityCount++; 
    cout << "Saved.\n";
}

void adminAddPrice() {
    if(priceCount >= 20) { cout << "Memory Full!\n"; return; }
    cout << "Price Cap: ";
    cin >> priceRanges[priceCount];
    priceCount++;
    cout << "Saved.\n";
}

void adminAddHouse() {
   
    if(houseCount >= 100) { cout << "Memory Full!\n"; return; }
    
    cout << "\n(Note: Use Underscores for spaces. e.g. Blue_Area)\n";
    cout << "City: "; cin >> houses[houseCount].city;
    cout << "Area: "; cin >> houses[houseCount].area;
    cout << "Name: "; cin >> houses[houseCount].houseName;
    cout << "Rent: "; cin >> houses[houseCount].price;
    
    houseCount++; 
    cout << "Saved.\n";
}

void adminUpdateHouse() {
    adminViewAll();
    cout << "Enter ID to update: ";
    int id; cin >> id;
    if(id > 0 && id <= houseCount) {
        id--; 
        cout << "New City: "; cin >> houses[id].city;
        cout << "New Area: "; cin >> houses[id].area;
        cout << "New Name: "; cin >> houses[id].houseName;
        cout << "New Rent: "; cin >> houses[id].price;
        cout << "Updated.\n";
    }
}

void adminViewAll() {
    cout << "\n--- All Houses List ---\n";
    for(int i=0; i<houseCount; i++) {
        cout << i+1 << ". " << houses[i].city << " | " << houses[i].area 
             << " | " << houses[i].houseName << " | Rs. " << houses[i].price << endl;
    }
}

void adminHistory() {
    cout << "\n--- Booking History ---\n";
    for(int i=0; i<historyCount; i++) cout << "- " << bookingHistory[i] << endl;
}

// ---------------- DELETE  ----------------
void adminDeleteMenu() {
    cout << "1. Delete City\n2. Delete House\n3. Back\nSelect: ";
    int c; cin >> c;
    if(c == 1) adminDeleteCity();
    else if(c == 2) adminDeleteHouse();
}

void adminDeleteCity() {
    cout << "Select City to Delete:\n";
    for(int i=0; i<cityCount; i++) cout << i+1 << ". " << cityList[i] << endl;
    
    int id; cin >> id;
    if(id > 0 && id <= cityCount) {
        for(int i = id-1; i < cityCount - 1; i++) {
            cityList[i] = cityList[i+1];
        }
        cityCount--; 
        cout << "Deleted.\n";
    }
}

void adminDeleteHouse() {
    adminViewAll();
    cout << "Select House to Delete: ";
    int id; cin >> id;
    
    if(id > 0 && id <= houseCount) {
        for(int i = id-1; i < houseCount - 1; i++) {
            houses[i] = houses[i+1];
        }
        houseCount--; 
        cout << "Deleted.\n";
    }
}