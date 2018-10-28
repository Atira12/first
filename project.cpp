#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <jsoncpp/json/json.h>
using namespace std;
using namespace Json;

int normal_decksize = 10;
int fulldeck_monster = 10 ;// used for better structure . just swap 2 in for loop with monster_full
int fulldeck_spells = 5;

int deck_build_menu();
int main_menu();
class Game
{
public:
  int hand[100];
  int grave[100];


};
class Player
{
public:
  string name;
  int HP = 40;
  int mana;


};
class Deck
{
public:
   int deck_player[20];// we will call them only on id of cards

}; // array of cards for each player
class cards_magic
{
public:

 string name;
 int cost;
 int attack;
 int effect;
 int id;
};
class cards_monster
{
public:
  string name;
  int cost;
  int att;
  int id;
  
};
Player player_state[2];
Deck play_deck[2];
cards_monster monster[10];
cards_magic magic[10];

int deck_shuffler()
{
  
 random_shuffle(&play_deck[0].deck_player[0],&play_deck[0].deck_player[9]);
 random_shuffle(&play_deck[1].deck_player[0],&play_deck[1].deck_player[9]);
 //deck shuffler using include <algorithm> and random_shuffler
  return 0;
}

int deck_save()
{
  int save_counter=0;
  
  system("cd /home/wamu/Desktop/Decks/");
  ofstream write_player1("/home/wamu/Desktop/Decks/"+player_state[0].name,fstream::app); // adding and connecting to file Cards.json. Note : Edit path in future
  ofstream write_player2("/home/wamu/Desktop/Decks/" +player_state[1].name,fstream::app);
  while(save_counter < normal_decksize)
  {

   write_player1 << play_deck[0].deck_player[save_counter]<<endl;
   write_player2 << play_deck[1].deck_player[save_counter]<<endl;
   save_counter++;
 }
 cout <<"data saved "<< endl;
 write_player2.close();
 write_player1.close();  
 return 0;
}

int deck_saving_menu(int finish_choice)
{

 switch(finish_choice){
  case 1:
     deck_save();// add new function . Pass trough case 2 and then start game in main_menu
     //add game functions to start game and field and hand
     break;
     case 2:
     deck_save();// save game and quit . Name of file and etc.
     break;
   }
   return 0;
 }
 int card_picker()
 {
  int card_choice;
  int card_counter;
  int player_counter = 0;
  int picker_finish_choice;
  do{
    cout << "Pick a name";
    cin >> player_state[player_counter].name;
  for(card_counter = 0;card_counter < normal_decksize;card_counter++) // we can freely change the normal_decksize (at will)
  {
    do{
      cout << "Chose by ID:"<<endl;
      cin >>card_choice; 
      if( card_choice < -1 * fulldeck_spells || card_choice > fulldeck_monster-1)
      {
        cout <<"Invalid choice pls try again"<<endl;
      }
      }while(card_choice <  -1 * fulldeck_spells || card_choice > fulldeck_monster-1); // if cards expand we can add change directly to fulldeck

      play_deck[player_counter].deck_player[card_counter] = card_choice;
    }
    player_counter++;
  }while(player_counter <= 1);
  system("clear");
  for(int i = 0;i < 10;i++){
   int some = play_deck[0].deck_player[i];
   cout << "card:"<<some<<endl;
 }
 deck_shuffler();
 cout << "1. Save & Play"<<endl;
 cout << "2. Save & Quit"<<endl;
 cin >>picker_finish_choice;
 deck_saving_menu(picker_finish_choice);


 return 0;
}



int build_deck_shower()
{
  int deckshow_counter=0;
  

  cout << "---------------------------------MONSTERS----------------------------------------"<<endl;
  for(deckshow_counter = 0;deckshow_counter < fulldeck_monster;deckshow_counter++)
  {
    cout << "/ID:"<< monster[deckshow_counter].id;
    cout << "/Name:"<<monster[deckshow_counter].name;
    cout << "/Cost:"<<monster[deckshow_counter].cost;
    cout <<"/Attack:"<< monster[deckshow_counter].att<<endl;
    //cout <<"----------------------------------------------------------------"<<endl; --> looks better without them but the option is here
  }
  cout << "--------------------------------SPELLS---------------------------"<<endl;
  for(deckshow_counter=0;deckshow_counter< fulldeck_spells;deckshow_counter++)
  {
    cout << "/ID:"<< magic[deckshow_counter].id;
    cout << "/Name:"<<magic[deckshow_counter].name;
    cout << "/Cost:"<<magic[deckshow_counter].cost;
    cout <<"/Attack:"<< magic[deckshow_counter].attack;
    cout <<"/Effect" << magic[deckshow_counter].effect<<endl;
  //cout <<"------------------------------------------------------------------"<<endl;
  }
  
  
  card_picker();
  return 0;
}
int card_load_magic()
{
  int magic_full = 20;
  int counter_magic =0;
  string num_mag;

ifstream ifile("/home/wamu/Desktop/Cards.json"); // adding and connecting to file Cards.json. Note : Edit path in future
Json::Reader reader;
Json::Value obj;
reader.parse(ifile,obj);


for(counter_magic;counter_magic < fulldeck_spells;counter_magic++)
{
  num_mag = to_string(counter_magic); 
  magic[counter_magic].name = obj["Magic"][num_mag]["Name"].asString();
  magic[counter_magic].cost = obj["Magic"][num_mag]["cost"].asInt();
  magic[counter_magic].attack = obj["Magic"][num_mag]["attack"].asInt();
  magic[counter_magic].effect = obj["Magic"][num_mag]["effect"].asInt();
  magic[counter_magic].id = obj["Magic"][num_mag]["id"].asInt();
}

return 0;
}
int card_load_monsters()
{

  int counter_monster = 0;
  string num_m;

ifstream ifile("/home/wamu/Desktop/Cards.json"); // adding and connecting to file Cards.json. Note : Edit path in future
Json::Reader reader;
Json::Value obj;
reader.parse(ifile,obj);


for(counter_monster;counter_monster < fulldeck_monster;counter_monster++)
{
  num_m = to_string(counter_monster);
  monster[counter_monster].name = obj["Monster"][num_m]["Name"].asString();
  monster[counter_monster].cost = obj["Monster"][num_m]["cost"].asInt();
  monster[counter_monster].att = obj["Monster"][num_m]["attack"].asInt();
  monster[counter_monster].id = obj["Monster"][num_m]["id"].asInt();
}

return 0;
}

int deck_switch(int hold_deck )
{
  switch(hold_deck)
  {
    case 1:
    build_deck_shower();
    break;
    case 2:
    break;
    default:
    cout << "Incorrect answer"<<endl;
    deck_build_menu();
    break;
  }
  return 0;
}
int deck_build_menu()
{
 int deck_build_answer;
  //system("clear"); // change for windows to cls for cmd command
 cout << "1. Build Own Deck"<<endl;
 cout << "2. Chose Deck" << endl;
 cout << "Choose option:";
 cin >> deck_build_answer;
 deck_switch(deck_build_answer);
}

int first_switch(int hold_first)
{
  switch(hold_first)
  {
    case 2:
    deck_build_menu();
    break;
    default:
    cout << "Incorrect Choice" << endl;
    main_menu();
    break;
  }
  return 0;
}


int main_menu()
{

  int answer;
system("clear"); // change for windows to cls
cout << "1. Play"<<endl;
cout << "2. Build Deck"<< endl;
cout << "Enter Choice"<<endl;
cin >> answer;
first_switch(answer);

return 0;
}

int main()
{

  card_load_monsters();
  card_load_magic();
  main_menu();
  return 0;
}