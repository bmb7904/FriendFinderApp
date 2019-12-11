/*
 * This class has the main functions that do the comparing and printing for the app
 * Also, reading data from files
 */
#ifndef FRIENDFINDER_H
#define FRIENDFINDER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "FriendSortedList.h"
#include "FriendRecord.h"
#include "TopThreeFriendScores.h"


using namespace std;

class FriendFinder
{
    public:
        FriendFinder();
        ~FriendFinder();
        void compareAndPrint(FriendRecord record1, FriendRecord record2, FriendSortedList sortedList);
        void readDataInFile(FriendSortedList &friendList);

        private:

};

// constructor
FriendFinder::FriendFinder()
{

}

// destructor
FriendFinder::~FriendFinder()
{

}

// takes in a alphabetically sorted linked list composed of objects of the FriendRecord class
// each object in the sorted linked list is a record of a person including their interests and values
// using 2 current pointers, starts with the first node and compares it with every other node in the sorted linked list
// if a node (a friend record) has matching interests with another node (friend record), the score for the interests are added
// each person has a friendScore with every other person using the app

// uses nested loops that use the same alphabetically sortedList, but with different pointers
void FriendFinder::compareAndPrint(FriendRecord record1, FriendRecord record2, FriendSortedList sortedList)
{
    // set current1 pointer to head pointer
    sortedList.setCurrentToHead();

    // while the current point is not NULL(this takes care of empty lists and end of list)...
    // let the node(a FriendRecord Object) that current is pointing at be represented by record1 object
    while(sortedList.getCurrent(record1))
    {
        // creates TopThreeFriendScores object
        // this object of this class has functions to take in the friendscores, sort them, and print them
        TopThreeFriendScores topThree;

        // set the current2 pointer, of the same linked list, equal to head
        sortedList.setCurrent2ToHead();

        // while current2 is not NULL(this takes care of empty lists and end of list)
        // let the node(a FriendRecord Object) that current2 is pointing at be represented by record2 object
        while(sortedList.getCurrent2(record2))
        {
            // temp int variable that sums each score between 2 nodes
            // each person has a friend score with every other person
            // this is the sum of all of their common interest values
            int friendScore = 0;

            // each person has 5, and only 5, different interests. We can hard code the 5
            // this will increment through the favorite interests array and the favorite interests value array
            for(int i = 0; i < 5; i++)
            {
                // if a person has a common interest with another, sums their values for that
                // interest and add it to the total friend score
                if( (record1.favorites[i] == record2.favorites[i]) && (record1.nameForSorting() != record2.nameForSorting()) )
                {
                    friendScore += (record1.favoritesValue[i] + record2.favoritesValue[i]);

                }
            }

            // set the total score with this person to their friendship score
            // a new friendship score is being updated for every comparison
            // with every person
            record2.friendshipScore = friendScore;

            // inserts a friendRecord into a numerically sorted Linked List
            // only insert friendship scores that are not 0 to save memory and computation
            if(record2.friendshipScore != 0)
            {
                topThree.insertIntoSortedList(record2);
            }

            // increments the current2 pointer
            sortedList.incrementCurrent2();
        }

        topThree.printTopThreeScores(record1);

        //increments the current pointer
        sortedList.incrementCurrent();
    }
}


// takes in a FriendSortedList passed by reference, and a file name and reads it
void FriendFinder::readDataInFile(FriendSortedList &friendList)
{
    ifstream fin;
    // this is a relative path to the file
    // this file must be included in the main project folder
    fin.open("FriendFinderData.txt");
    
    // checks to make sure file opens correctly
    if(! fin.is_open())
    {
        cout << "Error opening file!";
    }

    // EOF will return false when end of file is reached
    while(! fin.eof())
    {

        fin >> FR.firstName;
        fin >> FR.lastName;
        fin >> FR.favorites[0];
        fin >> FR.favoritesValue[0];
        fin >> FR.favorites[1];
        fin >> FR.favoritesValue[1];
        fin >> FR.favorites[2];
        fin >> FR.favoritesValue[2];
        fin >> FR.favorites[3];
        fin >> FR.favoritesValue[3];
        fin >> FR.favorites[4];
        fin >> FR.favoritesValue[4];

        // add FriendRecord object, with all of its attributes, into sorted linked list that sorts by string (names)
        friendList.InsertIntoList(FR,0);

        // going to comment this out, as it is not needed anymore but might be
        //cout << FR.firstName << " added to sorted linked list" << endl << endl;

    }
    fin.close();
}

#endif /* FRIENDFINDER_H */

