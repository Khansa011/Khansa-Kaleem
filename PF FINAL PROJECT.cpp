#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

// 1. Flight Reservation System

struct Flight {
    int flightNumber;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;
    double fare;
};

struct Ticket {
    int ticketNumber;
    int flightNumber;
    string customerName;
    string status;
};

const int MAX_FLIGHTS = 10;
const int MAX_TICKETS = 20;
Flight flights[MAX_FLIGHTS];
Ticket tickets[MAX_TICKETS];
int flightCount = 0;
int ticketCount = 0;

// Display available flights
void displayFlights() {
    cout << "Available Flights:\n";
    cout << "Flight No. | Origin        | Destination   | Total Seats | Available Seats | Fare\n";
    for (int i = 0; i < flightCount; i++) {
        cout << setw(10) << flights[i].flightNumber << " | "
             << setw(12) << flights[i].origin << " | "
             << setw(12) << flights[i].destination << " | "
             << setw(11) << flights[i].totalSeats << " | "
             << setw(16) << flights[i].availableSeats << " | "
             << "$" << fixed << setprecision(2) << flights[i].fare << "\n";
    }
}

// Book a ticket
void bookTicket() {
    int flightNo;
    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Flight Number to book: ";
    cin >> flightNo;
    bool flightFound = false;
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNumber == flightNo) {
            flightFound = true;
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                Ticket ticket = {ticketCount + 1, flightNo, name, "Booked"};
                tickets[ticketCount] = ticket;
                ticketCount++;
                cout << "Booking successful! Ticket Number: " << ticket.ticketNumber << endl;
                break;
            } else {
                cout << "Sorry, no seats available on this flight.\n";
            }
        }
    }

    if (!flightFound) {
        cout << "Flight not found.\n";
    }
}

// Modify booking
void modifyBooking() {
    int ticketNo;
    cout << "Enter Ticket Number to modify: ";
    cin >> ticketNo;

    bool ticketFound = false;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketNumber == ticketNo && tickets[i].status == "Booked") {
            ticketFound = true;
            int newFlightNo;
            cout << "Enter new flight number: ";
            cin >> newFlightNo;

            bool flightFound = false;
            for (int j = 0; j < flightCount; j++) {
                if (flights[j].flightNumber == newFlightNo && flights[j].availableSeats > 0) {
                    for (int k = 0; k < flightCount; k++) {
                        if (flights[k].flightNumber == tickets[i].flightNumber) {
                            flights[k].availableSeats++;
                            break;
                        }
                    }

                    tickets[i].flightNumber = newFlightNo;
                    tickets[i].status = "Modified";
                    flights[j].availableSeats--;
                    cout << "Booking modified successfully! New Flight: " << newFlightNo << endl;
                    flightFound = true;
                    break;
                }
            }

            if (!flightFound) {
                cout << "No available seats on the new flight or flight not found.\n";
            }
            break;
        }
    }

    if (!ticketFound) {
        cout << "Ticket not found or already cancelled.\n";
    }
}

// Show ticket details
void showTicketDetails() {
    int ticketNo;
    cout << "Enter Ticket Number: ";
    cin >> ticketNo;

    bool ticketFound = false;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketNumber == ticketNo) {
            ticketFound = true;
            cout << "Ticket Details:\n";
            cout << "Ticket Number: " << tickets[i].ticketNumber << endl;
            cout << "Flight Number: " << tickets[i].flightNumber << endl;
            cout << "Customer Name: " << tickets[i].customerName << endl;
            cout << "Status: " << tickets[i].status << endl;
            break;
        }
    }

    if (!ticketFound) {
        cout << "Ticket not found.\n";
    }
}

// Cancel a ticket
void cancelTicket() {
    int ticketNo;
    cout << "Enter Ticket Number to cancel: ";
    cin >> ticketNo;

    bool ticketFound = false;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketNumber == ticketNo && tickets[i].status == "Booked") {
            ticketFound = true;
            for (int j = 0; j < flightCount; j++) {
                if (flights[j].flightNumber == tickets[i].flightNumber) {
                    flights[j].availableSeats++;
                    break;
                }
            }
            tickets[i].status = "Cancelled";
            cout << "Ticket cancelled successfully.\n";
            break;
        }
    }

    if (!ticketFound) {
        cout << "Ticket not found or already cancelled.\n";
    }
}

// 2. Employee Management System
struct Employee {
    int id;
    string name;
    string jobTitle;
    string qualifications;
    double performanceScore;
    double hoursWorked;
    int leaveDays;
};

const int maxEmployees = 5;
Employee employees[maxEmployees];
int employeeCount = 0;

// Add employee
void addEmployee() {
    if (employeeCount < maxEmployees) {
        Employee emp;
        cout << "Enter Employee ID: ";
        cin >> emp.id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, emp.name);
        cout << "Enter Job Title: ";
        getline(cin, emp.jobTitle);
        cout << "Enter Qualifications: ";
        getline(cin, emp.qualifications);
        emp.performanceScore = 0.0;
        emp.hoursWorked = 0.0;
        emp.leaveDays = 0;
        employees[employeeCount] = emp;
        employeeCount++;
    } else {
        cout << "Employee list is full!" << endl;
    }
}

// Update performance
void updatePerformance() {
    int id;
    cout << "Enter Employee ID to Update Performance: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cout << "Enter New Performance Score (0 to 10): ";
            cin >> employees[i].performanceScore;
            cout << "Performance updated for " << employees[i].name << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found!\n";
    }
}

