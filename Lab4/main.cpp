#include <iostream>
#include "MailBox.h"


template <typename T>
void Show(const std::vector<T>& v ){
    // Use an iterator to loop through the vector and print each element
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << "\n";
    }
}

int main() {
    //MailBox mailbox(3);
    MailBox mailbox;

    // Create some emails
    mailbox.AddEmail(Email("John Doe", "2022-12-07", "Test Email 1"));
    mailbox.AddEmail(Email("Jane Smith", "2022-12-06", "Test Email 2"));
    mailbox.AddEmail(Email("John Doe", "2022-12-05", "Test Email 3"));
    mailbox.AddEmail(Email("Jane Smith", "2022-12-04", "Test Email 4"));
    mailbox.AddEmail(Email("John Doe", "2022-12-03", "Test Email 5"));

    // Sort the MailBox by sender, date, and subject
    std::cout << "---Sorting by sender:---\n";
    mailbox.SortWho();
    Show(mailbox.GetEmails());

    std::cout << "---Sorting by date:---\n";
    mailbox.SortDate();
    Show(mailbox.GetEmails());

    std::cout << "---Sorting by subject:---\n";
    mailbox.SortSubject();
    Show(mailbox.GetEmails());

    return 0;
}
