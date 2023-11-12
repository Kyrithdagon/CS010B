#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   vector<int> integerList;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()){
      cout << "Error reading " << inputFile << endl;
      return 1;
   }
   // Read in integers from input file to vector.
   int integers;
   char trash;
   while (inFS >> integers){
      integerList.push_back(integers);
      inFS >> trash;
   }
   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   int sum = 0;
   int avg = 0;
   int cnt = 0;
   for(unsigned int i = 0; i < integerList.size(); ++i){
      sum = sum + integerList.at(i);
      ++cnt;
   }
   avg = sum/cnt;
   // Convert each value within vector to be the difference between the original value and the average.
   for(unsigned int i = 0; i < integerList.size(); ++i){
      integerList[i] = integerList[i] - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()){
      cout << "Error reading " << outputFile << endl;
      return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned int i = 0; i < integerList.size(); ++i){
      if(integerList.size() == i+1){
         outFS << integerList.at(i);
      }
      else{
         outFS << integerList.at(i) << ", ";
      }
   }
   // Close output stream.
   outFS.close();

   return 0;
}