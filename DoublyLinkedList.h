// Class Definitions

#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Node { // constructing the node class
public:
  string data;
  Node *next;
  Node *previous;

  Node() {
    data = data;
    next = NULL;
    previous = NULL;
  }
  Node(string d) { data = d; }
};

class DoublyLinkedList { // constructing the doubly linked list class

public:
  Node *head;

  DoublyLinkedList() { head = NULL; }
  DoublyLinkedList(Node *n) { head = n; }

  // Append a node to the list (add a PC)

  void appendNode(Node *n) {
    if (head == NULL) {
      head = n;
      cout << "Added PC to list" << endl;
    } else {
      Node *ptr = head;
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
      ptr->next = n;
      n->previous = ptr;
      cout << "Added PC to list" << endl;
    }
  }

  // Removes a node from the list (deletes a PC)

  void deleteNode(Node *n) {
    if (head == NULL) {
      cout << "Error!" << endl;
    } else {
      Node *nextNode = head->next;
      Node *prevNode = head->previous;
      delete head;
      // deleting at the end
      if (nextNode == NULL) {

        prevNode->next = NULL;
        cout << "Removed PC" << endl;
      }

      // deleting in between
      else {
        prevNode->next = nextNode;
        nextNode->previous = prevNode;
        cout << "Removed PC" << endl;
      }
    }
  }

  // Loads the data file

  void load() {
    ifstream infile("data.txt");

    if (infile.fail()) {
      cout << "Problem opening file." << endl;
    } else {
      string option;
      string data1;

      while (infile >> option) {
        cout << option << data1 << endl; 
      }
    }
    infile.close();
  }

  // Displays the PC list

  void displayList() {
    if (head == NULL) {
      cout << "Error!";
    } else {
      cout << endl << "List of PCs" << endl;
      Node *temp = head;

      while (temp != NULL) {
        cout << "\t" << temp->data << endl;
        temp = temp->next;
      }
    }
  }
};