#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
    double height;
};

bool read_person(Person& person)
{
    if (cin >> person.name >> person.age >> person.height) {
        return true;
    } else {
        return false;
    }
}

void write_person(const Person& person)
{
    cout << person.name << ' ' << person.age << ' ' << person.height << endl;
}

// tells whether a < b (not <= !!!)
bool compare_persons(const Person& a, const Person& b)
{
    if (a.age != b.age) {
        return a.age < b.age;
    }
    if (a.height != b.height) {
        return a.height < b.height;
    }
    return a.name < b.name;
}

int main()
{
    // reading
    vector<Person> persons;
    Person person;
    while (read_person(person)) {
        persons.push_back(person);
    }

    // sorting
    sort(persons.begin(), persons.end(), compare_persons);

    // writing
    for (Person p : persons) {
        write_person(p);
    }
}
