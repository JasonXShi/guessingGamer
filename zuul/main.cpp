/*
Kevin Men
Zuul
12/4/17
An adventure game where the player is a character named Yasuo in the League of Legends world known as Runeterra
 */
#include <map>
#include <iostream>
#include "room.h"
#include <vector>
#include <iterator>
#include <cstring>

using namespace std;
//win condition: player has both Infinity Edge AND Phantom Dancer
//lose condition: player either goes to Ionia or picks up Rabadon's Deathcap
//checks if the player has won
bool winCondition(vector<item*> inventory){
  int itemCount = 0;
  //has both Phantom Dancer and Infinity Edge
  for(vector<item*>::iterator it = inventory.begin(); it!=inventory.end(); ++it){
    if(strcmp((*it)->description, "Phantom Dancer") == 0){
      itemCount++;
    }else if(strcmp((*it)->description, "Infinity Edge") == 0){
      itemCount++;
    }
  }
  if(itemCount == 2){
    return true;
  }else { return false; }
}
//checks if the player has lost
bool loseCondition(room* current, room* ionia, vector<item*> inventory){
  //player is in ionia
  if(current == ionia){
    return true;
  }
  //player has deathcap
  for(vector<item*>::iterator it = inventory.begin(); it!=inventory.end(); ++it){
    if(strcmp((*it)->description, "Rabadon's Deathcap")==0){
      return true;
    }
  }
  return false;
}
//prints out the player's inventory
void printInventory(vector<item*> inventory){
  cout << "The following items are in your inventory:" << endl;
  for(vector<item*>::iterator it = inventory.begin(); it!=inventory.end(); ++it){
    cout << (*it)->description << endl;
  }
}

