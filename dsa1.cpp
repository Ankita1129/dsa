#include <iostream>
using namespace std;
struct student // creating structure
{
    int roll_no; // data-members
    string name; // data-members
    float sgpa;  // data-members
};
// for swapping
void swap(student a[], int index1, int index2)
{
    // swapping SGPA
    int temp = 0;
    temp = a[index1].sgpa;
    a[index1].sgpa = a[index2].sgpa;
    a[index2].sgpa = temp;
    // cout << "swap1 :\n"
    // << a[index1].sgpa << " " << a[index2].sgpa << endl;
    // swapping roll number
    temp = a[index1].roll_no;
    a[index1].roll_no = a[index2].roll_no;
    a[index2].roll_no = temp;
    // cout << "swap2 :\n"
    // << a[index1].roll_no << " " << a[index2].roll_no << endl;
    // swapping name
    string str = "";
    str = a[index1].name;
    a[index1].name = a[index2].name;
    a[index2].name = str;
    // cout << "swap3 :\n"
    // << a[index1].name << " " << a[index2].name << endl;
}
void printarray(student a[]) // for printing the array(used in quicksort)
{
    int n = 10;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i].sgpa << " ";
    }
    cout << endl;
}
void printFinalArray(student a[], int n) // for printing the final top 5 students
{
    int count = 0, i = n - 1;
    cout << endl;
    while (count != 5)
    {
        cout << "Roll No.: " << a[i].roll_no << endl;
        cout << "Name: " << a[i].name << endl;
        cout << "SGPA: " << a[i].sgpa << endl;
        cout << "----------------------------------------------" << endl;
        count++;
        i--;
    }
    cout << endl;
}
int partition(student a[], int low, int high) // for partitioning the array(used in quicksort)
{
    // printarray(a);
    int thekey = a[high].sgpa;
    int i, j;
    i = low;
    j = low;
    while (i <= high)
    {
        if (a[i].sgpa > thekey)
        {
            // cout << "entered-if\n";
            i++;
        }
        else
        {
            // cout << "entered-else\n";
            swap(a, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}
// quicksort(recursive technique)
void quicksort(student a[], int low, int high) // sorting technique
{
    int pindex; // partition index
    if (low < high)
    {
        pindex = partition(a, low, high);
        quicksort(a, low, pindex - 1);
        quicksort(a, pindex + 1, high);
        // cout << "here";
    }
}
// main function
int main()
{
    int n = 10, num = 0;
    // cout << "Enter the number of students: ";
    // cin >> n;
    struct student a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the roll number of the student: " << endl;
        cin >> a[i].roll_no;
        cout << "Enter the name of the student: " << endl;
        cin >> a[i].name;
        cout << "Enter the sgpa of the student: " << endl;
        cin >> a[i].sgpa;
        cout << "---------------------------------------" << endl;
    }
    // printing the data of the students
    cout << endl;
    cout << "<<<<<<<<<<<<<<DATA OF STUDENTS>>>>>>>>>>>>>" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll No.: " << a[i].roll_no << endl;
        cout << "Name: " << a[i].name << endl;
        cout << "SGPA: " << a[i].sgpa << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << endl;
    cout << "<<<<<<<<<<<<<<<<<<LINEAR SEARCH>>>>>>>>>>>>>>>>\n";
    cout << endl;
    float s;
    int count = 0;
    cout << "Enter the SGPA: ";
    cin >> s;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].sgpa == s)
        {
            cout << "Name: " << a[i].name << endl;
            cout << "Roll No.: " << a[i].roll_no << endl;
            cout << "------------------------------------" << endl;
            count++;
        }
    }
    // if no student scored asked sgpa
    if (count == 0)
    {
        cout << "SGPA not found";
        cout << "-----------------------------------------" << endl;
    }
    cout << endl;
    cout << "<<<<<<<<<<<<<<<<<<<BINARY SEARCH>>>>>>>>>>>>>>>>>\n";
    cout << endl;
    // Possible only when input data is sorted
    count = 0;
    string p;
    cout << "Enter the name: ";
    cin >> p;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int c = -1;
        if (p == (a[mid].name))
            c = 0;
        if (c == 0)
        {
            cout << "Name: " << a[mid].name << endl;
            cout << "SGPA: " << a[mid].sgpa << endl;
            cout << "Roll No.: " << a[mid].roll_no << endl;
            cout << "-----------------------------------------" << endl;
            count++;
        }
        // If x greater, ignore left half
        if (p > (a[mid].name))
            low = mid + 1;
        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
    if (count == 0) // If name is not present
    {
        cout << "Name not found.\n";
        cout << "-------------------------------------" << endl;
    }
    cout << endl;
    cout << "<<<<<<<<<<<<<<<<Bubble Sort>>>>>>>>>>>>>>>>" << endl;
    cout << endl;
    string str;
    float temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j].roll_no > a[i].roll_no)
            {
                // swapping roll numbers
                a[j].roll_no ^= a[i].roll_no;
                a[i].roll_no ^= a[j].roll_no;
                a[j].roll_no ^= a[i].roll_no;
                // swapping names
                str = a[j].name;
                a[j].name = a[i].name;
                a[i].name = str;
                // swapping sgpa
                temp = a[j].sgpa;
                a[j].sgpa = a[i].sgpa;
                a[i].sgpa = temp;
            }
        }
    }
    cout << endl;
    cout << "<<<<<<<<<<<<<SORTED DATA OF STUDENTS>>>>>>>>>>>>" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll No.: " << a[i].roll_no << endl;
        cout << "Name: " << a[i].name << endl;
        cout << "SGPA: " << a[i].sgpa << endl;
        cout << "--------------------------------------------" << endl;
    }
    cout << endl;
    cout << "<<<<<<<<<<<<<<<Quick Sort>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // printarray(a);
    quicksort(a, 0, n - 1);
    cout << "<<<<<<<<<<<SORTED DATA OF TOP 5 STUDENTS>>>>>>>>>>>>" << endl;
    printFinalArray(a, n);
    return 0;
}