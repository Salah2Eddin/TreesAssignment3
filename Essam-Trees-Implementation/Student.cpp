#include "Student.h"

bool Student:: compareByID(const Student &other) const {
    return this->id < other.id;
}

bool Student:: compareByGpa(const Student &other) const {
    return this->gpa < other.gpa;
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

