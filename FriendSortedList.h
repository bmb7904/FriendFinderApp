/*
 * An object of this class will create a sorted Linked List
 * and depending on what is specified, the list can be sorted alphabetically or numerically
 */

#ifndef FRIENDSORTEDLIST_H
#define FRIENDSORTEDLIST_H

#include <iostream>
#include "FriendNode.h"

class FriendSortedList
{
                public:

                    FriendSortedList();
                    ~FriendSortedList();
                    void InsertIntoList(FriendRecord friendrecord, int sortByDeclaration);
                    void setCurrentToHead();
                    void incrementCurrent();
                    bool getCurrent(FriendRecord &fr);
                    void setCurrent2ToHead();
                    void incrementCurrent2();
                    bool getCurrent2(FriendRecord &fr);
                    void deleteList();

                private:
                    FriendNode *head, *current, *current2;



};

// constructor
FriendSortedList::FriendSortedList()
{
    head = NULL;
}

// destructor
FriendSortedList::~FriendSortedList()
{

}

// adds friendRecords to a linked list that is sorted alphabetically or numerically
void FriendSortedList::InsertIntoList(FriendRecord fr, int sortByDeclaration)
{
    // if 0 is specified by the parameter, the list will be sorted alphabetically
    if(sortByDeclaration == 0)
    {

        FriendNode *newNode = new FriendNode(fr);
        FriendNode *curr = head;
        FriendNode *prev = NULL;

        // if curr = NULL there are two possibilities;
        //      1.) current = head = NULL -- the list is empty
        //      2.) curr is pointing at the last node in the list, who's *next = NULL
        //  curr starts at the head and we compare the new node's object (friendRecord)'s name with the object's name point at by curr
        // as long as the new node's name > then curr's, we incrememnt through the list until it is not > or curr = NULL;
        // this sorts the list in alphabetial order
        // capitialization DOES matter, as we are comparing ASCII values
        while((curr != NULL) && (newNode ->friendRecord.nameForSorting() > curr->friendRecord.nameForSorting()))
        {
            prev = curr;
            curr = curr ->next;
        }

        // at this point, prev -> NULL only if new node's friendRecord's name is less than all other nodes OR
        // the list was empty to begin with
        // either way - the new node becomes the new head
        if(prev == NULL)
        {
            head = newNode;
        }

        // otherwise: connect prev -> next to new Node
        else
        {
            prev -> next = newNode;
        }

        // finally connect newNode->next to current
        // this will work even if curr is NULL and we reached the end of the list
        // the final node's next will always be NULL
        newNode ->next = curr;
    }

    // if 1 is specified as parameter, a list sorted by friendship score will be built
    // this will numerically sort in descending order (highest to lowest)
    else if (sortByDeclaration == 1)
    {
        // temporary node that points to a newly created node
        FriendNode *newNode = new FriendNode(fr);
        // curr is temporary pointer. DO NOT confuse with current
        FriendNode *curr = head;
        // temporary pointer
        FriendNode *prev = NULL;

        // if curr = NULL there are two possibilities;
        //   1.) current = head = NULL -- the list is empty
        //   2.) curr is pointing at the last node in the list, who's *next = NULL
        //  curr starts at the head and we compare the new node's object (friendRecord)'s friendScore with the object's friendScore pointed at by curr
        // as long as the new node's friendshipScore < then curr's, we incrememnt through the list until it is not < or curr = NULL;
        // This sorts the list as it is created numerically (highest to lowest)


        while((curr != NULL) && (newNode ->friendRecord.friendshipScore < curr ->friendRecord.friendshipScore))
        {
            prev = curr;
            curr = curr ->next;
        }

        // at this point, prev -> NULL only if new node's friendRecord's score is greater than all other nodes OR
        // the list was empty to begin with
        // either way - the new node becomes the new head
        if(prev == NULL)
        {
            head = newNode;
        }

        // otherwise: connect prev -> next to new Node
        else
        {
            prev -> next = newNode;
        }

        // finally connect newNode->next to current
        // this will work even if curr is NULL and we reached the end of the list
        // the final node's next will always be NULL
        newNode ->next = curr;
    }

    else
    {
        cout << "ERROR" << endl;
    }
}

void FriendSortedList::setCurrentToHead()
{
    current = head;
}

void FriendSortedList::incrementCurrent()
{
    // if list is not empty. i.e. curr != head != NULL
    if(current != NULL)
    {
        current = current -> next;
    }
}

bool FriendSortedList::getCurrent(FriendRecord &fr)
{
    if(current != NULL)
    {
        fr = current ->friendRecord;
        return true;
    }

    return false;
}

void FriendSortedList::setCurrent2ToHead()
{
    current2 = head;
}

void FriendSortedList::incrementCurrent2()
{
    //if list is not empty, i.e. current2 != head != NULL
    if(current2 != NULL)
    {
        current2 = current2 ->next;
    }
}

bool FriendSortedList::getCurrent2(FriendRecord& fr)
{
    if(current2 != NULL)
    {
        fr = current2 ->friendRecord;
        return true;
    }

    return false;
}

// This function will clear the entire list
// uses both current and next pointers as well as temporary temp pointer
// I wrote this with no outside help as a challenge, so it might not be ideal
// this was necessary in order to use a temporary, numerically sorted linked list in the FriendNode class
void FriendSortedList::deleteList()
{
    FriendNode *temp = head;

    // while there are at least two nodes in the entire list
    while(head ->next != NULL)
    {
        setCurrentToHead();

        // this increments current to the end of the list,
        // and temp will always follow along exactly one node behind current
        while(current ->next != NULL)
        {
            temp = current;
            current = current ->next;
        }

        // deletes the node current in pointing at, which at this point,
        // should be the final node in the list
        delete current;
        // this is necessary to set the *next of the new final node to NULL
        temp ->next = NULL;
    }

    delete head;

    // sets the head back to NULL in order to make it ready to create a new list
    head = NULL;
}

#endif /* FRIENDSORTEDLIST_H */

