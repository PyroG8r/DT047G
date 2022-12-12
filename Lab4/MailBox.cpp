//
// Created by emilj on 2022-12-12.
//


#include "MailBox.h"

MailBox::MailBox(int numElements) {
    //create an email object
    const Email& email = Email();

    //initialize the vector emails with numElements elements based on the email object
    emails = std::vector<Email>(numElements, email);
}

void MailBox::AddEmail(const Email &email) {
    emails.push_back(email);
}

std::vector<Email> &MailBox::GetEmails() { 
    return emails; 
}


void MailBox::SortWho() {
    std::sort(emails.begin(), emails.end(), CompWhoDateSubject());
}

void MailBox::SortDate() {
    std::sort(emails.begin(), emails.end(), CompDateWhoSubject());
}

void MailBox::SortSubject() {
    std::sort(emails.begin(), emails.end(), CompSubjectWheDate());
}

