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
   ReviewNode* new Node
}