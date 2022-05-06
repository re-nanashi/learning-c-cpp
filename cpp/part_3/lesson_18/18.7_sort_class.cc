#include <iostream>
#include <list>
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
    string phone;
    string displayAs;

    ContactItem(const string &conName, const string &conNum)
    {
        name = conName;
        phone = conNum;
        displayAs = (name + ": " + phone);
    }

    // used by list::remove() given contact list item to compare so that it knows what to delete
    bool operator==(const ContactItem &itemToCompare) const
    {
        return (itemToCompare.name == this->name);
    }

    // used by list::sort() without parameters
    bool operator<(const ContactItem &itemToCompare) const
    {
        return (this->name < itemToCompare.name);
    }

    // used in displayAsContents via cout
    operator const char *() const
    {
        return displayAs.c_str();
    }
};

bool SortOnPhoneNumber(const ContactItem &item1, const ContactItem &item2)
{
    return (item1.phone < item2.phone);
}

int main()
{
    list<ContactItem> contacts;
    contacts.push_back(ContactItem("Jack Welsch", "+1 7889879879"));
    contacts.push_back(ContactItem("Bill Gates", "+1 97789787998"));
    contacts.push_back(ContactItem("Angi Merkel", "+49 234565466"));
    contacts.push_back(ContactItem("Vlad Putin", "+7 66454564797"));
    contacts.push_back(ContactItem("Ben Affleck", "+1 745641314"));
    contacts.push_back(ContactItem("Dan Craig", "+44"));

    cout << "List in initial order: " << endl;
    DisplayContents(contacts);

    contacts.sort();
    cout << "Sorting in alphabetical order via operator < :" << endl;
    DisplayContents(contacts);

    contacts.sort(SortOnPhoneNumber);
    cout << "Sorting in alphabetical order via list::sort(predicate) :" << endl;
    DisplayContents(contacts);

    cout << "Erasing Putin from the list: " << endl;
    contacts.remove(ContactItem("Vlad Putin", ""));
    DisplayContents(contacts);

    return 0;
}
