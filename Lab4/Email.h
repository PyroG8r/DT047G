//
// Created by emilj on 2022-12-12.
//

#ifndef LAB4_EMAIL_H
#define LAB4_EMAIL_H

#include "iostream"
#include <string>

class Email {
public:
    // Default constructor that initializes the data members to default values
    Email() = default;
    // Constructor that initializes the data members to the values passed in
    Email(const std::string &who, const std::string &date, const std::string &subject) : who(who), date(date), subject(subject) {}

    //overloaded friend operator <<
    friend std::ostream &operator<<(std::ostream &os, const Email &email);

    // three friend function-like classes (structures): CompWhoDateSubject, CompDateWhoSubject, CompSubjectWheDate
    struct CompWhoDateSubject {
        bool operator()(const Email &lhs, const Email &rhs) const;
    };

    struct CompDateWhoSubject {
        bool operator()(const Email &lhs, const Email &rhs) const;
    };

    struct CompSubjectWheDate {
        bool operator()(const Email &lhs, const Email &rhs) const;
    };
    

private:
    std::string who;
    std::string date;
    std::string subject;
};


#endif //LAB4_EMAIL_H
