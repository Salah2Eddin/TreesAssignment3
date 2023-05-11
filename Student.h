#pragma once

#include <iostream>
#include <string>


static int StudentCount = 1;

class Student {
private:
    int id;
    std::string name;
    std::string department;
    double gpa = 0;
public:
    Student(std::string name, std::string department, double gpa) :
            id(StudentCount++), name(std::move(name)), department(std::move(department)), gpa(gpa) {}

    bool compareByID(const Student &other) const {
        return this->id < other.id;
    }

    bool compareByGpa(const Student &other) const {
        return this->gpa < other.gpa;
    }

    friend std::ostream &operator<<(std::ostream &out, const Student &student);
};

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "[" << student.id << ", " << student.name << ", " << student.gpa << ", " << student.department << ']';
    return out;
}