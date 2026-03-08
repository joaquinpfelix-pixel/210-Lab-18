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