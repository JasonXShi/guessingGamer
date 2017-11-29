/*
Kevin Men
Zuul
11/26/17
An adventure game
 */
#include <map>
#include <iostream>
#include "room.h"
#include "item.h"
#include <vector>
#include <iterator>
#include <cstring>

using namespace std;

/*struct item{
  const char* description[50];
};*/

bool winCondition(vector<item*> inventory){
  int itemCount = 0;
  for(vector<item*>::iterator it = inventory.begin(); it!=inventory.end(); ++it){
    if(strcmp((it)->description, "Phantom Dancer") == 0){
      itemCount++;
    }else if(strcmp((it)->description, "Infinity Edge") == 0){
      itemCount++;
    }
  }
  if(itemCount == 2){
    return true;
  }else { return false; }
}

int main(){
  bool win = false;
  vector<room*> v;
  vector<item*> inventory;
  item* frozenMallet = new item("Frozen Mallet");
  item* infinityEdge = new item("Infinity Edge");
  item* deathcap = new item("Rabadon's Deathcap");
  item* phantomDancer = new item("Phantom Dancer");
  item* bloodThirster = new item("Bloodthirster");
  item* spiritVisage = new item("Spirit Visage");
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

  freljord.addExit("EAST", piltover);
  freljord.addItem(frozenHeart);
  
  piltover.addExit("WEST", freljord);
  piltover.addExit("EAST", zaun);

  zaun.addExit("WEST", piltover);
  zaun.addExit("SOUTH", noxus);

  shadowIsles.addExit("SOUTH", conquerorsSea);

  noxus.addExit("NORTH", zaun);
  noxus.addExit("SOUTH", icathia);
  noxus.addItem(bloodThirster);

  ionia.addExit("SOUTH", guardiansSea);

  conquerorsSea.addExit("NORTH", shadowIsles);
  conquerorsSea.addExit("SOUTH", demacia);
  conquerorsSea.addItem(phantomDancer);

  demacia.addExit("NORTH", conquerorsSea);
  demacia.addExit("EAST", shurima);
  damacia.addItem(infinityEdge);

  shurima.addExit("WEST", demacia);
  shurima.addExit("EAST", icathia);
  shurima.addExit("SOUTH", kumungu);

  icathia.addExit("WEST", shurima);
  icathia.addExit("NORTH", noxus);
  icathia.addExit("EAST", guardiansSea);

  guardiansSea.addExit("NORTH", ionia);
  guardiansSea.addExit("WEST", icathia);
  guardiansSea.addExit("SOUTH", bilgewater);

  kumungu.addExit("NORTH", shurima);
  kumungu.addExit("SOUTH", plagueJungles);
  kumungu.addExit("EAST", bandleCity);
  kumungu.addItem(spiritVisage);

  bandleCity.addExit("WEST", kumungu);
  bandleCity.addItem(deathcap);

  bilgewater.addExit("NORTH", guardiansSea);

  plagueJungles.addExit("NORTH", kumungu);
		  

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
  cout << "Welcome to zuul! Your name is Yasuo, a man fasley accused or murder." << endl;
  cout << "You are in a fictional land known as Runeterra, where you must collect items for your build" << endl;
  cout << "In order to win, you must complete your core build." << endl;
  cout << "Type GO followed by the direction you wish to travel to go to another room" << endl;
  cout << "Type GET to pick up an item" << endl;
  cout << "Type DROP to drop an item" << endl;
  cout << "Type HELP for the commands" << endl;
    while(!wincondition(inventory)){
      
    }//while loop
  
}//main method
