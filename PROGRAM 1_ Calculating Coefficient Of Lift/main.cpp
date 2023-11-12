#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {
    string fileName;
    vector<double> FPAngle;
    vector<double> COLift;
    double userInput;
    double result;
    string choice;

    fileName = argv[1];
    readData(fileName, FPAngle, COLift);

    // cout << "Enter a flight-path angle: " <<
    cin >> userInput;
    // cout << userInput << endl;
    interpolation(userInput, FPAngle, COLift);

    choice = "Yes";
    while(choice == "Yes"){
        cin >> userInput;
        result = interpolation(userInput, FPAngle, COLift);
        cout << result << endl;
        cin >> choice;
    }

    return 0;
}

void readData(const string &fileName, vector<double> &FPAngle, vector<double> &COLift){
    ifstream inFS;
    double angle;
    double lift;

    inFS.open(fileName);

    if(!inFS.is_open()){
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    while(inFS >> angle >> lift){
        FPAngle.push_back(angle);
        COLift.push_back(lift);
    }

    inFS.close();
}

double interpolation(double userInput, const vector<double> &FPAngle, const vector<double> &COLift){
    double inter;

    for(unsigned int i = 0; i < FPAngle.size(); ++i){
        if(userInput == FPAngle.at(i)){
            return COLift.at(i);
        }
    }

    for(unsigned int i = 1; i < FPAngle.size(); ++i){
        if((FPAngle.at(i-1) < userInput) && (userInput < FPAngle.at(i))){
            inter = COLift.at(i-1) + ((userInput - FPAngle.at(i-1))/(FPAngle.at(i) - FPAngle.at(i-1))) * (COLift.at(i) - COLift.at(i-1));
        }
    }
    return inter;
}

bool isOrdered(const vector<double> &FPAngle){
    for(unsigned int i = 1; i < FPAngle.size(); ++i){
        if(FPAngle[i] < FPAngle[i-1]){
            return false;
        }
    }
    return true;
}

// void reorder(vector<double> &FPAngle, vector<double> &COLift){
    
// }