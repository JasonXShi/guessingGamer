#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int main(){
  map<char, int> precedence;
  precedence['^'] = 4;
  precedence['/'] = 3;
  precedence['*'] = 3;
  precedence['+'] = 2;
  precedence['-'] = 2;

  map<char, int> associativity;
  associativity['^'] = 0;
  associativity['/'] = 1;
  associativity['*'] = 1;
  associativity['+'] = 1;
  associativity['-'] = 1;
  
  char input[100];
  vector<char*> expression;
  cin.getline(input, 100, '\n');
  char* split;
  split = strtok(input, " ");
  while(split != NULL){
    expression.push_back(split);
    split =  strtok (NULL, " ");
  }
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    cout << *it << endl;
  }
}
