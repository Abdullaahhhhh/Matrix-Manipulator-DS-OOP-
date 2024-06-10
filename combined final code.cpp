#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>


using namespace std;


class Teacher {
protected:
    string classes[3];
public:
    void enterClass(string classNum[], int subjectNum) {
        for (int i = 0; i < 3; i++) {
            cout << "Enter your class " << i + 1 << " with name: ";
            cin >> classNum[i];
        }

        int c;
        do {
            cout << "Enter the class number you want to select: ";
            cin >> c;
        } while (c <= 0 || c > 3);

        if (c >= 1 && c <= 3)
            cout << "You have selected class " << classNum[c - 1] << endl;
        else
            cout << "Invalid class selection." << endl;

        string subjects[5];

        cout << "Enter Number Of Subjects: ";
        cin >> subjectNum;

        for (int j = 0; j < subjectNum; j++) {
            cout << "Enter subject " << j + 1 << " name: ";
            cin >> subjects[j];
        }

        int a;
        for (int j = 0; j < subjectNum; j++) {
            cout << "Press " << j + 1 << " for " << subjects[j] << endl;
        }
        cin >> a;

        if (a >= 1 && a <= subjectNum) {
            cout << "You have chosen the subject " << subjects[a - 1] << endl;
        }
        else {
            cout << "Invalid subject selection." << endl;
        }
    }

    int students(string name[], int rollno[]) {
        int studentNum;

        cout << "How many students do you want to enter? ";
        cin >> studentNum;

        for (int i = 0; i < studentNum; i++) {
            cout << "Enter the name and roll number for student " << i + 1 << ": ";
            cin >> name[i] >> rollno[i];
        }

        int m;
        cout << "Which student do you want to enter the marks for? Press 1 for the first and so on: ";
        cin >> m;

        if (m >= 1 && m <= studentNum) {
            cout << "You are entering the marks for " << name[m - 1] << " with roll no " << rollno[m - 1] << endl;
        }
        else {
            cout << "Invalid student selection." << endl;
        }

        return studentNum;
    }

    void marking(int studentNum) {
        cout << "You are entering marks for lab assessment" << endl;

        int labMarks[studentNum];
        int finalMarks[studentNum];
        int midMarks[studentNum];
        int labMarksWeightage[studentNum];

        for (int i = 0; i < studentNum; i++)
            labMarksWeightage[i] = 0;

        int numLabReports;
        cout << "Enter the number of lab reports: ";
        cin >> numLabReports;

        // Input marks for each student and lab report
        for (int i = 0; i < studentNum; i++) {
            cout << "Enter lab marks for Student " << i + 1 << endl;
            for (int j = 0; j < numLabReports; j++) {
                cout << "Lab Report " << j + 1 << ": ";
                cin >> labMarks[j];
            }
        }

        for (int i = 0; i < studentNum; i++) {
            cout << "Enter marks for Mid of Student " << i + 1 << endl;
            cin >> midMarks[i];
        }

        for (int i = 0; i < studentNum; i++) {
            cout << "Enter marks for FINAL of Student " << i + 1 << endl;
            cin >> finalMarks[i];
        }

        for (int i = 0; i < studentNum; i++)
            for (int j = 0; j < studentNum; j++)
                labMarksWeightage[i] = labMarksWeightage[i] + labMarks[j];

        for (int i = 0; i < studentNum; i++)
            labMarksWeightage[i] = 0.15 * labMarksWeightage[i];

        for (int i = 0; i < studentNum; i++)
            cout << endl << "Lab Report Weightage For Student " << i + 1 << ": " << labMarksWeightage[i] << endl;

        // Calculate total marks for each student
        int totalMarks[studentNum];
        for (int i = 0; i < studentNum; i++) {
            totalMarks[i] = labMarksWeightage[i] + midMarks[i] + finalMarks[i];
        }

        // Display total marks for each student
        cout << "Total Marks:" << endl;
        for (int i = 0; i < studentNum; i++) {
            cout << "Student " << i + 1 << ": " << totalMarks[i] << endl;
        }
    }
    
// Calculate average marks and total marks for each student
//for (int i = 0; i < numStudents; i++) {
//int sum = 0;
//for (int j = 0; j < numLabReports; j++) {
//sum += marks[i][j];
//averages[i] = static_cast<double>(sum) / numLabReports;
//totals[i] = sum;
//MECHATRONICS OOPS UNIVERSITY MANAGEMENT SYSTEM

// Display average marks and total marks for each student
//cout << "Average Marks and Total Marks:" << endl;
//for (int i = 0; i < numStudents; i++) {
//cout << "Student " << i + 1 << ": Average=" << averages[i] << ", Total=" << totals[i] << endl;
//}


//void fileHandling()
//{
//	        // File handling to store class information
//        ofstream classFile("class_info.txt");
//       if (classFile.is_open()) {
//
//           for (int i = 0; i < 3; i++) {
//                classFile << classNum[i] << endl;
//            }
//            classFile.close();
//           cout << "Class information saved to class_info.txt" << endl;
//        }
//        else {
//           cout << "Unable to open the file." << endl;
//        }
//}
};



