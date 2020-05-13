//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database
#ifndef FILEIO_H
#define FILEIO_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

using namespace std;

class FileIO
{
public:

  FileIO();//default constructor
  ~FileIO();//deconstructor

  //core functions
  void writeFile(BST<Student>* sTree, BST<Faculty>* fTree);
  void openFile(BST<Student>* sTree, BST<Faculty>* fTree);

  //aux functions


private:
  //vars
  string line = "";
};
#endif
