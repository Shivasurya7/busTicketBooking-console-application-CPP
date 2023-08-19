#include <bits/stdc++.h>
using namespace std;

class customer {
    private:
        int CustomerId;
        string CustomerName;
        string Password;
        int Age;
        char Gender;

    public:
        customer(int id, string customerName,string password, int age, char gender) {
            CustomerId = id;
            CustomerName = customerName;
            Password = password;
            Age = age;
            Gender = gender;
        }

        int getCustomerId() const {
            return CustomerId;
        }

        void setCustomerId(int customerId) {
            CustomerId = customerId;
        }

        string getCustomerName() {
            return CustomerName;
        }

        void setCustomerName(string customerName) {
            CustomerName = customerName;
        }

        string getPassword() {
            return Password;
        }

        void setPassword(string password) {
            Password = password;
        }

        char getGender() {
            return Gender;
        }

        void setGender(char gender) {
            Gender = gender;
        }

        int getAge() {
            return Age;
        }

        void setAge(int age) {
            Age = age;
        }
};

class Bus {
    private:
        string busType;
        string seatType;
        int bookedSeat;
        string seat[4][3];

    public:
        Bus(string busType, string seatType) {
            this->busType = busType;
            this->seatType = seatType;
            this->bookedSeat = 0;

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    seat[i][j] = " ";
                }
            }
        }

        string isCanBook(int n,string c) {
            n--;
            if (seat[n/3][n%3] == " ") {
                if (n <= 2) {
                    if (seat[(n/3)+1][n%3] == " " || seat[(n/3)+1][n%3] == c) {
                        seat[n/3][n%3] = c;
                        return "yes";
                    } else {
                        if (c == "F") {
                            return "Cannot book seat....Please choose female seat neighbour";
                        } else {
                            return "Cannot book seat....Please choose male seat neighbour";
                        }
                    }
                } else if (n <= 5) {
                    if (seat[(n/3)-1][n%3] == " " || seat[(n/3)-1][n%3] == c) {
                        seat[n/3][n%3] = c;
                        return "yes";
                    } else {
                        if (c == "F") {
                            return "Cannot book seat....Please choose female seat neighbour";
                        } else {
                            return "Cannot book seat....Please choose male seat neighbour";
                        }
                    }
                } else if (n <= 8) {
                    if (seat[(n/3)+1][n%3] == " " || seat[(n/3)+1][n%3] == c) {
                        seat[n/3][n%3] = c;
                        return "yes";
                    } else {
                        if (c == "F") {
                            return "Cannot book seat....Please choose female seat neighbour";
                        } else {
                            return "Cannot book seat....Please choose male seat neighbour";
                        }
                    }
                } else if (n <= 11) {
                    if (seat[(n/3)-1][n%3] == " " || seat[(n/3)-1][n%3] == c) {
                        seat[n/3][n%3] = c;
                        return "yes";
                    } else {
                        if (c == "F") {
                            return "Cannot book seat....Please choose female seat neighbour";
                        } else {
                            return "Cannot book seat....Please choose male seat neighbour";
                        }
                    }
                }
            } else {
                return "Ticket is Already Booked";
            }
            return "Invalid Ticket Number";
        }

        void displaySeat() {
            cout << "*->Driver\n";
            cout << "*  ";
            int s = 1;
            for (int i = 0; i < 4; i++) {
                if (i != 0) {
                    cout << "   ";
                }
                if (s == 7) {
                    cout << "-------->\n";
                    cout << "   ";
                }
                for (int j = 0; j < 3; j++) {
                    if (seat[i][j] == " ") {
                        cout << s << "  ";
                    } else {
                        cout << seat[i][j] << "  ";
                    }
                    s++;
                }
                cout << '\n';
            }
        }

        void display() const {
            cout << "Bus type : " << busType << '\n';
            cout << "Seat type : " << seatType << '\n';
            cout << "Booked seats : " << bookedSeat << '\n';
        }

        string getBusType() {
            return busType;
        }

        void setBusType(string busType) {
            this->busType = busType;
        }

        string getSeatType() {
            return seatType;
        }

        void setSeatType(string seatType) {
            this->seatType = seatType;
        }

        int getBookedSeat() const {
            return bookedSeat;
        }

        void setBookedSeat(int bookedSeat) {
            this->bookedSeat += bookedSeat;
        }

        void delBookedSeat(int bookedSeat) {
            this->bookedSeat -= bookedSeat;
        }
};

