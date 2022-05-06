#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T> void DisplayContents(const T &container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        cout << *element << endl;
    cout << endl;
}

struct ContactItem
{
    string name;
    string phoneNum;
    string displayaAs;

    ContactItem(const string &nameInit, const string &phone)
    {
        name = nameInit;
        phoneNum = phone;
        displayaAs = (name + ": " + phoneNum);
    }

    bool operator==(const ContactItem &itemToCompare) const
    {
        return (itemToCompare.name == this->name);
    }

    bool operator<(const ContactItem &itemToCompare) const
    {
        return (this->name < itemToCompare.name);
    }

    operator const char *() const
    {
        return displayaAs.c_str();
    }
};

int main()
{
    set<ContactItem> setContacts;
    setContacts.insert(ContactItem("Jack Welsch", "+1 7889 879 879"));
    setContacts.insert(ContactItem("Bill Gates", "+1 97 7897 8799 8"));
    setContacts.insert(ContactItem("Angi Merkel", "+49 23456 5466"));
    setContacts.insert(ContactItem("Vlad Putin", "+7 6645 4564 797"));
    setContacts.insert(ContactItem("John Travolta", "91 234 4564 789"));
    setContacts.insert(ContactItem("Ben Affleck", "+1 745 641 314"));
    DisplayContents(setContacts);

    cout << "Enter a name you wish to delete: ";
    string inputName;
    getline(cin, inputName);

    auto contactFound = setContacts.find(ContactItem(inputName, ""));
    if (contactFound != setContacts.end())
    {
        setContacts.erase(contactFound);
        cout << "Displaying contents after erasing " << inputName << endl;
        DisplayContents(setContacts);
    }
    else
        cout << "Contact not found" << endl;

    return 0;
}
