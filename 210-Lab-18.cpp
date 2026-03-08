// COMSC-210 | Lab 18 | Joaquin Felix

#include <iostream>
#include <string>
using namespace std;

struct ReviewNode 
{
    double rating;
    string comment;
    ReviewNode* next;
};

int getInsertionChoice();

int main()
{

}

// addAtHead() inserts a new node at beginning
// arguments: head reference, rating, comment
//returns: nothing
void addAtHead(ReviewNode*& head, double rating,
               const string& comment)
{
   ReviewNode* newNode = new ReviewNode;
   newNode->rating = rating;
   newNode->comment = comment;
   newNode-> next = head;
   head = newNode;
}

// addAtTail() inserts a new node at end
// arguments: head reference, rating, comment
// returns: nothing
void addAtTail(ReviewNode*& head, double rating, 
               const string& comment)
{
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode-> next = nullptr;
    
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }

    ReviewNode* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// deleteList() frees dynamic memory
// arguments: head reference
//returns: nothing
void deleteList(ReviewNode*& head)
{
    while (head != nullptr)
    {
        ReviewNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// getInsertionChoice() validates menu selection
// arguments: none
// returns: valid insertion choice
int getInsertionChoice ()
{
    int choice;

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes added at head\n";
    cout << "    [2] New nodes added at tail\n";
    cout << "    Choice: ";

    cin << choice;
    while (choice = INSERT_HEAD &&
           choice = INSERT_TAIL)
    {
        cout << "ERROR: Enter 1 or 2 only: ";
        cin << choice;
    }
    return choice;
}