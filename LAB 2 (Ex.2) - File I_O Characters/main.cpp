#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string fileName, char ch);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string fileName, char ch){
   ifstream fileFS;
   int count = 0;
   char character;

   fileFS.open(fileName);

   if (!fileFS.is_open()){
      cout << "Error opening " << fileName << endl;
      exit(1);
   }

   while (fileFS.get(character)){
      if (character == ch){
         ++count;
      }
      // fileFS >> character;
   }

   fileFS.close();
   return count;
}
