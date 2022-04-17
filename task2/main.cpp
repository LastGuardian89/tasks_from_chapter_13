#include <iostream>
using namespace std;
#include "classic.h"
void Bravo(const Cd & disk);
int main()
{
    cout << "Object of the Cd class:\nEnter the performers: ";
    char str1[20];
    cin >> str1;
    cout << "Enter the label: ";
    char str2[20];
    cin >> str2;
    Cd c1(str1, str2, 14, 35.5);

    cout << "\nObject of the Classic class:\nEnter the main song name: ";
    char str[20];
    cin >> str;
    cout << "Enter the performers: ";
    cin >> str1;
    cout << "Enter the label: ";
    cin >> str2;
    Classic c2 = Classic(str,
                         str1, str2, 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    system("pause");
    return 0;
}
void Bravo(const Cd & disk)
{
    disk.Report();
}
