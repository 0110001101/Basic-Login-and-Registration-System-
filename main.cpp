// This is login and registration system project

#include <iostream>
#include <fstream>
#include <string.h>
#include "globals.h"
#include "declaration.h"
using namespace std;

int main()
{

    char quest;
    cout << "What do you want : " << endl;
    cout << "For Sign up type S \n"
         << "For login type L" << endl;
    cin >> quest;
    cin.ignore();

    // Taking user's information
    cout << "Enter you user id : " << endl;
    getline(cin, userid);

    cout << "Enter Password(alphanumeric) : " << endl;
    getline(cin, pass);

    // ofstream declaration for registration
    ofstream onfile;

    // ifstream declaration for login line is for taking line of file
    ifstream infile;
    string line;

    // switching between sign and login options
    switch (quest)
    {
    case 'S':
        // Note: Change the path according to user's need
        onfile.open("C:\\Users\\HP\\OneDrive\\Desktop\\PROJECTs\\DataBase.txt", ios::app);
        if (!onfile.is_open())
        {
            std::cerr << "Error opening the file." << std::endl;
            return 1; // or any other error handling you prefer
        }
        else
        {
            onfile << userid << ":" << pass << endl;
        }
        onfile.close();
        cout << "For login run the program again :)" << endl;
        break;
    case 'L':

        // Opening the file which is accessible after authentication
        int ask;
        // Note: Change the path according to user's need
        infile.open("C:\\Users\\HP\\OneDrive\\Desktop\\PROJECTs\\01_CGPA.txt");
        if (!infile.is_open())
        {
            cerr << "There is something error in opening the database :(" << endl;
            return 0;
        }

        // Login process
        while (1)
        {
            if (check(userid, pass) == true)    // function that do for authentication
            {
                cout << "Your authentication is done ! Here is your file" << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                // printing the data of the accessed file
                while (getline(infile, line))
                {
                    cout << line << endl;
                }
                cout << "your session is closed ! \n rerun the program to next use" << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                return 0;
            }
            else
            {
                cout << "Invalid combination of password or username!" << endl;
                cout << "Do you want to try again (1/0)" << endl;
                cin >> ask;
                if (ask == 0)
                {
                    return 0;
                }
            }
        }
        infile.close();
        break;
    }
    return 0;
}