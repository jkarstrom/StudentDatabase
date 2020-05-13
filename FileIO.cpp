//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database
#include "FileIO.h"

using namespace std;

FileIO::FileIO()
{
  //default constructor
}

FileIO::~FileIO()
{
  //deconstructor
}

void FileIO::openFile()
{
  //students
  ifstream inputFile("masterStudent.txt");
  if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
      for(int i = 0; i < line.size(); ++i)
      {
        //read student information and insert it into tree
      }
    }
    inputFile.close();
  }
  else cout << "Unable to open file";

  //faculty
  ifstream inputF("masterStudent.txt");
  if (inputF.is_open())
  {
    while ( getline (inputF,line) )
    {
      for(int j = 0; j < line.size(); ++j)
      {
        // read faculty information and insert it into tree
      }
    }
    inputF.close();
  }
  else cout << "Unable to open file";
}

void FileIO::writeFile()
{
  //students first
  ofstream studentFile;
  studentFile.open ("masterStudent.txt");
  //write out the printed summary of each student per line
  //studentFile << masterStudent->printTree(masterStudent->getRoot()); << endl
  studentFile.close();

  //faculty
  ofstream facultyFile;
  facultyFile.open ("masterFaculty.txt");
  //write out the printed summary of each faculty per line
  //facultyFile << masterFaculty->printTree(masterFaculty->getRoot()); << endl
  facultyFile.close();

}
