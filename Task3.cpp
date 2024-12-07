#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void storing_data(int age, string name);
void cake();

int main()
{
    string name;
    int age;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    storing_data(age, name);
    cake();
}

void storing_data(int age, string name)
{
    fstream file;
    file.open("Output1.txt", ios::out);
    file << name << " , " << age;
    file.close();
}

void cake()
{
    fstream file;
    file.open("Output1.txt", ios::in);
    string data;
    getline(file, data);
    file.close();

    int comma_position = data.find(',');
    // Me ne substring function use kiya he, taake string ka specific part le sakoon
    string name = data.substr(0, comma_position);
    string age_string = data.substr(comma_position + 1);

    int age = stoi(age_string);

    if (age % 2 == 0)
    {
        cout << "########################" << endl;
        cout << "## " << age << " HB " << name << "! " << age << " ##" << endl;
        cout << "########################" << endl;

        file.open("Output2.txt", ios::out);
        file << "########################" << endl;
        file << "## " << age << " HB " << name << "! " << age << " ##" << endl;
        file << "########################" << endl;
        file.close();
    }
    else
    {
        cout << "************************" << endl;
        cout << "** " << age << " HB " << name << "! " << age << " **" << endl;
        cout << "************************" << endl;

        file.open("Output2.txt", ios::out);
        file << "************************" << endl;
        file << "** " << age << " HB " << name << "! " << age << " **" << endl;
        file << "************************" << endl;
        file.close();
    }
}
