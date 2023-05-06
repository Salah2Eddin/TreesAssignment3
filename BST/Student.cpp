#include "Student.h"

#include <utility>

Student::Student(int id, std::string name, std::string department, double gpa) :
                id(id), name(std::move(name)), department(std::move(department)), gpa(gpa) {}

bool Student::compareByID(const Student &other) const {
    return this->id < other.id;
}


std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "[" << student.id << ", " << student.name << ", " << student.gpa << ", " << student.department << ']';
    return out;
}

int Student::getId() const {
    return id;
}

Student &Student::operator=(const Student &otherStudent) {
    if(this->getId() != otherStudent.getId()){
        this->id = otherStudent.id;
        this->gpa = otherStudent.gpa;
        this->department = std::move(otherStudent.department);
        this->name = std::move(otherStudent.name);
    }
    return *this;
}

const std::string &Student::getDepartment() const {
    return department;
}

std::istream &operator>>(std::istream &in, Student &student) {
    std::cout << "Enter student ID:\n";
    in >> student.id;
    std::cout << "Enter student name:\n";
    in >> student.name;
    std::cout << "Enter student GPA:\n";
    in >> student.gpa;
    std::cout << "Enter student department:\n";
    in >> student.department;
    for (char & c : student.department) {
        c = toupper(c);
    }
    return in;
}

