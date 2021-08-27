/*
pos ta ficando em 0;
consertar o contador;
o resto nao ta com problemas;
terminar função compare
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h> //malloc
#include <stdlib.h>
#include  <bits/stdc++.h>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;
int tam_ranked = 0,  tam_player = 0;


struct ll{
    int data;
    int position;
    struct ll *next;
};

//Define linked list functions
struct ll *insert_back(struct ll *front, int num);
struct ll *insert_front(struct ll *front, int num, int position);
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

struct ll *insert_front(struct ll *front, int num, int position){
    
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

void print(struct ll *front, int num)
{
    //Iterate through the linked list until we reach the last node
    if(num == 1){
        printf("tamanho %d\n", tam_ranked);
        
    }
    else{
        printf("tamanho %d\n", tam_player);
    }
    while (front != NULL){
        printf("pos: %d ", front->position);
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
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

struct ll *inserting(struct ll *rank, int num){
    string points_string;
    vector<int> points_int{};
    
    getline(cin, points_string);
    points_int = divide(points_string);
    
    if(num == 1){
        int cont_1 = 1;
        for (const auto &point : points_int){
            cout << cont_1;
            rank = insert_front(rank, point, cont_1);
            tam_ranked++;
            cont_1++;
        }
    }else{
        int cont_2 = 1;
            for (const auto &point : points_int) {
            rank = insert_front(rank, point, cont_2);
            tam_player++;
            cont_2++;
        }
    }
    
    return rank;
}


main(void){

    struct ll *ranked, *player;
    ranked = NULL; // An empty linked list
    player = NULL;
    string num;
    vector<int> points;
    
    //getline(cin, num);
    ranked = inserting(ranked, 1);
    //getline(cin, num);
    //player = inserting(player, 2);
    print(ranked, 1);
    //print(player, 2);

}