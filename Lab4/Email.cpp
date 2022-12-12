//
// Created by emilj on 2022-12-12.
//

#include "Email.h"


std::ostream &operator<<(std::ostream &os, const Email &email) {
    os << "From: " << email.who << "\n";
    os << "Date: " << email.date << "\n";
    os << "Subject: " << email.subject << "\n";
    return os;
}


bool Email::CompWhoDateSubject::operator()(const Email &lhs, const Email &rhs) const {
    if (lhs.who < rhs.who) {
        return true;
    } else if (lhs.who == rhs.who) {
        if (lhs.date < rhs.date) {
            return true;
        } else if (lhs.date == rhs.date) {
            return lhs.subject < rhs.subject;
        }
    }
    return false;
}

bool Email::CompDateWhoSubject::operator()(const Email &lhs, const Email &rhs) const {
    if (lhs.date < rhs.date) {
        return true;
    } else if (lhs.date == rhs.date) {
        if (lhs.who < rhs.who) {
            return true;
        } else if (lhs.who == rhs.who) {
            return lhs.subject < rhs.subject;
        }
    }
    return false;
}

bool Email::CompSubjectWheDate::operator()(const Email &lhs, const Email &rhs) const {
    if (lhs.subject < rhs.subject) {
        return true;
    } else if (lhs.subject == rhs.subject) {
        if (lhs.who < rhs.who) {
            return true;
        } else if (lhs.who == rhs.who) {
            return lhs.date < rhs.date;
        }
    }
    return false;
}
