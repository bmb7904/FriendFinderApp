/*
 ************************* FRIEND FINDER APP *****************************
 *
 * This program will take in data for a person, their name, interests, and the
 * importance of those interests as a numerical value
 *
 * It will create records for each person and store the information
 *
 * The program will then sort & compare these records of people and output which of the
 * people have the most in common by comparing their interests
 *
 * Each person must have exactly 5 interests. This is hard coded.
 *
 * Programmer and Author: Brett Bernardi
 * December 7, 2019
 *************************************************************************
 */

#include <iostream>
#include <string.h>
#include "FriendRecord.h"
#include "FriendSortedList.h"
#include "FriendFinder.h"

using namespace std;

int main()
{
    // A sorted linked list that holds friend records
    FriendSortedList friendList;
    // a friend record object
    FriendRecord FR;
    // a friend record object
    FriendRecord FR2;

    // creates FriendFinder object named finderApp
    // this class contains many of the main functions for the app
    FriendFinder finderApp;

    // reads in data from the file, creates a FriendSortedLinkedList
    // This FriendSortedLinkedList is passed by reference
    // thus, we can name the object from the main
    finderApp.readDataInFile(friendList);

    // Takes the FriendSortedLinkedList calculates matching friends and prints the results
    finderApp.compareAndPrint(FR,FR2,friendList);

    return 0;
}
