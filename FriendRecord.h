/*
 * Holds data as a record of a potential friend
 * Includes name, interests, interests value, and friendshipScore
 */

#ifndef FRIENDRECORD_H
#define FRIENDRECORD_H

#include <string.h>

using namespace std;

class FriendRecord
{
            public:
                string firstName;
                string lastName;
                string favorites[5];
                int favoritesValue[5];
                int friendshipScore;
                FriendRecord();
                ~FriendRecord();
                string nameForSorting();
                
                

            private:
};

// constructor
FriendRecord::FriendRecord()
{
    
}

// destructor
FriendRecord::~FriendRecord()
{
    
}

// returns the lastname and firstname of a particular friend as one string - no spaces
// this is used for the sorted list to order by alphabetical order
string FriendRecord::nameForSorting()
{
    return lastName + firstName;
}

#endif /* FRIENDRECORD_H */

