/*Kevin Men
9/15/17
Palindrome
Allows the user to input a string and checks if it is a palindrome
C++
 */
#include <iostream>
using namespace std;
int main(){
  //variables to keep track of char arrays
  bool isPalindrome = true;
  char inputString[80];
  char compareString[80];
  cin.get(inputString, 80);
  //how long the string is
  int count = 0;
  for(int i = 0; i < 80;i++){
    if(inputString[i] == '\0'){
      break;
    }else{
      //turns all uppercase letters into lower case
      if('A' <=  inputString[i] && inputString[i] <='Z'){
	inputString[i] = inputString[i] - 'A' + 'a';
      }
      //adds all the LETTERS into a char array
      if('a' <=  inputString[i] && inputString[i] <= 'z'){
      compareString[count]= inputString[i];
      count++;
    }
    }
  }
  //inverse of the string
  char inverseString[count];
  for(int i = 0; i < count; i++){
    inverseString[count-1-i] = compareString[i];
  }
  //checks if the string is equals to the inverse of the string
  for(int j = 0; j < count; j++){

    if(compareString[j] == inverseString[j]){
      
    }else{
      isPalindrome = false;
      break;
  }
  }
  //prints out if the string is a palindrome or not
    if(isPalindrome == true){
      cout << "Is a palindrome" << endl;
      
    }else {
      cout << "Not a palindrome" << endl;
    }
    
}
