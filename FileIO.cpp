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

    }
    inputFile.close();
  }
  else cout << "Unable to open file";

  //faculty
  ifstream inputFile("masterStudent.txt");
  if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {

    }
    inputFile.close();
  }
  else cout << "Unable to open file";
}

void FileIO::writeFile()
{
  //students first
  ofstream studentFile;
  studentFile.open ("masterStudent.txt");
  studentFile <<
  studentFile.close();

  //faculty
  ofstream facultyFile;
  facultyFile.open ("masterFaculty.txt");
  facultyFile <<
  facultyFile.close();

}
