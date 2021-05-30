#ifndef LIST
#define LIST

//when a client send a connection, it will create a client node
//prev is its previous node in linked list, link is its next node in linked list, name is the nickname of client
typedef struct ClientNode {
    int data;
    struct ClientNode* prev;
    struct ClientNode* link;
    char ip[16];
    char name[31];
} ClientList;

//create the new client node and add to the linked list in serve.c
ClientList *newNode(int sockfd, char* ip) {
    //request allocated memory to store client nodes
    ClientList *np = (ClientList *)malloc( sizeof(ClientList) );
    np->data = sockfd;
    np->prev = NULL;//initialize the previous node
    np->link = NULL;//initialize the link node
    //strncpy() is used to copy data from client node to np
    strncpy(np->ip, ip, 16);
    strncpy(np->name, "NULL", 5);
    return np;
}

#endif // LIST
