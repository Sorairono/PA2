//This program count the number of files and directories in a directory
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include "version.h"
using namespace std;

//This function traverse the directory given
void listdir(const char *name, int &dir_num, int &file_num, int &byte_num)
{
    DIR *dir;
    struct dirent *entry;
    struct stat byteCheck;
    //Can't open directory
    if (!(dir = opendir(name)))
    {
        return;
    }
    //Loop until end of given directory
    while ((entry = readdir(dir)) != NULL) 
    {
        //Break if directory name is not found
        if (access(name, X_OK) != 0) 
        {
            break;
        }
        //Link is a directory
        if (entry->d_type == DT_DIR) 
        {
            char path[1024];
            //Skip "." and ".."
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {    
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            if (access(path, X_OK) != 0) 
            {
                continue;
            }
            dir_num = dir_num + 1;
            listdir(path, dir_num, file_num, byte_num);
        } 
        //Entry is a link to another location
        else if (entry->d_type == DT_LNK) 
        {
            continue;
        }
        //Get number of files and number of bytes 
        else 
        {
            char path[1024];
            char * path_ptr = path;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            if (access(path, R_OK) != 0) 
            {
                continue;
            }
            stat(path_ptr, &byteCheck);
            file_num = file_num + 1;
            byte_num = byte_num + byteCheck.st_size;
        }
    }
    closedir(dir);
}
    
    //Main
int main(int argc, char* argv[]) 
{
    int dir_num = 0, file_num = 0, byte_num = 0;
    listdir(argv[1],  dir_num, file_num, byte_num);
    cout << "The total number of directories in directory " << argv[1] << " is: " << dir_num << endl;
    cout << "The total number of files in directory " << argv[1] << " is: " << file_num << endl;
    cout << "The total number of bytes occupied by all files in directory " << argv[1] << " is: " << byte_num << endl;
    return 0;
}
