#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h> 
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

struct ll *insert_back(struct ll *front, int num, int posit);
struct ll *insert_front(struct ll *front, int num, int posit);
int search(struct ll *front, int val);
void print(struct ll *front);

struct ll *create_node(int num, int posit);

struct ll *create_node(int num, int posit){

    struct ll *temp;

    temp = (struct ll *)malloc(sizeof(struct ll));
    temp->data = num;
    temp->position = posit;
    temp->next = NULL;

    return temp;
}

struct ll *insert_front(struct ll *front, int num, int position){
    struct ll *temp = create_node(num, position);
    temp->next = front;
    return temp;
}


int search(struct ll *front, int val){
    
    for(int i = 1; i <= tam_ranked; i++){
    
        if (front->position == val){ 
            return front->data;
            
        }

        front = front->next;
    }

    return 99; 
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

struct ll *inserting(struct ll *rank, int tipo, int tam){
    string points_string;
    vector<int> points_int{};
    int aux = tam, res = -1;
    getline(cin, points_string);
    points_int = divide(points_string);
    

    if(tipo == 1){
        tam_ranked = tam;
        int posi_r = 1;

        for (const auto &point : points_int){
            if(point != res){ 
                rank = insert_front(rank, point, posi_r);
                res = point;
                posi_r++;
                aux--;
    
            }
            else if(point == res){
                tam_ranked--;
                
            } 
            
        }
        
    }else{
        tam_player = tam;
        int posi_r = 1;
        for (const auto &point : points_int){
            if(point != res){ 
                rank = insert_front(rank, point, posi_r);
                res = point;
                posi_r++;
                aux--;
    
            }
            else if(point == res){
                tam_player--;
            } 
            
        }
    }
    
    return rank;
}

int compare(int a, int b, int i){
    

    if(a > b){
        if(i == 1){
            return 1;
        }
        return 0;
    }
    else if(a == b){
        return 2;
    }
    else if(a < b){
        int x = 3;
        return x;
    }
    return 0;
}



vector<int> verifica(struct ll *ranked, struct ll *player){

    int aux_ranked, aux_player;
    vector<int> pos_player;
    int r;
    
    
    for(int j = 1; j <= tam_player; j++){
        aux_player = search(player, j);
        
        for(int i = tam_ranked; i > 0; i--){
            aux_ranked = search(ranked, i);
            r = compare(aux_player, aux_ranked, i);

            if(r == 1){ 
                pos_player.push_back(1);
                i = 0;
                break;
            }
            if(r == 2){ 
                pos_player.push_back(2);
                i = 0;
                break;
            }
            else if(r == 3){
                pos_player.push_back(3);
                i = 0;
                break;
            }
            
        }
    
    }    

    
    return pos_player;
}



int main(void){

    struct ll *ranked, *player;
    ranked = NULL;
    player = NULL;
    
    
    string num = "3"; 
    vector<int> solution;

    getline(cin, num);
    int m = stoi(num);
    ranked = inserting(ranked, 1, m);
    getline(cin, num);
    int n = stoi(num);
    player = inserting(player, 2, n);
    solution = verifica(ranked, player);
    
    for (const auto &p : solution) {
        cout << p;
    }
    return 0;
}