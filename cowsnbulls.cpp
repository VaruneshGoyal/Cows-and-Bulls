#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int number_of_words_in_list = 12478;

ifstream in("five.txt");
char words[number_of_words_in_list][5];
char answer[5];
string x, xcopy;
int cows=0, bulls=0;
int id;
string finalanswer = "AAAAA";

int main(){
	for(int i=0; i<number_of_words_in_list; i++){
		in>>answer;
		for(int j=0; j<5; j++){
			words[i][j] = answer[j];
		}
	}
	
	//cout<<finalanswer;
	cout<<"COWS and BULLS\nStart guessing 5 letter words!! (Type in Capital letters only)\n";
	

	char play='y';
	while(play == 'y'||play =='Y'){
		srand((int) time(0));
		id = rand()%number_of_words_in_list;
		//cout<<id;

		for(int j=0; j<5; j++){
			finalanswer[j] = words[id][j] ;
		}

		cout<<"Try\t\tWord guessed\t\tCows\tBulls\n";
		
		int tries = 1;
		while(bulls!=5 && tries<11){
			bulls = 0; cows = 0;
			cin>>x;
			xcopy = x;
			
			for(int j=0; j<5; j++){
				if(xcopy[j]==finalanswer[j]){
					bulls++;
					xcopy[j] = 1;
				}
			}
			//cout<<xcopy<<endl;
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					if(xcopy[i]==finalanswer[j]) {cows++; break;}
				}
			}
			cout<<tries<<"\t\t"<<x<<"\t\t\t"<<cows<<"\t"<<bulls<<endl;
			tries++;
		}
		if(bulls == 5) cout<<"Congrats you have correctly determined the word in "<<tries-1<<" tries!! "<<endl;
		else cout<<"Oops thats the number of tries you had. The correct word was "<<finalanswer<<"."<<endl;
		cout<<"Press 'Y' to play again : \t";
		cin>>play;
	}
	
	return 0;
}