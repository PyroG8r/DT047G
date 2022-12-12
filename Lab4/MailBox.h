//
// Created by emilj on 2022-12-12.
//

#ifndef LAB4_MAILBOX_H
#define LAB4_MAILBOX_H


#include <vector>
#include <algorithm>
#include "Email.h"



class MailBox : public Email {
public:
    //constructor
    MailBox() = default;

    MailBox(int numElements);                   // Alternative: MailBox(int numElements, const Email& email = Email()) : emails(numElements, email) {}

    //function to add an email to the mailbox
    void AddEmail(const Email &email);

    // Access function that allows for reading and writing to the vector
    std::vector<Email> &GetEmails();

    // Sort the emails in the mailbox based on sender, date, and subject
    void SortWho();
    void SortDate();
    void SortSubject();

private:
    std::vector<Email> emails;
};


#endif //LAB4_MAILBOX_H
