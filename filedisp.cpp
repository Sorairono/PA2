#include <string>
#include <string.h>
#include <iostream>
#include "version.h"
using namespace std;

int main(int argc, char* argv[])
{
    displayVersion();
    //Not exactly 2 arguments are passed
    if (argc != 2) 
    {
        cout << "Inavlid argument" << endl;
    }
    //If option is -d, print number of directory
    else if (strcmp(argv[1],"-d") == 0) 
    {
        string line_read = "";
        getline(cin, line_read);
        while (line_read != "") 
        {
            if (line_read.find("directories") != -1) 
            {
                cout << line_read << endl;
            	return 0;
	        }
            else 
            {
                getline(cin, line_read);
                continue;
            }
        }
    }
    //If option is -f, print number of files
    else if (strcmp(argv[1],"-f") == 0) 
    {
        string line_read = "";
        getline(cin, line_read);
        while (line_read != "") 
        {
            if (line_read.find("files") != -1) 
            {
                cout << line_read << endl;
                return 0;
            }
            else 
            {
                getline(cin, line_read);
                continue;
            }
        }
    }
    //If option is -b, print number of bytes
    else if (strcmp(argv[1],"-b") == 0) 
    {
        string line_read = "";
        getline(cin, line_read);
        while (line_read != "") 
        {
            if (line_read.find("bytes") != -1) 
            {
                cout << line_read << endl;
                return 0;
            }
            else 
            {
                getline(cin, line_read);
                continue;
            }
        }
    }
    else 
    {
        cout << "Invalid arguments" << endl;
    }
}