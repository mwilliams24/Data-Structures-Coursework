#include <iostream>
using namespace std;

class Person {

private:
	string name;
	int age;
	string address

public:

	void setName(string n) {
		name = n
	}

	void setAge(int a) {
		age = a;
	}

	void setAddress(string add) {
		address = add;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	string getAddress() {
		return address;
	}

	Person() {
		age = 0;
		name = address = "";

	}

	Person(string n, int a, string add) {
		name = n;
		age = a
		address = add;

	}

	void displayInfo() {
		cout << getName() << " , " << getAge() << " , " << getAddress() << endl;
	}

	class Student : public Person
	{
	private:
		int ID;
		string school;
		float GPA;
		float grades[5];
	public:
		void setID(int id) {
			ID = id;
		}

		void setSchool(string s) {
			school = s;
		}

		void setGPA(float g) {
			GPA = g;
		}

		int getID() {
			return ID;
		}

		string getSchool() {
			return school;
		}

		float getGPA() {
			return GPA;
		}

		Student() {

			ID = 0;
			school = "";
			float = 0;
		}

		Student(string n, int a, string add, int id, string s, float g float pa[5]): //a student is a person; inheritance
		Person(n, a, add), ID(id), school(s), GPA(g)
		{ 
			for (int i = 0; i < 5; i++) {
				grades[i] = pa[i]
					cout << grades[i] << ".";
		   }

		}

		void displayStudentInfo{
			displayInfo();
			cout << " ,  " << getID() << " , " << getSchool() << " , " << getGPA() << " , " << endl:
		}

			void calculateGPA
};

}; // Inheritance: a class that inherits the attributes of another class

int main() {

	float grades[5] = [9.0, 3.5, 6.7, 8.8, 5.6];
	Student Albert("Albert", 23, "PV", 12345, "PVAMU", 3.5, grades);



}