struct Route {
    int routeId;
    string departure;
    string arrival;
    string busNumber;
    string departureTime;
    int seatsAvailable;
};
const int MAX_ROUTES = 100;
Route routes[MAX_ROUTES];
int numRoutes = 0;
const int MAX_RESERVATIONS = 100;
int reservations[MAX_RESERVATIONS];
int numReservations = 0;
int lastReservation = -1;

void addRoute(int routeId, string departure, string arrival, string busNumber, string departureTime, int seatsAvailable) 
{
    if (numRoutes < MAX_ROUTES) {
        Route route;
        route.routeId = routeId;
        route.departure = departure;
        route.arrival = arrival;
        route.busNumber = busNumber;
        route.departureTime = departureTime;
        route.seatsAvailable = seatsAvailable;

        routes[numRoutes++] = route;
        cout << "Route added successfully " << endl;
    } else {
        cout << "Maximum number of routes reached " << endl;
    }
}
void showRoutes() {
    cout << "Available Routes:" << endl;
    for (int i = 0; i < numRoutes; i++) {
        cout << "Route ID: " << routes[i].routeId << endl;
        cout << "Departure: " << routes[i].departure << endl;
        cout << "Arrival: " << routes[i].arrival << endl;
        cout << "Departure Time: " << routes[i].departureTime << endl;
        cout << "Bus Number: " << routes[i].busNumber << endl;
        cout << "Seats Available: " << routes[i].seatsAvailable << endl;
        cout << endl;
    }
}

bool reserveSeat(int routeId) {
    for (int i = 0; i < numRoutes; i++) {
        if (routes[i].routeId == routeId) {
            if (routes[i].seatsAvailable > 0) {
                routes[i].seatsAvailable--;
                lastReservation = routeId;
                reservations[numReservations++] = routeId;
                cout << "Seat reserved successfully!" << endl;
                cout << "Route ID: " << routes[i].routeId << endl;
                cout << "Departure: " << routes[i].departure << endl;
                cout << "Arrival: " << routes[i].arrival << endl;
                cout << "Departure Time: " << routes[i].departureTime << endl;
                cout << "Bus Number: " << routes[i].busNumber << endl;
                return true;
            } else {
                cout << "No seats available for this route " << endl;
                return false;
            }
        }
    }
    cout << "Invalid Route ID." << endl;
    return false;
}

void showLastReservation() {
    if (lastReservation != -1) {
        cout << "Last Reservation Details:" << endl;
        for (int i = 0; i < numRoutes; i++) {
            if (routes[i].routeId == lastReservation) {
                cout << "Route ID: " << routes[i].routeId << endl;
                cout << "Departure: " << routes[i].departure << endl;
                cout << "Arrival: " << routes[i].arrival << endl;
                cout << "Departure Time: " << routes[i].departureTime << endl;
                cout << "Bus Number: " << routes[i].busNumber << endl;
                return;
            }
        }
    }
    cout << "No previous reservations." << endl;
}

void checkAvailableBuses() {
    cout << "Number of available buses: " << numRoutes << endl;
}

struct MenuItem {
    string name;
    double price;
};