class Ticket {
    private:
        int cusId;
        string busType;
        string seatType;
        int NoOfTickets;
        vector<int> bookedSeats;
        int ticketId;
        int price;

    public:
        static int ticketNo;
        Ticket(string bt, string st, int nt, vector<int> a, int c) {
            ticketId = ticketNo;
            cusId = c;
            busType = bt;
            seatType = st;
            NoOfTickets = nt;
            price = nt * setPrice(bt, st);
            bookedSeats = a;
            ticketNo++;
        }

        int setPrice(string bt, string st) {
            if (bt == "AC") {
                if (st == "seater") {
                    return 500;
                } else {
                    return 600;
                }
            } else {
                if (st == "seater") {
                    return 200;
                } else {
                    return 400;
                }
            }
        }

        int getPrice() {
            return price;
        }

        void setPrice(int price) {
            this->price = price;
        }

        vector<int> getBookedSeats() {
            return bookedSeats;
        }

        void setBookedSeats(vector<int> bookedSeats) {
            this->bookedSeats = bookedSeats;
        }

        string getBusType() {
            return busType;
        }

        void setBusType(string busType) {
            this->busType = busType;
        }

        string getSeatType() {
            return seatType;
        }

        void setSeatType(string seatType) {
            this->seatType = seatType;
        }

        int getNoOfTickets() {
            return NoOfTickets;
        }

        void setNoOfTickets(int noOfTickets) {
            NoOfTickets = noOfTickets;
        }

        int getTicketId() {
            return ticketId;
        }

        void setTicketId(int ticketId) {
            this->ticketId = ticketId;
        }

        int getCusId() {
            return cusId;
        }

        void setCusId(int cusId) {
            this->cusId = cusId;
        }
};

int Ticket::ticketNo = 0;

class BusData {
    private:
        vector<Bus> b;
        vector<Ticket> tickets;

    public:
        BusData() {
            Bus b1("AC", "seater");
            Bus b2("AC", "sleaper");
            Bus b3("NON-AC", "seater");
            Bus b4("NON-AC", "sleaper");
            b.push_back(b1);
            b.push_back(b2);
            b.push_back(b3);
            b.push_back(b4);
        }

        void bookTickets(customer cus) {
            string bustype;
            string seattype;
            cout << "Enter bustype, seattype: ";
            cin >> bustype >> seattype;

            for (int i = 0; i < (int)b.size(); i++) {
                if (b[i].getBusType() == bustype && b[i].getSeatType() == seattype) {
                    int noOfTicket;
                    cout << "Enter the number of tickets you want to book: ";
                    cin >> noOfTicket;

                    int f = 0;
                    vector<int> bt;
                    while (f != noOfTicket) {
                        int ticketNo;
                        string gender;

                        cout << "Enter the seat number to be booked: ";
                        cin >> ticketNo;
                        cout << "Enter gender (M or F): ";
                        cin >> gender;

                        string result = b[i].isCanBook(ticketNo, gender);
                        if (result == "yes") {
                            bt.push_back(ticketNo);
                            f++;
                        } else {
                            cout << result <<endl;
                        }
                    }

                    b[i].setBookedSeat(noOfTicket);
                    Ticket t(bustype, seattype, noOfTicket, bt, cus.getCustomerId());
                    tickets.push_back(t);

                    cout << "-------------------------------" << endl;
                    cout << "Your Ticket id is: " << t.getTicketId() << endl;
                    cout << "You have to pay Rs." << t.getPrice() << endl;
                    cout << "Your Tickets were booked" << endl;
                    cout << "!!!!Happy Journey!!!!" << endl;
                    cout << "-------------------------------" << endl;
                    break;
                }
            }
        }

        void viewTicket() {
            string bt;
            string st;
            cout << "Enter bustype, seattype: ";
            cin >> bt >> st;

            for (int i = 0; i < (int)b.size(); i++) {
                if (b[i].getBusType() == bt && b[i].getSeatType() == st) {
                    b[i].displaySeat();
                    break;
                }
            }
        }

