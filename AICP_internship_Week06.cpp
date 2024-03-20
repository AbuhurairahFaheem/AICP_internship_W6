#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

struct Ticket {
    string type;
    double oneDayPrice;
    double twoDaysPrice;
};

struct ExtraAttraction {
    string name;
    double costPerPerson;
};

void displayTicketTable() {
    cout << "\t\t\t\t*WELCOME TO WILDLIFE PARK TICKET STORE*\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(100) << std::setfill('_') << "_" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(60) << std::left << "Ticket type"
        << std::setw(25) << std::right << "Cost for one day|"
        << std::setw(20) << std::right << "Cost for two days" << std::endl;

    std::cout << std::setw(100) << std::setfill('=') << "=" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(60) << std::left << "1. One Adult"
        << std::setw(25) << std::right << "$20.00"
        << std::setw(20) << std::right << "$30.00" << std::endl;

    std::cout << std::setw(60) << std::left << "2. One Child (an adult may bring up to two children)"
        << std::setw(25) << std::right << "$12.00"
        << std::setw(20) << std::right << "$18.00" << std::endl;

    std::cout << std::setw(60) << std::left << "3. One Senior"
        << std::setw(25) << std::right << "$16.00"
        << std::setw(20) << std::right << "$24.00" << std::endl;

    std::cout << std::setw(60) << std::left << "4. Family Ticket (up to two adults or seniors, and three children)"
        << std::setw(20 - 1) << std::right << "$60.00"
        << std::setw(20) << std::right << "$90.00" << std::endl;

    std::cout << std::setw(60) << std::left << "5. Groups of six people or more, price per person"
        << std::setw(25) << std::right << "$15.00"
        << std::setw(20) << std::right << "$22.50" << std::endl;
    std::cout << std::setw(100) << std::setfill('_') << "_" << std::endl;
    std::cout << std::setfill(' ');
    // Display a separator line between tables
    std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(30) << std::left << "Extra Attraction"
        << std::setw(20) << std::right << "Cost per person" << std::endl;

    std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(30) << std::left << "1. Lion Feeding"
        << std::setw(20) << std::right << "$2.50" << std::endl;

    std::cout << std::setw(30) << std::left << "2. Penguin Feeding"
        << std::setw(20) << std::right << "$2.00" << std::endl;

    std::cout << std::setw(30) << std::left << "3. Evening BBQ (two-day tickets only)"
        << std::setw(20) << std::right << "$5.00" << std::endl;
    std::cout << std::setw(100) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
    cout << "\t\t\t\t*Tickets available for all 7 days of the week.*" << endl;
}

// Function to validate and get user input
template<typename T>
T getInput(const string& prompt) {
    T input;
    cout << prompt;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid option: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

// Function to calculate total cost for one or two days
double calculateTotalCost(const Ticket& ticket, const ExtraAttraction& attraction, int numTickets, int numPersons, bool twoDays) {
    double totalCost;
    if (twoDays) {
        totalCost = ticket.twoDaysPrice * numTickets;
    }
    else {
        totalCost = ticket.oneDayPrice * numTickets;
    }
    totalCost += attraction.costPerPerson * numPersons;
    return totalCost;
}

// Function to set text color
void setColor(int color) {
    cout << "\033[" << color << "m";
}

// Function to reset text color
void resetColor() {
    cout << "\033[0m";
}

int main() {
    vector<Ticket> tickets = {
        {"One Adult", 20.00, 30.00},
        {"One Child (an adult may bring up to two children)", 12.00, 18.00},
        {"One Senior", 16.00, 24.00},
        {"Family Ticket (up to two adults or seniors, and three children)", 60.00, 90.00},
        {"Groups of six people or more, price per person", 15.00, 22.50}
    };

    vector<ExtraAttraction> attractions = {
        {"Lion Feeding", 2.50},
        {"Penguin Feeding", 2.00},
        {"Evening BBQ (two-day tickets only)", 5.00}
    };

    char option;
    do {
        // Clear the screen
        system("cls");

        // Display main menu with color
        setColor(34); // Blue text color
        cout << "\nWelcome to Wildlife Park Booking System\n";
        resetColor();

        setColor(33); // Yellow text color
        cout << "1. Display Ticket Options and Extra Attractions\n";
        cout << "2. Book Tickets and Attractions\n";
        cout << "3. Exit\n";
        resetColor();

        setColor(31); // red text color
        cout << "Enter your choice (1-3): ";
        cin >> option;
        setColor(32);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
        case '1': {
            // Display ticket options and attractions
            displayTicketTable();
            setColor(31);
            cout << "Press Enter to continue...";
            resetColor();
            cin.ignore();
            cin.get(); // Wait for user to press Enter
            break;
        }
        case '2': {
            displayTicketTable();
            // Input tickets and attractions required
            setColor(31);
            int ticketIndex = getInput<int>("Enter the ticket option number: ");
            int attractionIndex = getInput<int>("Enter the extra attraction option number: ");
            int numTickets = getInput<int>("Enter the number of tickets required: ");
            int numPersons = getInput<int>("Enter the number of persons for the attraction: ");
            bool twoDays = (getInput<int>("Enter 1 for one day, 2 for two days: ") == 2);

            // Validate input indices
            if (ticketIndex < 1 || ticketIndex > static_cast<int>(tickets.size()) ||
                attractionIndex < 1 || attractionIndex > static_cast<int>(attractions.size()) ||
                numTickets <= 0 || numPersons <= 0) {
                cout << "Invalid input. Please try again.\n";
                break;
            }

            // Calculate total cost
            double totalCost = calculateTotalCost(tickets[ticketIndex - 1], attractions[attractionIndex - 1], numTickets, numPersons, twoDays);
            setColor(33);
            // Display booking details
            cout << "\nBooking Details:\n";
            cout << "Total Cost: $" << totalCost << endl;

            // Task 3 - Ensure best value
            if (totalCost > 100 && numTickets >= 2) {
                cout << "Consider purchasing a family ticket for better value!\n";
            }
            else if (totalCost > 50 && numTickets >= 4) {
                cout << "Consider purchasing a group ticket for better value!\n";
            }
            setColor(31);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get(); // Wait for user to press Enter
            resetColor();
            break;
        }
        case '3': {
            setColor(31); // Red text color
            cout << "Thank you for using the Wildlife Park Booking System. Goodbye!\n";
            resetColor();
            break;
        }
        default: {
            setColor(31);
            cout << "Invalid choice. Please enter a number from 1 to 3.\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get(); 
            resetColor();
            break;
        }
        }
    } while (option != '3');

    return 0;
}

