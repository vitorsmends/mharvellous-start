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
struct ll *insert_back(struct ll *front, int num, int posit);
struct ll *insert_front(struct ll *front, int num, int posit);
int search(struct ll *front, int val);
void print(struct ll *front);

struct ll *create_node(int num, int posit);

struct ll *create_node(int num, int posit){

    struct ll *temp;

    //Create temporary node
    temp = (struct ll *)malloc(sizeof(struct ll));
    temp->data = num;
    temp->position = posit;
    temp->next = NULL;

    return temp;
}

struct ll *insert_front(struct ll *front, int num, int position){
    //cout << "\npos: "<< position;
    struct ll *temp = create_node(num, position);
    temp->next = front;
    return temp;
}


int search(struct ll *front, int val){

    //Iterate through the linked list until we reach the last node
    /*
    while (front->next != NULL){
    cout << "\n" << front->data << "\n";
    
        if (front->position == val){ 
            cout << "\nencontrei na pos: " << front->position << " data: "<< front->data <<"\n";
            return front->data;
            
        }

        front = front->next;
    }*/
    
    for(int i = 1; i <= tam_ranked; i++){
        cout << "\n" << front->data << "\n";
    
        if (front->position == val){ 
            cout << "\nencontrei na pos: " << front->position << " data: "<< front->data <<"\n";
            return front->data;
            
        }

        front = front->next;
    }

    return 99; 
}

void print(struct ll *front, int tipo){
    //Iterate through the linked list until we reach the last node
    if(tipo == 1){
        //printf("\ntamanho ranked %d\n", tam_ranked);
        
    }
    else{
        //printf("tamanho player %d\n", tam_player);
    }
    while (front != NULL){
        printf("pos = %d ", front->position);
        printf("num = %d ", front->data);
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
                cout << "\n-\n";
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
                cout << "\n-\n";
            } 
            
        }
    }
    
    return rank;
}


vector<int> compare(struct ll *ranked, struct ll *player){
    cout << "\n----- ranked:  \n";
    print(ranked, 1);
    cout << "\n----- player:  \n";
    print(player, 2);
    int aux_ranked, aux_player;
    vector<int> pos_player;
    /*
    for(int i = 1; i <= tam_player; i++){
        aux_player = search(player, i);
        cout << "\ni = " << i << " num: " << aux_player;
        for(int j = tam_ranked; j > 0; j--){
            aux_ranked = search(player, j);
            cout << "\nj = " << j << " num: " << aux_ranked;
        }
    }*/
    
    int i_ranked, i_player;
    
    for(int j = tam_player; j > 0; j--){
        //cout << "\n-------- pos_player: "<< j<<"---------\n"; 
        i_player = search(player, j);
        
        for(int i = tam_ranked; i > 0; i--){
            
            //cout << "\ncomparando p = "<< i_player << " com r = "<< i_ranked<<"\n";
            
            //cout << "\n----pos_rank: "<< i<<"-----n/";
            i_ranked = search(ranked, i);
            //cout << "\n vez:"<< i<<"\n";
            if(i_player > i_ranked){ 
                //cout << "maior";
                if(i = 0){ 
                    pos_player.push_back(1);
                }
            }
            else if(i_player = i_ranked){
                //cout << "igual";
                pos_player.push_back(i);
            }
            else if(i_player < i_ranked){
                //cout << "é menor";
                pos_player.push_back(i+1);
            }
             
        }
    }    

    return pos_player;
}

/*
    for(int j = tam_player; j > 0; j--){
        //cout << "\n-------- pos_player: "<< j<<"---------\n"; 
        i_player = search(player, j);
        
        for(int i = tam_ranked; i > 0; i--){
            
            //cout << "\ncomparando p = "<< i_player << " com r = "<< i_ranked<<"\n";
            
            //cout << "\n----pos_rank: "<< i<<"-----n/";
            i_ranked = search(ranked, i);
            //cout << "\n vez:"<< i<<"\n";
            if(i_player > i_ranked){ 
                //cout << "maior";
                if(i = 0){ 
                    pos_player.push_back(1);
                }
            }
            else if(i_player = i_ranked){
                //cout << "igual";
                pos_player.push_back(i);
            }
            else if(i_player < i_ranked){
                //cout << "é menor";
                pos_player.push_back(i+1);
            }
             
        }
    }
    */

main(void){

    struct ll *ranked, *player;
    ranked = NULL; // An empty linked list
    player = NULL;
    
    
    string num = "3"; 
    vector<int> solution;
    getline(cin, num);
    int m = stoi(num);
    ranked = inserting(ranked, 1, m);
    getline(cin, num);
    int n = stoi(num);
    player = inserting(player, 2, n);
    print(ranked, 1);
    print(player, 2);
    solution = compare(ranked, player);
    cout << "tam: " << tam_ranked << "\n";
    for (const auto &p : solution) {
        cout << p;
    }

}