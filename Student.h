#ifndef DATASTRUCTURES_STUDENT_H
#define DATASTRUCTURES_STUDENT_H

#include <iostream>

class Student {
private:
    int id;
    double gpa = 0;
    std::string name;
    std::string department;
public:
    Student() = default;

    Student(int id, std::string name, std::string department, double gpa);

    bool compareByID(const Student &other) const;
    bool compareByGpa(const Student &other) const;

    int getId() const;

    const std::string &getDepartment() const;

    Student& operator=(const Student& otherStudent);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);

    friend std::istream &operator>>(std::istream &in, Student &student);
};



#endif //DATASTRUCTURES_STUDENT_H
