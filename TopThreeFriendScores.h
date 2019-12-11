// this class will take all of the friend scores for each person with every other person
// it will then determine the top ranking friend scores for each person
// this class has functions to take in friendRecord object, sort by friendship Scores, and print them
#ifndef TOPTHREEFRIENDSCORES_H
#define TOPTHREEFRIENDSCORES_H

#include <iostream>
#include <string.h>
#include <iomanip>
#include "FriendRecord.h"
#include "FriendSortedList.h"

using namespace std;

// a new sorted list is created
FriendSortedList sortedListByScore;
FriendRecord FR;

class TopThreeFriendScores
{
        public:
            TopThreeFriendScores();
            ~TopThreeFriendScores();
            void insertIntoSortedList(FriendRecord friendRecord);
            void printTopThreeScores(FriendRecord);
            
    
        private:
            
};

// constructor
TopThreeFriendScores::TopThreeFriendScores()
{

}

// destructor
TopThreeFriendScores::~TopThreeFriendScores()
{
    
}

void TopThreeFriendScores::insertIntoSortedList(FriendRecord friendRecord)
{
    // adds each object (record) to a temporary sorted list
    // sorted numerically by friend score
    sortedListByScore.InsertIntoList(friendRecord, 1);
}

void TopThreeFriendScores::printTopThreeScores(FriendRecord friendRecord)
{
    int counter = 1;
    
    // the person who's friendScores are all relative to
    cout << friendRecord.firstName << " " << friendRecord.lastName << endl;
    
    sortedListByScore.setCurrentToHead();
    
    while(sortedListByScore.getCurrent(FR))
    {
        // prints only the top three (if they exist)
        // will not print friendshipScores of 0
        // there should be no friendship scores of zero, but this is just a safety check
        if((FR.friendshipScore != 0) && (counter < 4))
        {
            cout <<"      #" << counter <<".  " << left << setw(9) << FR.firstName << " " << left << setw(13) << FR.lastName << "  " << "Score:  " << FR.friendshipScore << endl;
            
            counter++;
        }
        
        sortedListByScore.incrementCurrent();
        
    }
    
    cout << endl;
    
    // deletes and clears the temporary sorted linked list
    // this is needed
    sortedListByScore.deleteList();
}





#endif /* TOPTHREEFRIENDSCORES_H */

