/*
Kevin Men
Zuul
11/26/17
An adventure game
 */
#include <map>
#include <iostream>
#include "room.h"
#include <vector>
#include <iterator>

using namespace std;

struct item {
  char description[50];
};

int main(){
  bool win = false;
  vector<room*> v;
  cout << "Welcome to zuul!" << end;
  room current;
  room freljord = new room("ice hangs above your head...", "The Freljord");
  room piltover = new room("tall buildings loom over you...", "Piltover");
  room zaun = new room("a flash of light blinks before you...", "Zaun");
  room shadowIsles = new room("an onslaught of shadows engulfs you...", "The Shadow Isles");
  room noxus = new room("you notice a rare plant nearby, the Death Lotus...", "Noxus");
  room ionia = new room("death is like the wind, always by your side...", "Ionia");
  room conquerorsSea = new room("I don't know who's from this place...", "Conqueror's Sea");
  room demacia = new room("It's time to face Demacian Judgement...SPIN TO WIN", "Demacia");
  room shurima = new room("remains of an ancient power sleep here...", "The Shurima Desert");
  room icathia = new room("you are in for quite the Icathian Surprise", "Icathia");
  room guardiansSea = new room("your boat rocks as you chum the waters...", "Guardian's Sea");
  room kumungu = new room("You will fear the wild...", "Kumungu");
  room bandleCity = new room("Was that a mushroom you just stepped on?", "Bandle City");
  room bilgewater = new room("Fortune doesn't favor fools...", "Bilgewater");
  room plagueJungles = new room("There's a monkey on a flying nimbus", "Plague Jungles");

  freljord.addExit("EAST", piltover);
  //freljord.addItem(frozenHeart);
  
  piltover.addExit("WEST", freljord);
  piltover.addExit("EAST", zaun);

  zaun.addExit("WEST", piltover);
  zaun.addExit("SOUTH", noxus);
  //zaun.addItem(hextechGunblade);

  shadowIsles.addExit("SOUTH", conquerorsSea);

  noxus.addExit("NORTH", zaun);
  noxus.addExit("SOUTH", icathia);

  ionia.addExit("SOUTH", guardiansSea);

  conquerorsSea.addExit("NORTH", shadowIsles);
  conquerorsSea.addExit("SOUTH", demacia);

  demacia.addExit("NORTH", conquerorsSea);
  demacia.addExit("EAST", shurima);

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

  bandleCity.addExit("WEST", kumungu);

  bilgewater.addExit("NORTH", guardiansSea);

  plagueJungles.addExit("NORTH", kumungu);
		  

  v.push_back(freljord&);
  v.push_back(piltover&);
  v.push_back(zaun&);
  v.push_back(shadowIsles&);
  v.push_back(noxus&);
  v.push_back(ionia&);
  v.push_back(conquerorsSea&);
  v.push_back(demacia&);
  v.push_back(shurima&);
  v.push_back(icathia&);
  v.push_back(guardiansSea&);
  v.push_back(kumungu&);
  v.push_back(bandleCity&);
  v.push_back(bilgewater&);
  v.push_back(plagueJungles&);
  while(!winCondition(player){

    }//while loop
  
}//main method
