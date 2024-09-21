#include <iostream>
using namespace std;

class Vehicle {

private:
    int ID;
    string make;
    float price;
    int model;

public:

    void setID(int id) {
        ID = id;
    }

    void setMake(string m) {
        make = m;
    }

    void setPrice(float p) {
        price = p;
    }

    void setModel(int mo) {
        model = mo;
    }

    int getID() {
        return ID;
    }

    string getMake() {
        return make;
    }
    float getPrice() {
        return price;
    }

    int getModel() {
        return model;
    }


    Vehicle() {
        ID = model = 0;
        make = "";
        price = 0;

    }

    Vehicle(int id, string m, float p, int mo) {
        ID = id;
        make = m;
        price = p;
        model = mo;
    }

    void displayInfo() {
        cout << "Car ID: " << getID() << endl;
        cout << "Car's make: " << getMake() << endl;
        cout << "Car's price: " << getPrice() << endl;
        cout << "Car's model: " << getModel() << endl;
    }
};
class Bus : public Vehicle {
private:
    string ISD;
    int capacity;

public:
    void setISD(string isd) {
        ISD = isd;
    }

    void setCapacity(int c) {
        capacity = c;
    }

    string getISD() {
        return ISD;
    }

    int getCapacity() {
        return capacity;
    }



    Bus() {

        ISD = "";
        capacity = 0;
    }

    Bus(int ID, string make, float price, int model, string ISD, int capacity) : Vehicle(ID, make, price, model)
    {


    }



    void displayBusInfo() {
        displayInfo();
        cout << " ,  " << getISD() << " , " << getCapacity() << endl;
    }

};

class Car : public Vehicle {
private:
    string owner;
    string color;
    float mileage;

public:
    void setOwner(string o) {
        owner = o;
    }
    void setColor(string co) {
        color = co;
    }
    void setMileage(float mi) {
        mileage = mi;
    }

    string getOwner() {
        return owner;
    }

    string getColor() {
        return color;
    }

    float getMileage() {
        return mileage;
    }

    Car() {
        owner = color = "";
        mileage = 0;

    }

    Car(int ID, string make, float price, int model, string
        owner, string color, float mileage) : Vehicle(ID, make,
            price, model) {

    }

    void displayCarInfo() {
        displayInfo();
        cout << " ,  " << getOwner() << " , " << getColor() << " , " << getMileage() << endl;
    }


}; // Inheritance: a class that inherits the attributes of another class

void searchBusByModel(Bus BusList[], int e, int model) {

    for (int i = 0; i < e; ++i) {
        if (BusList[i].getModel() == model) {
            cout << "Bus found with model " << model << ":" << endl;
            BusList[i].displayInfo();
        }
        cout << "No bus found with model " << model << endl;

    }
}

void searchCarByMileage(Car CarList[], int e, float mileage) {

    for (int i = 0; i < e; ++i) {
        if (CarList[i].getMileage() == mileage) {
            cout << "Car found with " << mileage << "mileage" << endl;
            CarList[i].displayInfo();
        }
        cout << "No car found with " << mileage << " mileage." << " mileage." << endl;
    }

}

int main()
{
    const int size = 5;
    Bus BusList[size];
    Car CarList[size];

    cout << "Enter info for 5 buses: " << endl;
    for (int i = 0; i < size; i++) {
        int ID, model, capacity;
        string make, ISD;
        float price;

        cout << "Bus " << i + 1 << " ID: " << endl;
        cin >> ID;
        cout << "Bus " << i + 1 << " make: " << endl;
        cin >> make;
        cout << "Bus " << i + 1 << " price: " << endl;
        cin >> price;
        cout << "Bus " << i + 1 << " model: " << endl;
        cin >> model;
        cout << "Bus " << i + 1 << " ISD: " << endl;
        cin >> ISD;

        cout << "Bus " << i + 1 << " capacity: " << endl;
        cin >> capacity;



        BusList[i] = Bus(ID, make, price, model, ISD, capacity);

    }


    cout << "Enter info for 5 cars: " << endl;
    for (int i = 0; i < size; i++) {
        int ID, model;
        string make, owner, color;
        float price, mileage;

        cout << "Car " << i + 1 << " ID: " << endl;
        cin >> ID;
        cout << "Bus " << i + 1 << " make: " << endl;
        cin >> make;
        cout << "Car " << i + 1 << " price: " << endl;
        cin >> price;
        cout << "Car " << i + 1 << " model: " << endl;
        cin >> model;
        cout << "Car " << i + 1 << " owner: " << endl;
        cin >> owner;
        cout << "Car " << i + 1 << " color: " << endl;
        cin >> color;
        cout << "Car " << i + 1 << " mileage: " << endl;
        cin >> mileage;


        CarList[i] = Car(ID, make, price, model, owner, color, mileage);
    }

    int busModel;
    cout << "Enter the bus model: " << endl;
    cin >> busModel;
    searchBusByModel(BusList, size, busModel);

    float carMileage;
    cout << "Enter the car mileage: " << endl;
    cin >> carMileage;
    searchCarByMileage(CarList, size, carMileage);

    return 0;

}