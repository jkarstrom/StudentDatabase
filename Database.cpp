#include "Database.h"

Database::Database(){
    masterFaculty = new BST<Faculty>();
    masterStudent = new BST<Student>();
    history = new Rollback();
    running = true;
}

Database::~Database(){

}

void Database::makeTrees(){
    // check if files for trees are already there, if so, update

}

void Database::run(){
    // look for trees


    // print menu
    printMenu();

    // make user's selection
    cin >> userAction;

    if(userAction == 1)
        masterStudent->printTree(masterStudent->getRoot());
    else if(userAction == 2)
        masterFaculty->printTree(masterFaculty->getRoot());
    else if(userAction == 3 || userAction == 5){
        cout << "Enter student id: ";
        cin >> someID;
        masterStudent->search(someID, userAction);
    }
    else if(userAction == 4 || userAction == 6){
        cout << "Enter faculty id: ";
        cin >> someID;
        masterFaculty->search(someID, userAction);
    }

    // add transaction to rollback
    else if(userAction >= 7 && userAction <= 12){
        Transaction* myMove = new Transaction(userAction);
        myMove->proceed(masterStudent, masterFaculty);
        myMove->reverse();
        history->update(myMove);
    }
    else if(userAction == 13){
        // rollback
        Transaction* myReverse = history->goBack();
        myReverse->proceed(masterStudent, masterFaculty);
        delete myReverse;
    }
    else if(userAction == 14)
        running = false;

}

bool Database::isRunning(){
    return running;
}


void Database::printMenu(){
    cout << endl << "Main Menu" << endl;
    cout << "(1) Print all students and their information" << endl;
    cout << "(2) Print all faculty and their information" << endl;
    cout << "(3) Print a student's information" << endl;
    cout << "(4) Print a faculty member's information" << endl;
    cout << "(5) Find a student's faculty advisor" << endl;
    cout << "(6) Find all advisees of a faculty member" << endl;

    cout << "(7) Add a new student" << endl;
    cout << "(8) Delete a student" << endl;

    cout << "(9) Add a new faculty member" << endl;
    cout << "(10) Delete a faculty member" << endl;

    cout << "(11) Change a student's advisor" << endl;
    cout << "(12) Remove an advisee from a faculty member" << endl;

    cout << "(13) Rollback" << endl;
    cout << "(14) Exit" << endl;
}

void Database::importFiles(){
	cout <<"Importing files"<<endl;
	ifstream sFile;
	ifstream fFile;
	string input="";
	int sCount=0;
	int stepCount=1;

	//variables of students and faculty
	int sID = 0;
 	string sName = "";
 	string sLevel = "";
	string sMajor = "";
  double gpa = 0.0;
  int sAdvisorID = 0;
  int fID = 0;
  string fName = "";
  string fLevel = "";
  string department = "";
  int adviseeID = 0;

	sFile.open("studentTable.txt");
//opening and importing student file
  if(sFile.is_open()) {
    try {
      getline(sFile, input);
      if(input != "") {
        sCount = atoi(input.c_str());
        sCount*=7;
      }
    }
    catch(exception e) {
      cout << "File is not in correct format, it cannot be read" << endl;
    }

    for(int i = 0; i < sCount; i++) {
      getline(sFile, input);
      switch(stepCount) {
        case 1: {
          if(input != "~") {//the space saver between elements of the tree
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 2: {
          try {
            sID = atoi(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 3: {
          sName = input;
          break;
        }
        case 4: {
          sLevel = input;
          break;
        }
        case 5: {
          sMajor = input;
        }
        case 6: {
          try {
            gpa = atof(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 7: {
          try {
            sAdvisorID = atoi(input.c_str());

            Student *stu = new Student(sID, sName, sLevel, sMajor, gpa, sAdvisorID);
            TreeNode<Student> *sNode = new TreeNode<Student>(stu, sID);
            masterStudent.insert(sNode);
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        default:
          break;
      }

      stepCount++;
      stepCount%=7; //makes cases repeat after each student

    }
    cout <<"Students Filled"<<endl;
  }

  else {
    cout << "Creating empty student tree" << endl;
  }
  sFile.close();

  //opening and importing faculty file
  stepCount=1;
  int fCount=0;
  fFile.open("facultyTable.txt");
  if(fFile.is_open()) {
    try {
      getline(fFile, input);

      if(input != "") {
        fCount = atoi(input.c_str());
        fCount*=7;
      }
    }
    catch(exception e) {
      cout << "File is not in correct format, it cannot be read" << endl;
    }

    for(int i = 0; i < fCount; i++) {
      getline(fFile, input);

      switch(stepCount) {
        case 1: {
          if(input != "~") {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 2: {
          try {
            fID = atoi(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 3: {
          fName = input;
          break;
        }
        case 4: {
          fLevel = input;
          break;
        }
        case 5: {
          department = input;
        }
        case 6: {
          try {
            cout<<"";
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 7: {
          try {
            adviseeID = atoi(input.c_str());

            Faculty *fac = new Faculty(fID, fLevel, fName, department);
            TreeNode<Faculty> *fNode = new TreeNode<Faculty>(fac, fID);
            masterFaculty.insert(fNode);
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        default:
          break;
      }
      stepCount++;
      stepCount%=7; //makes cases repeat after each student
    }
    cout <<"Faculty Filled"<<endl;
  }
  else {
    cout << "Creating empty faculty tree" << endl;
  }
	fFile.close();
}

void Database::exportFiles(){
	//saving student tree
	TreeNode<Student> *stu = masterStudent.getRoot();
	string fileName="studentTable.txt";
	outputStudent(stu, fileName);


	//saving faculty tree
	TreeNode<Faculty> *fac = masterFaculty.getRoot();
	fileName="facultyTable.txt";
	outputFaculty(fac, fileName);
}

void Database::outputStudent(TreeNode<Student> *stu, string fileName){
	ofstream out;

	//for student tree:
	out.open(fileName.c_str());
	if(out.is_open()){
		if(stu != NULL) {
   			out << "~" << endl;
    		out << stu->data->getID() << endl;
    		out << stu->data->getName() << endl;
    		out << stu->data->getLevel() << endl;
    		out << stu->data->getMajor() << endl;
    		out << stu->data->getGPA() << endl;
    		out << stu->data->getAdvisor() << endl;

    		if(stu->left != NULL) {
      			outputStudent(stu->left, fileName);
    		}

    		if(stu->right != NULL) {
      			outputStudent(stu->right, fileName);
    		}
  		}
	}
	out.close();
	cout <<"Students saved"<<endl;
}

void Database::outputFaculty(TreeNode<Faculty> *fac, string fileName){
	ofstream out;

	//for faculty tree:
	out.open(fileName.c_str());
	if(out.is_open()){
		if(fac != NULL) {
   			out << "~" << endl;
    		out << fac->data->getID() << endl;
    		out << fac->data->getName() << endl;
    		out << fac->data->getLevel() << endl;
    		out << fac->data->getDepartment() << endl;
    		out << " "<< endl;
    		out << fac->data->getAdviseeID() << endl;

    		if(fac->left != NULL) {
      			outputFaculty(fac->left, fileName);
    		}

    		if(fac->right != NULL) {
      			outputFaculty(fac->right, fileName);
    		}
  		}
	}
	out.close();
	cout <<"Faculty saved"<<endl;
}
