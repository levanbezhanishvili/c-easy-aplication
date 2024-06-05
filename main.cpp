#include <iostream>
#include <string>
using namespace std;

class University {
private:
    static int studentCount;

public:
    static void incrementStudentCount() {
        studentCount++;
    }

    static int getStudentCount() {
        return studentCount;
    }
};

int University::studentCount = 0;

class Student {
protected:
    string name;
    int age;

public:
    Student(string name, int age) {
        this->name = name;
        this->age = age;
        University::incrementStudentCount(); 
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class informaticStudent : public Student {
private:
    string major;

public:
    informaticStudent(string name, int age, string major) : Student(name, age) {
        this->major = major;
    }

    void displayInfo() {
        cout << "CS Student Information:" << endl;
        Student::displayInfo();
        cout << "Major: " << major << endl;
    }
};

class INFORMATICStudent : public Student {
private:
    string major;

public:
    INFORMATICStudent(string name, int age, string major) : Student(name, age) {
        this->major = major;
    }

    void displayInfo() {
        cout << "informatic Student Information:" << endl;
        Student::displayInfo();
        cout << "Major: " << major << endl;
    }
};

class Course {
private:
    string name;
    int creditHours;

public:
    Course(string name, int creditHours) {
        this->name = name;
        this->creditHours = creditHours;
    }
};

int main() {
    Student* student1 = new informaticStudent("levan bezhanishvili", 19, "Computer Science");
    Student* student2 = new INFORMATICStudent("vighac bichi", 20, "Informatic");

    student1->displayInfo();
    cout << endl;
    student2->displayInfo();
    cout << endl;

    Course course("Informatic", 3);
    return 0;
}