#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s){
   string flippedVersion;

   if(s.size() <= 1){
      return;
   }
   else{
      flippedVersion = s.substr(1, s.size() - 2);
      flipString(flippedVersion);
      s = s.back() + flippedVersion + s.front();
   }
}

