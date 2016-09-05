#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>

int main()
{
    using namespace std;
    vector<string> allFiles;
    DIR *dir;
struct dirent *ent;
if ((dir = opendir ("./csvfiles")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    //printf ("%s\n", ent->d_name);
    allFiles.push_back(ent->d_name);
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
}
for (int i = 3; i < allFiles.size(); ++i)
{
    cout << allFiles[i] << ": ";
     ifstream in("./csvfiles/" + allFiles[i]);
     if(in)
     
        cout << "File opened" << endl;
     else 
        cerr << "error" << endl;

    string line, field;

    vector< vector<string> > array;  // the 2D array
    vector<string> v;                // array of values for one line only

    while ( getline(in,line) )    // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss,field,','))  // break line into comma delimitted fields
        {
            v.push_back(field);  // add each field to the 1D array
        }

        array.push_back(v);  // add the 1D array to the 2D array
    }
    in.close();
    // print out what was read in
    int counter = 0;
    for (size_t array1 = 0; array1<array.size(); ++array1)
    {
        for (size_t array2=0; array2<array[array1].size(); array2++)
        {
            if(array1 == array2) {
            //cout << array[0][array2] << endl; // (separate fields by |)
            counter++;
            }
            
        }
    }
    cout << counter << endl;
}
   
    return 0;
}