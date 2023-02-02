/*
Student Name: Kennedy Keyes
Student NetID: kfk38
Compiler Used: Visual Studio Code (g++, mingw64)
Program Description:
This program will manage a list of Player Characters (PCs)
by adding, removing, editing, searching, and displaying the contents
within the PC list.
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

int main() {

  DoublyLinkedList obj;
  string option; // user input
  string data1; // new node data
  string stat; // stat for set and search
  int num; // the level integer
  string job; // the job/race input

  do {

    cin >> option; // user input
    Node *n1 = new Node(); // makes a new node

    if (option == "add") { // adds a new PC
      cin >> data1;
      n1->data = data1;
      obj.appendNode(n1);
    }

    if (option == "remove") { // removes a PC
      cin >> data1;
      obj.deleteNode(n1); // problem
    }

    if (option == "load") { // loads the data file
      obj.load();
    }

    if (option == "set") { // will set PC's job, race, or level
        cin >> data1 >> stat >> num; 
        cout << "Successfully set PC " << data1 << " " << stat << " " << "to" << " " << num << endl; 
    }

    if (option == "search") { // will search for a certain job, race, or level
        cin >> stat >> num;
        cout << "Search results\n" << "\t" << data1 << " " << stat << " " << num << endl;
    }

    if (option == "display") { // will display the list of PCs
      obj.displayList();
    }

  } while (option != "exit"); // doesn't exit the program unless told so

  return 0;
}