        void cancelTickets() {
            int id;
            cout << "Enter booking id: ";
            cin >> id;

            for (int i = 0; i < (int)tickets.size(); i++) {
                if (tickets[i].getTicketId() == id) {
                    cout << "-----------------------" << endl;
                    cout << "Ticket details are: " << endl;
                    cout << "Bus type: " << tickets[i].getBusType() << endl;
                    cout << "Seat type: " << tickets[i].getSeatType() << endl;
                    cout << "Booked by the customer id: " << tickets[i].getCusId() << endl;
                    cout << "No. of tickets: " << tickets[i].getNoOfTickets() << endl;
                    cout << "Booked seats: ";
                    cout<<"[";
                    for (int j = 0; j < (int)tickets[i].getBookedSeats().size(); j++) {
                        if(j != 0){
                            cout<<",";
                        }
                        cout << tickets[i].getBookedSeats()[j];
                    }
                    cout<<"]";
                    cout << endl << "-----------------------" << endl;
                    cout << "Your ticket has been deleted successfully!!!" << endl
                              << "Your amount " << tickets[i].getPrice() << " will return back soon..." << endl
                              << "Thank you" << endl;

                    for (int j = 0; j < (int)b.size(); j++) {
                        if (b[j].getBusType() == tickets[i].getBusType() && b[j].getSeatType() == tickets[i].getSeatType()) {
                            b[j].delBookedSeat(tickets[i].getNoOfTickets());
                        }
                    }

                    tickets.erase(tickets.begin() + i);
                    break;
                }
            }
        }

        void summary() {
            cout << "Bus summary:" << endl;
            cout << "------------------------" << endl;
            for (int i = 0; i < (int)b.size(); i++) {
                b[i].display();
                cout << "------------------------" << endl;
            }
        }
};

bool validateId(const vector<customer> customers, int id) {
    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i].getCustomerId() == id) {
            return true;
        }
    }
    return false;
}

int logIn(vector<customer> customers) {
    int id;
    string password;

    cout << "Enter Customer id: ";
    cin >> id;
    cout << "Enter Password to Login: ";
    cin >> password;

    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i].getCustomerId() == id) {
            if (customers[i].getPassword() == password) {
                return i;
            } else {
                return -1;
            }
        }
    }
    return -1;
}

void signUp(vector<customer>& customers) {
    int id;
    string name;
    string password;
    int age;
    char gender;

    cout << "Enter Customer id: ";
    cin >> id;
    cout << "Enter Customer name: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;

    if (validateId(customers, id)) {
        cout << "User id exists...\nTry a new user id.\n";
    } else {
        customer cus(id, name, password, age, gender);
        customers.push_back(cus);
    }
}

int main() {
    vector<customer> customer;
    BusData bus;
    int n, f = 0;
    while (true) {
        cout << "1)Sign up\n"
                  << "2)Login\n"
                  << "3)Exit\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch (n) {
            case 1:
                signUp(customer);
                break;
            case 2:
                int s;
                s = logIn(customer);
                if (s != -1) {
                    cout << "login successful.....\n";
                    cout << "welcome " << customer[s].getCustomerName() << "\n";
                    int f2 = 0;
                    while (true) {
                        cout << "\n1)BookTickets\n"
                                  << "2)ViewTickets\n"
                                  << "3)CancelTickets\n"
                                  << "4)Summary\n"
                                  << "5)Logout\n";
                        cout << "Enter your choice: ";
                        cin >> n;

                        switch (n) {
                            case 1:
                                bus.bookTickets(customer[s]);
                                break;
                            case 2:
                                bus.viewTicket();
                                break;
                            case 3:
                                bus.cancelTickets();
                                break;
                            case 4:
                                bus.summary();
                                break;
                            case 5:
                                cout << "logout successful.....\n";
                                f2 = 1;
                                break;
                        }
                        if (f2 == 1) {
                            break;
                        }
                    }
                } else {
                    cout << "User id or Password is invalid\n try again\n";
                }
                break;
            case 3:
                f = 1;
                break;
        }
        if (f == 1) {
            break;
        }
    }
    return 0;
}
