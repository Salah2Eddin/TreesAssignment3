#pragma once

#include <iostream>
#include <string>


static int StudentCount = 1;

class Student {
private:
    int id;
public:
    int getId() const;

private:
    std::string name;
    std::string department;
public:
    const std::string &getDepartment() const;

private:
    double gpa = 0;
public:
    Student() = default;
    Student(std::string name, std::string department, double gpa){
        this->id = StudentCount++;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }

    bool compareByID(const Student &other) const;

    bool compareByGpa(const Student &other) const;

    Student& operator=(const Student& otherStudent);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);
};