int main(){
  vector<room*> v;
  //inventory and search words
  vector<item*> inventory;
  char command[10];
  char direction[10];
  char itemName[50];    
  //creates items and rooms
  item* frozenMallet = new item("Frozen Mallet");
  item* infinityEdge = new item("Infinity Edge");
  item* deathcap = new item("Rabadon's Deathcap");
  item* phantomDancer = new item("Phantom Dancer");
  item* bloodThirster = new item("Bloodthirster");
  item* spiritVisage = new item("Spirit Visage");
  item* hourglass = new item("Zhonya's Hourglass");
  room* current;
  room* freljord = new room("ice hangs above your head...", "The Freljord");
  room* piltover = new room("tall buildings loom over you...", "Piltover");
  room* zaun = new room("a flash of light blinks before you...", "Zaun");
  room* shadowIsles = new room("an onslaught of shadows engulfs you...", "The Shadow Isles");
  room* noxus = new room("you notice a rare plant nearby, the Death Lotus...", "Noxus");
  room* ionia = new room("death is like the wind, always by your side...", "Ionia");
  room* conquerorsSea = new room("I don't know who's from this place...", "Conqueror's Sea");
  room* demacia = new room("It's time to face Demacian Judgement...SPIN TO WIN", "Demacia");
  room* shurima = new room("remains of an ancient power sleep here...", "The Shurima Desert");
  room* icathia = new room("you are in for quite the Icathian Surprise", "Icathia");
  room* guardiansSea = new room("your boat rocks as you chum the waters...", "Guardian's Sea");
  room* kumungu = new room("You will fear the wild...and the north", "Kumungu");
  room* bandleCity = new room("Was that a mushroom you just stepped on?", "Bandle City");
  room* bilgewater = new room("Fortune doesn't favor fools...", "Bilgewater");
  room* plagueJungles = new room("There's a monkey on a flying nimbus", "Plague Jungles");

  //adds exits and items to rooms
  freljord->addExit("EAST", piltover);
  freljord->addItem(frozenMallet);
  
  piltover->addExit("WEST", freljord);
  piltover->addExit("EAST", zaun);

  zaun->addExit("WEST", piltover);
  zaun->addExit("SOUTH", noxus);

  shadowIsles->addExit("SOUTH", conquerorsSea);

  noxus->addExit("NORTH", zaun);
  noxus->addExit("SOUTH", icathia);
  noxus->addItem(bloodThirster);

  ionia->addExit("SOUTH", guardiansSea);

  conquerorsSea->addExit("NORTH", shadowIsles);
  conquerorsSea->addExit("SOUTH", demacia);
  conquerorsSea->addItem(phantomDancer);

  demacia->addExit("NORTH", conquerorsSea);
  demacia->addExit("EAST", shurima);
  demacia->addItem(infinityEdge);

  shurima->addExit("WEST", demacia);
  shurima->addExit("EAST", icathia);
  shurima->addExit("SOUTH", kumungu);
  shurima->addItem(hourglass);

  icathia->addExit("WEST", shurima);
  icathia->addExit("NORTH", noxus);
  icathia->addExit("EAST", guardiansSea);

  guardiansSea->addExit("NORTH", ionia);
  guardiansSea->addExit("WEST", icathia);
  guardiansSea->addExit("SOUTH", bilgewater);

  kumungu->addExit("NORTH", shurima);
  kumungu->addExit("SOUTH", plagueJungles);
  kumungu->addExit("EAST", bandleCity);
  kumungu->addItem(spiritVisage);

  bandleCity->addExit("WEST", kumungu);
  bandleCity->addItem(deathcap);

  bilgewater->addExit("NORTH", guardiansSea);

  plagueJungles->addExit("NORTH", kumungu);

  
  //adds all rooms to the vector
  v.push_back(freljord);
  v.push_back(piltover);
  v.push_back(zaun);
  v.push_back(shadowIsles);
  v.push_back(noxus);
  v.push_back(ionia);
  v.push_back(conquerorsSea);
  v.push_back(demacia);
  v.push_back(shurima);
  v.push_back(icathia);
  v.push_back(guardiansSea);
  v.push_back(kumungu);
  v.push_back(bandleCity);
  v.push_back(bilgewater);
  v.push_back(plagueJungles);
  current = shurima;
  //introduction
  cout << "Welcome to zuul! Your name is Yasuo, a man fasley accused or murder." << endl;
  cout << "You are in a fictional land known as Runeterra, where you must collect items for your build" << endl;
  cout << "In order to win, you must complete your core build." << endl;
  cout << "Type GO to go to another room" << endl;
  cout << "Type GET to pick up an item" << endl;
  cout << "Type DROP to drop an item" << endl;
  cout << "Type QUIT to exit the game" << endl;
  //while the player has not won/lost
  while(!winCondition(inventory) && !loseCondition(current, ionia, inventory)){
      //displays room information
      cout << endl;
      cout << "You are in " << current->getName() << endl;
      cout << current->getDescription() << endl;
      cout << "The exits are:" << endl;
      current->displayExits();
      current->displayItems();
      printInventory(inventory);
      cout << endl;
      cout << "Enter a command" << endl;
      cin.getline(command, 10, '\n');
      if(strcmp(command, "GO") == 0){
	cout << "Enter the direction you wish to travel" << endl;
	cin.getline(direction, 10, '\n');
	//travels to another room based on the direction specified
	current->travel(direction, current);
      }else if(strcmp(command, "GET") == 0){
	cout << "Enter the name of the item you wish to pick up" << endl;
	cin.getline(itemName, 50, '\n');
	//adds the item into the inventory
	current->removeItem(itemName, inventory);
      }else if(strcmp(command, "DROP") == 0){
	cout << "Enter the name of the item you wish to drop" << endl;
	cin.getline(itemName, 50, '\n');
	//drops the item into the room
	current->dropItem(itemName, inventory);
      }else if(strcmp(command, "QUIT") == 0){
	//quites the program
	break;
      }else{
	cout << "Not a valid command" << endl;
	cout << "Type GO to travel to go to another room" << endl;
	cout << "Type GET to pick up an item" << endl;
	cout << "Type DROP to drop an item" << endl;
      }
    }//while loop
  if(winCondition(inventory)){
    cout << "Congratulations! You have won!" << endl;
    cout << "Now that you have completed your core build you are able to 1v9 carry the game" << endl;
  }else if(loseCondition(current, ionia, inventory)){
    cout << "You lose because you are trolling like the filthy yasuo main you are and have been reported x9" << endl;
  }
  
}//main method
