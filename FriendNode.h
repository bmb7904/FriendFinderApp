/*
 * An object of this class will be a node that holds another object (A friendRecord object)
 */
#ifndef FRIENDNODE_H
#define FRIENDNODE_H

#include "FriendRecord.h"

using namespace std;

class FriendNode
{
            public:
                FriendRecord friendRecord;
                FriendNode *next;
                FriendNode(FriendRecord fr);
                ~FriendNode();
    
            private:  
                
    
};

FriendNode::FriendNode(FriendRecord fr)
{
    friendRecord = fr;
    next = NULL;
}

FriendNode::~FriendNode()
{
    
}

#endif /* FRIENDNODE_H */

