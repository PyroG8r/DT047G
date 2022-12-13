#include <iostream>
#include "email.h"
#include "Mailbox.h"

// Global function template that takes a reference to a const vector object and displays its contents
template <typename T>
void Show(const vector<T>& v)
{
    // Use an iterator to loop through the vector and print each element
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}


int main()
{
  // Create a MailBox object with 3 elements by default
  MailBox mailbox(3);

  // Add 5 Email messages to the MailBox
  mailbox.addEmail(Email("John Doe", "2022-12-07", "Test Email 1"));
  mailbox.addEmail(Email("Jane Smith", "2022-12-06", "Test Email 2"));
  mailbox.addEmail(Email("John Doe", "2022-12-05", "Test Email 3"));
  mailbox.addEmail(Email("Jane Smith", "2022-12-04", "Test Email 4"));
  mailbox.addEmail(Email("John Doe", "2022-12-03", "Test Email 5"));

  // Sort the MailBox by sender, date, and subject
  mailbox.SortWho();
  Show(mailbox.getEmails());
  mailbox.SortDate();
  Show(mailbox.getEmails());
  mailbox.SortSubject();
  Show(mailbox.getEmails());

  return 0;
}
