// COMSC-210 | Lab 18 | Joaquin Felix

#include <iostream>
#include <string>
using namespace std;

// Named constants
const int INSERT_HEAD = 1;
const int INSERT_TAIL = 2;
const double MIN_RATING = 0.0;
const double MAX_RATING = 5.0;

// Node structure
struct ReviewNode 
{
    double rating;
    string comment;
    ReviewNode* next;
};

// Function Prototypes
void addAtHead(ReviewNode*& head, double rating,
               const string& comment);
void addAtTail(ReviewNode*& head, double rating, 
               const string& comment);
void outputReviews(const ReviewNode* head);
void deleteList(ReviewNode*& head);               
int getInsertionChoice();
double getValidatedRating();
char getYesNo();

int main()
{
    ReviewNode* head = nullptr;

    int choice = getInsertionChoice();

    char another;
    
    do {
        double rating = getValidatedRating();

        cout << "Enter review comments: ";
        cin.ignore();
        string comment;
        getline(cin, comment);

        if (choice == INSERT_HEAD)
        {
            addAtHead(head, rating, comment);
        } else {
            addAtTail(head, rating, comment);
        }
        another = getYesNo();
    } while (another == 'y' || another == 'Y');

    outputReviews(head);
    deleteList(head);

    return 0;
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

    cin >> choice;
    while (choice != INSERT_HEAD &&
           choice != INSERT_TAIL)
    {
        cout << "ERROR: Enter 1 or 2 only: ";
        cin >> choice;
    }
    return choice;
}

void outputReviews(const ReviewNode* head)
{
    const ReviewNode* temp = head;
    int count = 0;
    double sum = 0.0;

    cout << "\nOutputting all reviews:\n";

    while (temp != nullptr) 
    {
        count++;
        cout << "   > Review #" << count
             << ": " << temp->rating
             << ": " << temp->comment << endl;
        
        sum += temp->rating;
        temp = temp->next;
    }

    if (count > 1) 
    {
        cout << "   > Average: "
             << sum / count << endl;
    } else {
        cout << "   > No reviews entered.\n";
    }
}

// get ValidatedRating() ensures rating in range
// arguments: none
// returns: valid rating
double getValidatedRating()
{
    double rating;

    cout << "Enter review rating 0-5: ";
    cin >> rating;

    while (rating < MIN_RATING ||
           rating > MAX_RATING)
    {
        cout << "ERROR: Rating must be between "
             << MIN_RATING << " and "
             << MAX_RATING << ": ";
        cin >> rating;
    }

    return rating;
}

// getYesNo() validates Y/N input
// arguments: none
// returns: validated character
char getYesNo()
{
    char answer;

    cout << "Enter another review? Y/N: ";
    cin >> answer;

    while (answer != 'y' && answer != 'Y' &&
           answer != 'n' && answer != 'N')
    {
        cout << "ERROR: Enter Y or N only: ";
        cin >> answer;
    }
    return answer;
}