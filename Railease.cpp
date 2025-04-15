#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ticket {
public:
   string passengerName;
   string trainName;
   int seatNumber;
   string source;
   string destination;
   string dateOfJourney;

   Ticket(string passengerName, string trainName, int seatNumber, string source, string destination, string dateOfJourney) {
       this->passengerName = passengerName;
       this->trainName = trainName;
       this->seatNumber = seatNumber;
       this->source = source;
       this->destination = destination;
       this->dateOfJourney = dateOfJourney;
   }

   void displayTicket() {
       cout << "\nTicket Details: " << endl;
       cout << "Passenger Name: " << passengerName << endl;
       cout << "Train Name: " << trainName << endl;
       cout << "Seat Number: " << seatNumber << endl;
       cout << "Source: " << source << endl;
       cout << "Destination: " << destination << endl;
       cout << "Date of Journey: " << dateOfJourney << endl;
   }
};

class RailwayBookingSystem {
private:
   vector<Ticket> tickets;
   vector<string> availableTrains;
   vector<string> stations;

public:
   RailwayBookingSystem() {
       availableTrains.push_back("Darjeeling Limited");
       availableTrains.push_back("Vande Bharat Express");
       availableTrains.push_back("Royal Rajasthan On Wheels");
       stations.push_back("New Delhi Junction");
       stations.push_back("Jaipur Station");
       stations.push_back("Darjeeling Railway Station");
       stations.push_back("Jammu Tawi Station");
   }

   void displayTrains() {
       cout << "Available Trains: " << endl;
       for (int i = 0; i < availableTrains.size(); i++) {
           cout << i + 1 << ". " << availableTrains[i] << endl;
       }
   }

   void displayStations() {
       cout << "Available Stations: " << endl;
       for (int i = 0; i < stations.size(); i++) {
           cout << i + 1 << ". " << stations[i] << endl;
       }
   }

   bool isValidStation(int station) {
       return station > 0 && station <= stations.size();
   }
   bool isValidTrain(int train) {
       return train > 0 && train <= availableTrains.size();
   }

   void bookTicket() {
       string passengerName, source, destination, dateOfJourney;
       int trainChoice, sourceStation, destinationStation, seatNumber;

       cin.ignore();

       cout << "\nEnter passenger name: ";
       getline(cin, passengerName);
       displayStations();
       cout << "\nSelect source station: ";
       cin >> sourceStation;

       if (!isValidStation(sourceStation)) {
           cout << "Invalid station choice!" << endl;
           return;
       }
       source = stations[sourceStation - 1];

       displayStations();
       cout << "\nSelect destination station: ";
       cin >> destinationStation;
       if (!isValidStation(destinationStation) || sourceStation == destinationStation) {
           cout << "Invalid destination choice!" << endl;
           return;
       }
       destination = stations[destinationStation - 1];
       displayTrains();
       cout << "\nSelect train: ";
       cin >> trainChoice;

       if (!isValidTrain(trainChoice)) {
           cout << "Invalid train choice!" << endl;
           return;
       }

       cout << "\nEnter date of journey (YYYY-MM-DD): ";
       cin >> dateOfJourney;

       cout << "\nEnter seat number: ";
       cin >> seatNumber;
       Ticket newTicket(passengerName, availableTrains[trainChoice - 1], seatNumber, source, destination, dateOfJourney);
       tickets.push_back(newTicket);
       cout << "\nTicket booked successfully!" << endl;
       newTicket.displayTicket();
   }
   void showAllTickets() {
       if (tickets.empty()) {
           cout << "\nNo tickets booked yet!" << endl;
       } else {
           for (int i = 0; i < tickets.size(); i++) {
               tickets[i].displayTicket();
           }
       }
   }
};
int main() {
       cout<<"🚂 Welcome To RailEase"<<endl;
   cout<<"Book Your Ticket with Ease!!"<<endl;
   RailwayBookingSystem system;
   int choice;
   do {
       cout << "\nRailway Ticket Booking System\n";
       cout << "1️⃣ Book a ticket\n";
       cout << "2️⃣ Show all booked tickets\n";
       cout << "3️⃣ Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;
       cin.ignore();
       switch (choice) {
           case 1:
               system.bookTicket();
               break;
           case 2:
               system.showAllTickets();
               break;
           case 3:
               cout << "👋 Exiting the system. Goodbye!" << endl;
               break;
           default:
               cout << "❌ Invalid choice! Please try again." << endl;
       }
   } while (choice != 3);
   return 0;
}