class MenuOrderingSystem {
private:
    MenuItem menus[7][3];

public:
    // Constructor to initialize the menus
    MenuOrderingSystem() {
        menus[0][0] = {"Roll", 40};
        menus[0][1] = {"Fruit Chat", 200};
        menus[0][2] = {"Cake", 100};
        menus[1][0] = {"Shawarma", 170};
        menus[1][1] = {"Macaroni", 200};
        menus[1][2] = {"AppleJuice", 70};
        menus[2][0] = {"Zinger Shawarma", 200};
        menus[2][1] = {"Samosa", 40};
        menus[2][2] = {"Peach Juice", 70};
        menus[3][0] = {"Fries", 100};
        menus[3][1] = {"Pizza Slice", 200};
        menus[3][2] = {"Grapes Juice", 70};
        menus[4][0] = {"Lays", 60};
        menus[4][1] = {"Burger", 200};
        menus[4][2] = {"Tea", 60};
        menus[5][0] = {"Pasta", 100};
        menus[5][1] = {"Grilled Wrap", 300};
        menus[5][2] = {"Strawberry Milkshake", 200};
        menus[6][0] = {"Noodles", 70};
        menus[6][1] = {"Loaded Fries", 200};
        menus[6][2] = {"Slush", 100};
    }

    // Function to display the menu for a specific day
    void displayMenu(int day) {
        cout << "Menu for the day: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << menus[day][i].name << " - Rs " << menus[day][i].price << endl;
        }
        cout << endl;
    }

    // Function to calculate the total bill including 4% GST
    double calculateTotalBill(const MenuItem order[], int size) {
        double total = 0.0;
        for (int i = 0; i < size; i++) {
            total += order[i].price;
        }
        double gst = total * 0.04;
        total += gst;
        return total;
    }

    // Function to start the ordering process
    void startOrdering() {
        // Get current day of the week
        time_t now = time(NULL);
        tm* currentDate = localtime(&now);
        int currentDay = currentDate->tm_wday;

        // Get the menu for the current day
        MenuItem* currentMenu = menus[currentDay];
        int menuSize = 3;

        MenuItem order[menuSize];
        int orderSize = 0;
        string choice;

        // Display the menu for the current day
        displayMenu(currentDay);

        do {
            cout << "Choose an item number to add to your order (or enter 'Bill' to show the bill): ";
            cin >> choice;

            if (choice == "Bill") {
                break;
            } else {
                int itemIndex;
                istringstream iss(choice);
                if (iss >> itemIndex && itemIndex >= 1 && itemIndex <= menuSize) {
                    order[orderSize++] = currentMenu[itemIndex - 1];
                    cout << "Item added to your order." << endl;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        } while (true);

        cout << endl;
        // Calculate and display the total bill
        double totalBill = calculateTotalBill(order, orderSize);
        cout << "Your Order :" << endl;
        for (int i = 0; i < orderSize; i++) {
            cout << order[i].name << " - Rs " << order[i].price << endl;
        }
        cout << "Total Price: Rs " << totalBill << endl;
    }
};


int main() {
int choice;

cout << endl ;
 addRoute(1, "University", "Murree Road", "BUS001", "17:30", 10);
    addRoute(2, "University", "Islamabad Sectors", "BUS002", "16:300", 5);
    addRoute(3, "University", "Rawalpindi Cantt", "BUS003", "17:00", 3);

do {
    cout << "Welcome to the university Management System" << endl;
    cout << "1. Transportation System" << endl;
    cout << "2. Menu Ordering System" << endl;
    cout << "3. Teachers portal" << endl;
     cout << "4. For showing details about project makers"  << endl;
     cout << "5. For exiting" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
cout << endl ;
    switch (choice) {
        case 1: {
            int option;
            do {
                cout << "Transportation System" << endl;
                cout << "1. Add Route" << endl;
                cout << "2. Display Routes" << endl;
                cout << "3. Make Reservation" << endl;
                cout << "4. Display Reservations" << endl;
                cout << "5. Go Back" << endl;
                cout << "Enter your option: ";
                cin >> option;
cout << endl ;
                switch (option) {
                    case 1: {
                        if (numRoutes == MAX_ROUTES) {
                            cout << "Maximum number of routes reached." << endl;
                        } else {
                            Route newRoute;
                            newRoute.routeId = numRoutes + 1;
                            cout << "Enter Departure: ";
                            cin >> newRoute.departure;
                            cout << "Enter Arrival: ";
                            cin >> newRoute.arrival;
                            cout << "Enter Bus Number: ";
                            cin >> newRoute.busNumber;
                            cout << "Enter Departure Time: ";
                            cin >> newRoute.departureTime;
                            cout << "Enter Seats Available: ";
                            cin >> newRoute.seatsAvailable;

                            routes[numRoutes] = newRoute;
                            numRoutes++;

                            cout << "Route added successfully." << endl;
                        }
                        break;
                    }
                    cout << endl ;
                    case 2: {
                        if (numRoutes == 0) {
                            cout << "No routes available." << endl;
                        } else {
                            cout << "Routes:" << endl;
                            for (int i = 0; i < numRoutes; i++) {
                                cout << "Route ID: " << routes[i].routeId << endl;
                                cout << "Departure: " << routes[i].departure << endl;
                                cout << "Arrival: " << routes[i].arrival << endl;
                                cout << "Bus Number: " << routes[i].busNumber << endl;
                                cout << "Departure Time: " << routes[i].departureTime << endl;
                                cout << "Seats Available: " << routes[i].seatsAvailable << endl;
                                cout << endl;
                            }
                        }
                        break;
                    }
                    cout << endl ;
                    case 3: {
                        if (numRoutes == 0) {
                            cout << "No routes available for reservation." << endl;
                        } else {
                            int routeId;
                            cout << "Enter Route ID: ";
                            cin >> routeId;

                            int index = -1;
                            for (int i = 0; i < numRoutes; i++) {
                                if (routes[i].routeId == routeId) {
                                    index = i;
                                    break;
                                }
                            }

                            if (index == -1) {
                                cout << "Invalid Route ID." << endl;
                            } else if (routes[index].seatsAvailable == 0) {
                                cout << "No seats available for this route." << endl;
                            } else {
                                lastReservation++;
                                reservations[lastReservation] = routeId;
                                routes[index].seatsAvailable--;

                                cout << "Reservation successful." << endl;
                            }
                        }
                        break;
                    }
                    cout << endl ;
                    case 4: {
                        if (lastReservation == 0) {
                            cout << "No reservations made." << endl;
                        } else {
                            cout << "Reservations:" << endl;
                            for (int i = 1; i <= lastReservation; i++) {
                                int routeId = reservations[i];
                                int index = -1;
                                for (int j = 0; j < numRoutes; j++) {
                                    if (routes[j].routeId == routeId) {
                                        index = j;
                                        break;
									}
                                }
                                cout << "Reservation ID: " << i << endl;
                                cout << "Route ID: " << routes[index].routeId << endl;
                                cout << "Departure: " << routes[index].departure << endl;
                                cout << "Arrival: " << routes[index].arrival << endl;
                                cout << "Bus Number: " << routes[index].busNumber << endl;
                                cout << "Departure Time: " << routes[index].departureTime << endl;
                                cout << "Seats Available: " << routes[index].seatsAvailable << endl;
                                cout << endl;
                            }
                        }
                        break;
                    }
                    cout << endl ;
                    case 5: 
					{
                    	cout << "Exiting..." << endl;
                cout << endl ;
                        break;
                    }
                    default: {
                        cout << "Invalid option. Please try again." << endl;
                    }
                }
            } while (option != 5);

            break;
        }
        cout << endl ;
        case 2: {
           MenuOrderingSystem menu;
    menu.startOrdering();

            break;
        }
        cout << endl ;
        case 3: {
            Teacher t;
    string classNum[3];
    int subjectNum;
    int studentNum;
    string name[5]; // Assuming a maximum of 5 students
    int rollno[5]; // Assuming a maximum of 5 students
    t.enterClass(classNum, subjectNum);
    studentNum = t.students(name, rollno);
    t.marking(studentNum);

            break;
        }
         case 4: {
            cout << "This project was made by : " << endl << "Eihaab 221751 "<<endl<<"Abdullah 221748"<<endl<<"Eden 221658"<<endl<<"Presented To Very Dedicated MAAM MARIAM SABIR" << endl;
            break;
        }
         case 5: {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
} while (choice != 4);
cout << endl ;
 

return 0;
}