// Update attendance
void updateAttendance() {
    int id;
    cout << "Enter Employee ID to Update Attendance: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            double hours;
            int leaves;
            cout << "Enter Hours Worked: ";
            cin >> hours;
            employees[i].hoursWorked += hours;
            cout << "Enter Leave Days Taken: ";
            cin >> leaves;
            employees[i].leaveDays += leaves;
            cout << "Attendance and leave updated for " << employees[i].name << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found!\n";
    }
}

// Display all employees
void displayEmployees() {
    if (employeeCount == 0) {
        cout << "No employees to display." << endl;
    } else {
        for (int i = 0; i < employeeCount; i++) {
            cout << "\nEmployee ID: " << employees[i].id << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Job Title: " << employees[i].jobTitle << endl;
            cout << "Qualifications: " << employees[i].qualifications << endl;
            cout << "Performance Score: " << employees[i].performanceScore << endl;
            cout << "Hours Worked: " << employees[i].hoursWorked << endl;
            cout << "Leave Days: " << employees[i].leaveDays << endl;
        }
    }
}

// 3. Customer Management System

struct Customer {
    string name;
    string email;
    int loyaltyPoints;
};

const int MAX_CUSTOMERS = 100;
Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

// Add customer
void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "Customer list is full!" << endl;
        return;
    }
    cout << "Enter customer name: ";
    cin >> customers[customerCount].name;
    cout << "Enter customer email: ";
    cin >> customers[customerCount].email;
    cout << "Enter customer Loyalty Points: ";
    cin >> customers[customerCount].loyaltyPoints;
    customerCount++;
    cout << "Customer added successfully." << endl;
}

// View customers
void viewCustomers() {
    if (customerCount == 0) {
        cout << "No customers to display." << endl;
        return;
    }
    for (int i = 0; i < customerCount; i++) {
        cout << "Name: " << customers[i].name << ", Email: " << customers[i].email << ", Loyalty Points: " << customers[i].loyaltyPoints << endl;
    }
}

// Update customer loyalty points
void updateCustomerLoyalty() {
    string email;
    cout << "Enter customer email to update: ";
    cin >> email;
    bool found = false;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].email == email) {
            int points;
            cout << "Enter points to add: ";
            cin >> points;
            customers[i].loyaltyPoints += points;
            cout << "Loyalty points updated." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer not found." << endl;
    }
}

// Delete customer
void deleteCustomer() {
    string email;
    cout << "Enter customer email to delete: ";
    cin >> email;
    bool found = false;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].email == email) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            cout << "Customer deleted." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer not found." << endl;
    }
}

// Main menu loop
int main() {
	system("color 68");
    // Initialize flights
    flights[flightCount++] = {101, "New York", "Los Angeles", 100, 100, 350.00};
    flights[flightCount++] = {102, "Chicago", "Miami", 50, 50, 220.00};
    flights[flightCount++] = {103, "San Francisco", "Seattle", 75, 75, 180.00};

    cout << setw(65) << "****************************************" << endl;
    cout << setw(62) << "WELCOME TO AIRLINE MANAGEMENT SYSTEM" << endl;
    cout << setw(65) << "*****************************************" << endl;
    
    system("color 64");
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Flight Reservation\n";
        cout << "2. Employee Management\n";
        cout << "3. Customer Management\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int flightChoice;
                do {
                    cout << "\nFlight Reservation and Ticketing System\n";
                    cout << "1. Display Available Flights\n";
                    cout << "2. Book a Ticket\n";
                    cout << "3. Cancel a Ticket\n";
                    cout << "4. Modify a Booking\n";
                    cout << "5. View Ticket Details\n";
                    cout << "6. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> flightChoice;
                    switch (flightChoice) {
                        case 1: displayFlights(); break;
                        case 2: bookTicket(); break;
                        case 3: cancelTicket(); break;
                        case 4: modifyBooking(); break;
                        case 5: showTicketDetails(); break;
                        case 6: cout << "Exiting the system. Thank you for using the flight reservation system.\n"; break;
                        default: cout << "Invalid choice! Please try again.\n"; break;
                    }
                } while (flightChoice != 6);
                break;
            }
            case 2: {
            	system("color 72");
                int employeeChoice;
                do {
                    cout << "\nEmployee Management Menu:\n";
                    cout << "1. Add Employee\n";
                    cout << "2. Update Performance\n";
                    cout << "3. Update Attendance\n";
                    cout << "4. Display All Employees\n";
                    cout << "5. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> employeeChoice;
                    switch (employeeChoice) {
                        case 1: addEmployee(); break;
                        case 2: updatePerformance(); break;
                        case 3: updateAttendance(); break;
                        case 4: displayEmployees(); break;
                        case 5: break;
                        default: cout << "Invalid choice.\n"; break;
                    }
                } while (employeeChoice != 5);
                break;
            }
            case 3: {
            	system("color 31");
                int customerChoice;
                do {
                    cout << "\nCustomer Management Menu:\n";
                    cout << "1. Add Customer\n";
                    cout << "2. View Customers\n";
                    cout << "3. Update Customer Loyalty\n";
                    cout << "4. Delete Customer\n";
                    cout << "5. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> customerChoice;
                    switch (customerChoice) {
                        case 1: addCustomer(); break;
                        case 2: viewCustomers(); break;
                        case 3: updateCustomerLoyalty(); break;
                        case 4: deleteCustomer(); break;
                        case 5: break;
                        default: cout << "Invalid choice.\n"; break;
                    }
                } while (customerChoice != 5);
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 4);
    return 0;
}
