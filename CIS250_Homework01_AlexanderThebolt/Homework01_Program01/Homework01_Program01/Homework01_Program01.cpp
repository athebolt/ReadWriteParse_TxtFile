//============================================================
//Name: Alexander Thebolt
//Date: 02-03-2023
//Desc: Program 01 - Reading, Parsing and Sorting a Text File
//Then displaying a menu with 6 options that display different
//things about the information in the file.
//============================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Employee
{
    string ssn;
    string fName;
    string lName;
    string mInitial;
    string city;
    string state;
    int age = 0;
    string gender;
};

struct Department
{
    Employee employeeData;
    int id = 0;
    string dName;
    string buildingLetter;
    int buildingFloor = 0;
    string departmentPhone;
};

void readTextFile(vector<Department>&);

int displayMenu();

void menuOptions(int, vector<Department>&);

void option1(vector<Department>&);

void option2(vector<Department>&);

void option3(vector<Department>&);

void option4(vector<Department>&);

void option5(vector<Department>&);

void option6(vector<Department>&);

int main()
{
    int menuChoice;

    vector<Department> departmentInfo;
    
    readTextFile(departmentInfo);

    menuChoice = displayMenu();

    menuOptions(menuChoice, departmentInfo);
}

void readTextFile(vector<Department>& departmentInfo)
{
    ifstream inputFile;
    string fileName = "EmployeeList.txt";
    string lineOfText;
    char delim = ',';
    int commaPos;
    int i = 0;

    inputFile.open(fileName);

    if (inputFile)
    {
        //cout << "File is opened." << endl;

        while (getline(inputFile, lineOfText))
        {
            //cout << lineOfText << endl;

            //creates a chunk in memory for each field
            departmentInfo.push_back(Department());

            //getting all values from the text file and storing them
            //fields are in this order: ssn, fName, lName, mInitial, city, state, age, gender
            //id, dName, buildingLetter, buildingFloor, departmentPhone
            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.ssn = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.fName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.lName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.mInitial = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.city = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.state = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.age = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).employeeData.gender = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).id = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).dName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).buildingLetter = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            departmentInfo.at(i).buildingFloor = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            departmentInfo.at(i).departmentPhone = lineOfText;

            i++;
        }
    }
    else
    {
        cout << "File isn't found." << endl;
    }

    inputFile.close();
}

int displayMenu()
{
    int menuChoice;

    cout << "           EMPLOYEE INFORMATION WHATEVER COMPANY INC." << endl;
    cout << "===========================================================================" << endl;
    cout << "   1. Display all employees" << endl;
    cout << "   2. Display name of oldest employee" << endl;
    cout << "   3. Display the building letter and floor for Computer Science department" << endl;
    cout << "   4. Display department names who are in building A" << endl;
    cout << "   5. Find an employee and list their information" << endl;
    cout << "   6. Average age of employees who live in michigan" << endl;
    cout << "   0. Return to menu" << endl;
    cout << "-999. Exit the program" << endl;
    cout << "Enter your selection (0 for menu -999 to exit): ";
    cin >> menuChoice;
    
    return menuChoice;
}

