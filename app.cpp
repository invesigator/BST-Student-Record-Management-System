#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"
#include <string>
#include <iomanip>

using namespace std;

bool readFile(const char *, BST *);
int menu();

int main() {
    BST t1, t2;
    
    int choice = 0, order = 0, source = 0, opt = 0;

    while (true) {
        choice = menu();
  
        switch (choice){
        // read file
        case 1:
            system("cls");
            
            readFile("student.txt", &t1);
            cout << "The number of student records successfully read are " << t1.count << ".\n\n";

            system("pause");
            system("cls");
            break;

        // deepest nodes
        case 2:
            system("cls");

            t1.deepestNodes();

            system("pause");
            system("cls");
            break;

        // display
        case 3:
            system("cls");

            if (!t1.empty()) {  // if the tree is not empty
                cout << "Please enter the order of the tree (1 for ascending, 2 for descending): ";
                cin >> order;

                cout << "Please enter the source of the tree (1 for print to screen, 2 for file-printing): ";
                cin >> source;
            }

            t1.display(order, source);
            cout << endl;
            
            system("pause");
            system("cls");
            break;

        // clone subtree
		case 4:
            system("cls");

            if (!t1.empty()) {
                cout << "Please enter the subtree root (1 for left subtree, 2 for right subtree): ";
                cin >> opt;
			}
            else
                cout << "Error! The tree is empty.\n\n";

            if (opt == 1) {  // left subtree
                t2.CloneSubtree(t1, t1.root->left->item);  // clone the left subtree

                cout << "\nTree t1: \n";

                t1.preOrderPrint();

                cout << "\nCloned subtree t2: \n";

                t2.preOrderPrint();
            }
            else if (opt == 2) {  // right tree
                t2.CloneSubtree(t1, t1.root->right->item);  // clone the right subtree

                cout << "\nTree t1: \n";

                t1.preOrderPrint();

                cout << "\nCloned subtree t2: \n";

                t2.preOrderPrint();
            }
            else
                cout << "Error! Cannot clone subtree.\n\n";

            system("pause");
            system("cls");
			break;

        // print level nodes
		case 5:
            system("cls");

            if (!t1.printLevelNodes())
                cout << "Error! The tree is empty.\n";

            cout << endl;
            system("pause");
            system("cls");
			break;

        // print path
		case 6:
            system("cls");

            t1.printPath();

            system("pause");
            system("cls");
			break;

        // exit
		case 7:
            system("cls");

            cout << "Exiting the program." << endl;
            cout << "Thank you for using the program." << endl;
            return 0;  // exit the program

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

	system("pause");
	return 0;
}

// display menu
int menu() {
    int choice;

    cout << "\n" << string(45, '=') << endl;
    cout << "\n      Student Record Management System\n";
    cout << "\n" << string(45, '=') << endl;
    cout << "Please choose an option from the menu below:" << endl;
    cout << string(45, '-') << endl;
    cout << "(1)" << " Read data to BST" << endl;
    cout << "(2)" << " Print deepest nodes" << endl;
    cout << "(3)" << " Display student" << endl;
    cout << "(4)" << " Clone Subtree" << endl;
    cout << "(5)" << " Print Level Nodes" << endl;
    cout << "(6)" << " Print Path" << endl;
    cout << "(7)" << " Exit" << endl;
    cout << string(45, '-') << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

// read data from file to BST
bool readFile(const char* filename, BST* t1) {
    ifstream infile;
    infile.open(filename);

    if (!infile.is_open()) {
        cout << "\nError: Cannot open the file " << filename << " successfully.\n";  // error message if cannot open file
        return false;
    }
    else
        cout << "\nSuccessfully open the file " << filename << "." << endl;

    string line;  // store each line of the file
    Student tempStudent;  // store each student record

    while (getline(infile, line)) {
        if (line.find("Student Id") != string::npos) {
            tempStudent.id = stoi(line.substr(line.find("=") + 1));
        }
        else if (line.find("Name") != string::npos) {
            strcpy(tempStudent.name, line.substr(line.find("=") + 2).c_str());
        }
        else if (line.find("Address") != string::npos) {
            strcpy(tempStudent.address, line.substr(line.find("=") + 2).c_str());
        }
        else if (line.find("DOB") != string::npos) {
            strcpy(tempStudent.DOB, line.substr(line.find("=") + 2).c_str());
        }
        else if (line.find("Phone Number") != string::npos) {
            strcpy(tempStudent.phone_no, line.substr(line.find("=") + 2).c_str());
        }
        else if (line.find("Course") != string::npos) {
            strcpy(tempStudent.course, line.substr(line.find("=") + 2).c_str());
        }
        else if (line.find("CGPA") != string::npos) {
            tempStudent.cgpa = stod(line.substr(line.find("=") + 1));
            t1->insert(tempStudent); // insert the student into the BST
        }
    }

    infile.close();
}

