#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);

int main() {
   /* Type your code here. */
    vector<int> jerseyNums(5);
    vector<int> ratings(5);
    int i;

    for (i = 0; i < 5; ++i){
        cin >> jerseyNums.at(i);
        cin >> ratings.at(i);
    }

    for (i = 0; i < 5; ++i){
        cout << "Enter player " <<  i+1 << "'s jersey number: " << endl;
        //cin >> jerseyNums.at(i);
        //cout << jerseyNums[i] << endl;

        cout << "Enter player " << i+1 << "'s rating: " << endl;
        //cin >> ratings.at(i);
        //cout << ratings[i] << endl;
        cout << endl; 
    }

    cout << "ROSTER" << endl;
    for (i = 0; i < 5; ++i){
        cout << "Player " << i+1 << " -- Jersey number: " << jerseyNums.at(i) << ", Rating: " << ratings.at(i) << endl;
    }

    cout << endl;
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option: " << endl;
    char option;
    cin >> option;

    while (option != 'q'){
        if (option == 'o'){
            outputRoster(jerseyNums, ratings);
        }

        if (option == 'a'){
            addPlayer(jerseyNums, ratings);
        }

        if (option == 'd'){
            removePlayer(jerseyNums, ratings);
        }

        if (option == 'u'){
            updatePlayerRating(jerseyNums, ratings);
        }

        if (option == 'r'){
            outputPlayersAboveRating(jerseyNums, ratings);
        }

        cout << endl << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option: " << endl;
        cin >> option;
    }

   return 0;
}

void outputRoster(const vector<int> &jerseyNums, const vector<int> &ratings){
    cout << "ROSTER" << endl;
    for (unsigned int i = 0; i < jerseyNums.size(); ++i){
        cout << "Player " << i+1 << " -- Jersey number: " << jerseyNums.at(i) << ", Rating: " << ratings.at(i) << endl;
    }
}

void addPlayer(vector<int> &jerseyNums, vector<int> &ratings){
    int newjNum;
    int newRating;

    cout << "Enter another player's jersey number: " << endl;
    cin >> newjNum;
    jerseyNums.push_back(newjNum);

    cout << "Enter another player's rating: " << endl;
    cin >> newRating;
    ratings.push_back(newRating);
}

void removePlayer(vector<int> &jerseyNums, vector<int> &ratings){
    int removedNum;

    cout << "Enter a jersey number: " << endl;
    cin >> removedNum;

    for (unsigned int i = 0; i < jerseyNums.size(); ++i){
        if (removedNum == jerseyNums.at(i)){
            jerseyNums.erase(jerseyNums.begin() + i);
            ratings.erase(ratings.begin() + i);
        }
    }
}

void updatePlayerRating(const vector<int> &jerseyNums, vector<int> &ratings){
    int jerseyNumber;
    int newRatingNum;

    cout << "Enter a jersey number: " << endl;
    cin >> jerseyNumber;

    cout << "Enter a new rating for player: " << endl;
    cin >> newRatingNum;

    for (unsigned int i = 0; i < jerseyNums.size(); ++i){
        if (jerseyNumber == jerseyNums.at(i)){
            ratings.at(i) = newRatingNum;
        }
    }
}

void outputPlayersAboveRating(const vector<int> &jerseyNums, const vector<int> &ratings){
    int userRating;

    cout << "Enter a rating: " << endl << endl;
    cin >> userRating;

    cout << "ABOVE " << userRating << endl;
    for (unsigned int i = 0; i < jerseyNums.size(); ++i){
        if (ratings.at(i) > userRating){
            cout << "Player " << i+1 << " -- Jersey number: " << jerseyNums.at(i) << ", Rating: " << ratings.at(i) << endl;
        }
    }
}