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

void FileIO::openFile(BST<Student>* sTree, BST<Faculty>* fTree)
{
  //students
  ifstream sFile("studentTable.txt");
  string line;
  if (sFile.is_open())
  {
    while ( getline (sFile, line) )
    {
      for(int i = 0; i < line.size(); ++i)
      {
          Student* s = new Student();
          sTree->insert(s->getID(), s);
      }
    }
    sFile.close();
  }
  else cout << "Unable to open file";

  //faculty
  ifstream fFile("facultyTable.txt");
  if (fFile.is_open())
  {
    while ( getline (fFile,line) )
    {
      for(int i = 0; i < line.size(); ++i)
      {
          Faculty* f = new Faculty();
          fTree->insert(f->getID(), f);
      }
    }
    fFile.close();
  }
  else cout << "Unable to open file";
}

void FileIO::writeFile(BST<Student>* sTree, BST<Faculty>* fTree)
{
  //students first
  ofstream studentFile;
  studentFile.open("studentTable.txt");
  // studentFile << sTree->writeTree() << endl;
  studentFile.close();

  //faculty
  ofstream facultyFile;
  facultyFile.open("masterFaculty.txt");
  // facultyFile << fTree->writeTree() << endl;
  facultyFile.close();

}
