#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;
    int age;
public:
    Student() : name(nullptr), age(0) {}
    Student(const char* n, int a) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        age = a;
    }
    Student(const Student& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        age = obj.age;
        cout << "Copy constructor\n";
    }
    ~Student() {
        cout << "Destructor\n";
        delete[] name;
    }
    void Print() {
        cout << "Name: " << name << "\tAge: " << age << endl;
    }
};

int main() {
    Student a("Dima", 17);
    a.Print();
    Student b = a; // Вызов конструктора копирования
    b.Print();
    return 0;
}
