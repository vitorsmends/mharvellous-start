/*
   Title: Linked List
   Description: This program inserts a value into a linked list, searches for a value in a linked list, and prints the value(s) of the linked list
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h> //malloc
#include <stdlib.h>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;

struct ll
{
    int data;
    struct ll *next;
};

//Define linked list functions
struct ll *insert_back(struct ll *front, int num);
struct ll *insert_front(struct ll *front, int num);
int search(struct ll *front, int val);
void print(struct ll *front);

struct ll *create_node(int num);

struct ll *create_node(int num){

    struct ll *temp;

    //Create temporary node
    temp = (struct ll *)malloc(sizeof(struct ll));
    temp->data = num;
    temp->next = NULL;

    return temp;
}

struct ll *insert_front(struct ll *front, int num){

    struct ll *temp = create_node(num);
    temp->next = front;

    return temp;
}

struct ll *insert_back(struct ll *front, int num){

    struct ll *temp = create_node(num); //Create temporary node
    struct ll *begin = front;           //Store front of the linked list

    //Check if we are inserting into a empty or NULL list
    if (front == NULL)
        return temp;

    //Iterate through the linked list until we reach the last node
    while (front->next != NULL)
    {
        front = front->next;
    }

    //Insert temp into the list
    front->next = temp;

    return begin; // return the pointer to the front of the list
}

int search(struct ll *front, int val){

    //Iterate through the linked list until we reach the last node
    while (front->next != NULL)
    {

        if (front->data == val) // value was found in list return 1
            return 1;

        front = front->next;
    }

    return 0; // value was not found in list return 0
}

void print(struct ll *front)
{
    //Iterate through the linked list until we reach the last node

    while (front != NULL)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

struct ll *inserting_players(struct ll *rank, int num){
    int points;
    for (int i = 0; i < num; i++){
        scanf("%d", &points);
        rank = insert_back(rank, points);
    }
    
    print(rank);
    return rank;
}

struct ll *inserting_points(struct ll *player, int num){
    int points;
    for (int i = 0; i < num; i++){
        scanf("%d", &points);
        player = insert_back(player, points);
    }
    return player;
}

vector<int> divide(string text){

    text = text + " ";
    string space_delimiter = " ";
    vector<string> num_string{};
    vector<int> num_int{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        num_string.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    
    for (const auto &str : num_string) {
    int num;
    num = stoi(str);
    num_int.push_back(num);
    }
    
    return num_int;
   
}

    main(void){

        struct ll *ranked, *player;
        ranked = NULL; // An empty linked list
        player = NULL;
        int num;
        //start the input
        scanf("%d", &num);
        ranked = inserting_players(ranked, num);
        scanf("%d", &num);
        player = inserting_players(player, num);

    }