void menuOptions(int menuChoice, vector<Department> &departmentInfo)
{
    while ((menuChoice < 0 || menuChoice > 6) && menuChoice != -999)
    {
        cout << "Enter your selection (0 for menu -999 to exit): ";
        cin >> menuChoice;
    }

    system("cls");

    if (menuChoice == 0)
    {
        menuChoice = displayMenu();

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 1)
    {
        option1(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 2)
    {
        option2(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 3)
    {
        option3(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 4)
    {
        option4(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 5)
    {
        option5(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else if (menuChoice == 6)
    {
        option6(departmentInfo);

        menuChoice = -1;

        menuOptions(menuChoice, departmentInfo);
    }
    else
    {
        cout << "Bye." << endl;
    }
}

void option1(vector<Department> &departmentInfo)
{
    for (int i = 0; i < departmentInfo.size(); i++)
    {
        cout << "EMPLOYEE";

        if (i < 10)
        {
            cout << "0";
        }

        cout << i << endl;
        cout << "==========" << endl;
        cout << "SSN            : " << departmentInfo.at(i).employeeData.ssn << endl;
        cout << "First Name     : " << departmentInfo.at(i).employeeData.fName << endl;
        cout << "Last Name      : " << departmentInfo.at(i).employeeData.lName << endl;
        cout << "Middle Initial : " << departmentInfo.at(i).employeeData.mInitial << endl;
        cout << "City           : " << departmentInfo.at(i).employeeData.city << endl;
        cout << "State          : " << departmentInfo.at(i).employeeData.state << endl;
        cout << "Age            : " << departmentInfo.at(i).employeeData.age << endl;
        cout << "Gender         : " << departmentInfo.at(i).employeeData.gender << endl;
        cout << "Depart ID      : " << departmentInfo.at(i).id << endl;
        cout << "Depart Name    : " << departmentInfo.at(i).dName << endl;
        cout << "Building Letter: " << departmentInfo.at(i).buildingLetter << endl;
        cout << "Building Floor : " << departmentInfo.at(i).buildingFloor << endl;
        cout << "Phone Number   : " << departmentInfo.at(i).departmentPhone << endl << endl << endl;
    }
}

void option2(vector<Department> &departmentInfo)
{
    int age = 0;
    int oldest = 0;

    for (int i = 0; i < departmentInfo.size(); i++)
    {
        if (departmentInfo.at(i).employeeData.age > age)
        {
            age = departmentInfo.at(i).employeeData.age;

            oldest = i;
        }
    }

    cout << "Oldest Employee Name" << endl;
    cout << "====================" << endl;
    cout << departmentInfo.at(oldest).employeeData.lName << ", " << departmentInfo.at(oldest).employeeData.fName << " " << departmentInfo.at(oldest).employeeData.mInitial << "." << endl;
    cout << "Age: " << age << endl;
}

void option3(vector<Department>& departmentInfo)
{
    string buildingLetter;
    int buildingFloor = 0;

    for (int i = 0; i < departmentInfo.size(); i++)
    {
        if (departmentInfo.at(i).dName == "Computer Science")
        {
            buildingLetter = departmentInfo.at(i).buildingLetter;

            buildingFloor = departmentInfo.at(i).buildingFloor;
        }
    }

    cout << "Computer Science Location" << endl;
    cout << "=========================" << endl;
    cout << "Building: " << buildingLetter << "  Floor: " << buildingFloor << endl;
}

void option4(vector<Department>& departmentInfo)
{
    vector<string> depts;

    cout << "Building A Departments" << endl;
    cout << "======================" << endl;
    
    for (int i = 0; i < departmentInfo.size(); i++)
    {
        if (departmentInfo.at(i).buildingLetter == "A")
        {
            if (depts.empty())
            {
                depts.push_back(departmentInfo.at(i).dName);
            }
            else
            {
                bool deptExists = false;

                for (int ii = 0; ii < depts.size(); ii++)
                {
                    if (depts.at(ii) == departmentInfo.at(i).dName)
                    {
                        deptExists = true;
                    }
                }

                if (!deptExists)
                {
                    depts.push_back(departmentInfo.at(i).dName);
                }
            }
        }
    }

    for (int i = 0; i < depts.size(); i++)
    {
        cout << depts.at(i) << endl;
    }
}

void option5(vector<Department>& departmentInfo)
{
    string ssn;
    bool found = false;
    int employee = 0;

    cout << "Employee Search" << endl;
    cout << "===============" << endl;
    cout << "Enter the ssn for the employee" << endl;
    cin >> ssn;

    for (int i = 0; i < departmentInfo.size(); i++)
    {
        if (ssn == departmentInfo.at(i).employeeData.ssn)
        {
            found = true;
            
            employee = i;
        }
    }

    if (found)
    {
        cout << "SSN            : " << departmentInfo.at(employee).employeeData.ssn << endl;
        cout << "First Name     : " << departmentInfo.at(employee).employeeData.fName << endl;
        cout << "Last Name      : " << departmentInfo.at(employee).employeeData.lName << endl;
        cout << "Middle Initial : " << departmentInfo.at(employee).employeeData.mInitial << endl;
        cout << "City           : " << departmentInfo.at(employee).employeeData.city << endl;
        cout << "State          : " << departmentInfo.at(employee).employeeData.state << endl;
        cout << "Age            : " << departmentInfo.at(employee).employeeData.age << endl;
        cout << "Gender         : " << departmentInfo.at(employee).employeeData.gender << endl;
        cout << "Depart ID      : " << departmentInfo.at(employee).id << endl;
        cout << "Depart Name    : " << departmentInfo.at(employee).dName << endl;
        cout << "Building Letter: " << departmentInfo.at(employee).buildingLetter << endl;
        cout << "Building Floor : " << departmentInfo.at(employee).buildingFloor << endl;
        cout << "Phone Number   : " << departmentInfo.at(employee).departmentPhone << endl;
    }
    else
    {
        cout << "The employee with the ssn of " << ssn << " does not exist" << endl;
    }
}

void option6(vector<Department>& departmentInfo)
{
    int ages = 0;
    int people = 0;
    int avg = 0;

    for (int i = 0; i < departmentInfo.size(); i++)
    {
        if (departmentInfo.at(i).employeeData.state == "MI") 
        {
            ages += departmentInfo.at(i).employeeData.age;

            people++;
        }
    }

    avg = ages / people;

    cout << "Average age for employees who live in MI" << endl;
    cout << "========================================" << endl;
    cout << avg << endl;
}