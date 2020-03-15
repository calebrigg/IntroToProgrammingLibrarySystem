#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////Function Prototypes
string removeName(string personsName[]);
int findName (string personsName[]);
void displayNames(string personsName[]);
void mainMenu(string personsName[]);
void selectOption(string personsName[]);
string getNames(string personsName[]);
void sortNames(string personsName[]);
//////////////////////////////////////////////////////////////////////^Function Prototypes^
////////////////////////////////////////////////////////////////////////////Main Function
const int size = 10;
int main()
{
string nameIn[size];
 mainMenu(nameIn);

}

void mainMenu(string personsName[]){   
	
	cout<<"\nPress a Key to continue........."<<endl;
	getch();
	system("cls");
	cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"XX"<<'\t'<<'\t'<<'\t'<<"Select an Option:"<<'\t'<<'\t'<<'\t'<<"  "<<"XX"<<endl;
    cout<<"XX----------------------------------------------------------------XX"<<endl;
    cout<<"XX"<<'\t'<<"(G)Get Names"<<'\t'<<"(S)Sort Names"<<'\t'<<"(D)Display Names"<<'\t'<<"  "<<"XX"<<endl;
    cout<<"XX"<<'\t'<<"(F)Find Name"<<'\t'<<"(R)Remove Name"<<'\t'<<"(Q)Quit Program"<<'\t'<<'\t'<<"  "<<"XX"<<endl;
    cout<<"XX"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"  "<<"XX"<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    	selectOption(personsName);
}


void displayNames(string personsName[]){
	for(int i=0;i<size;i++)
	if(personsName[i]!="")
		cout<<personsName[i]<<endl;
	
	mainMenu(personsName);
}
void selectOption(string personsName[]){
	bool running =true;
	char ch;
	//string nameIn[size];
		do {
			ch =getch();
			switch(ch){
			case 'g': getNames(personsName);break;
			case 'G': getNames(personsName);break;
			case 's': sortNames(personsName);break;
			case 'S': sortNames(personsName);break;
			case 'd': displayNames(personsName);break;
			case 'D': displayNames(personsName);break;
			case 'f': findName(personsName);break;
			case 'F': findName(personsName);break;
			case 'r': removeName(personsName);break;
			case 'R': removeName(personsName);break;
			case 'q': exit(0);break;
			case 'Q': exit(0);break;
			default: cout<<"Incorrect Input, Try Again:"<<endl;continue;
		}} while (running);
}
string getNames(string personsName[]){
	personsName = new string[size];
	string input;
	int x;
		cout<<"Enter 10 Names or 'quit' to Exit..."<<endl;
		for(int x=0; x<size; x++)
			{
			
			cout<<"Enter a Name: "<<endl;
			cin>>input;
			if (input == "quit") {exit(0);}
			personsName[x] = input;
		}
			mainMenu(personsName);	
		}
			
void sortNames(string personsName[]){
string temp;
	for (int i=0; i < size-1; i++)
	{		
		for (int j=0; j < (size-i-1); j++)
		{

		if (personsName[j] > personsName[j+1])
            {
                 temp = personsName[j];
                 personsName[j] = personsName[j+1];
                 personsName[j+1] = temp;
            }
    	}
	}cout<<endl<<"Your names are now ordered alphabetically."<<endl<<endl;;
mainMenu(personsName);
}

int findName (string personsName[]) {
string target;
int i, x=0;
cout<<"Enter the Name You Wish to Find or Input 'quit' to Exit..."<<endl;
cin>>target;
if (target=="quit") {exit(0);}
int pos=0;
for (int i=0; i<size; i++){
	
	if (personsName[i] == target) {
		cout<<"This name is located in position #"<<pos+1<<'.'<<endl;
		mainMenu(personsName);
		return pos;
	}
	if (personsName[i] == "") {
		pos--;
	}
	pos++;
	}
	cout<<"Name not found!"<<endl;
	mainMenu(personsName);
	return -1;
}

string removeName(string personsName[]){ 	
	string x; 
	cout<<"which name do you wish to remove? Or Enter 'quit' to exit"<<endl; 
	cin>>x;  
	if (x=="quit") {exit(0);}
	for (int i=0; i<size; ++i) 	{ 		
		if (personsName[i]== x) personsName[i]="";}
	mainMenu(personsName); }
