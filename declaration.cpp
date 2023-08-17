#include <iostream>
#include "declaration.h"
#include <fstream>
#include "globals.h"
#include <sstream>

// Here sstream is used for taking one line of text file into string stream
bool check(string username, string password)
{
    
    ifstream infile;
    // Note: Change the path according to user's need
    infile.open(("C:\\Users\\HP\\OneDrive\\Desktop\\PROJECTs\\DataBase.txt"));
    while (getline(infile, content))
    {
        istringstream iss(content);
        string storedusername, storedpassword;

        // this getline method will put iss(string stream) into storedusername until ':' comes
        getline(iss, storedusername, ':');  
        getline(iss, storedpassword);
        cout << storedusername << storedpassword << endl;
        // Doing authentication of username and password
        if (storedusername == username && storedpassword == password)
        {
            infile.close();
            return true;
        }
        else
        {
            if (infile.eof())
            {
                infile.close();
                return false;
            }
        }
    }
}
