/* Application Name : Console Dictionary.
   Version: 3.0
   Author : CyberPhoenix
   A c++ project based on file handling, its a non-GUI application that can search a word of user's choice and display its meaning. 
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Data
{
public:
	string Word,Meaning;
	void getData(string text)
	{
		string word,meaning;
		char raw[100000];
		int pos;
		for(int i = 0 ; i < text.length() ; i++)
		{
			if(text[i] == ' ')
			{
				raw[i] = '\0';
				word = raw;
				pos = i;
				break;
			}
			else
			{
				raw[i] = text[i];
			}
		}
		int j,k;
		for(j = pos,k = 0 ; j < text.length() ; j++,k++)
		{
			raw[k] = text[j];
		}
		raw[k] = '\0';
		meaning = raw;
		Word = word;
		Meaning = meaning;
	}
};
Data D[200000];
int total;
void readAll()
{
	ifstream ifile;
	string filename,extension = ".TXT";//if you are running this program in visual studio c++ then modify ".TXT" into ".txt".
	string text;
	int i=0;
	for(char alfa = 'A' ; alfa <= 'Z' ; alfa++)
	{
		filename=alfa+extension;
		ifile.open(filename,ios::in);
		while(getline(ifile,text))
		{
			D[i].getData(text);
			i++;
			/////////////////////Progress Indicator.
			if(i%109 == 0)
			{
				int percentage = (i*100)/182684;//total 182684 number of words are there in this dictionary.
				system("clear");//change this to "cls" if using visual studio c++.
				cout<<"\033[0;94m";
				cout<<"\n                              Loading files into the Memory. Please wait";
				cout<<"\n                              Total Progress..."<<endl;
				cout<<"\n\t====================================================================================================="<<endl<<"\t";
				for(int j = 0 ; j <= 100 ; j++)
				{
					if(j <= percentage)
					{
						cout<<"\u25A0";
					}
					else
					{
						cout<<" ";
					}
				}
				cout<<"\t"<<"[ "<<percentage<<" % ]";
				cout<<"\n\t====================================================================================================="<<endl;
				cout<<"\033[0m";
			}
		}
		ifile.close();
	}
	total = i;
	cout<<"\033[0;92m";
	cout<<"\n                              Data loaded into the memory successfully.";
	cout<<"\033[0m";
}
string toLower(string text)
{
	for(int i = 0; i < text.length() ; i++)
	{
		if(65 <=int(text[i]) && 90 >= int(text[i]))
		{
			text[i] = char(int(text[i])+32);
		}
	}
	return text;
}
bool search(string key)
{
	bool flag = false;
	bool done = true;
	key = toLower(key);
	string word;
		for(int i = 0 ; i < total ; i++)
		{
			word = toLower(D[i].Word);
				if(word.compare(key) == 0)
				{
					if(done)
					{
						done=false;
						cout<<"\033[0;92m";
						cout<<" WORD : "<<D[i].Word<<endl;
						cout<<"\033[0;91m";
						cout<<"========================================================================================================================"<<endl;
						cout<<"\033[0;94m";
						cout<<" MEANING :"<<endl;
					}
					cout<<D[i].Meaning<<endl;
					flag = true;
				}
		}
	return flag;
}
void saveHistory(string text)
{
	ofstream ofile;
	ofile.open("History.txt",ios::out|ios::app);
	ofile<<text<<endl;
	ofile.close();
}
void clearHistory()
{
	ofstream ofile;
	ofile.open("History.txt",ios::out);
	ofile.close();
}
bool history()
{
	bool flag = false;
	ifstream ifile;
	ifile.open("History.txt",ios::in);
	string line;
	while(ifile>>line)
	{
		cout<<endl;
		cout<<"\t"<<line<<endl;
		flag = true;
	}
	ifile.close();
	return flag;
}
int inputInteger(string message)
{
	int input;
	for (;;) 
	{
		cout<<"\033[0;92m";
		if (cin >> input) 
		{
				return input;
				break;
		}
		else
		{
			cout<<"\033[0m";
			cout<<"\033[0;91m";
			cout<<message<<endl;
			cout<<"\033[0m";
			cin.clear();
			cin.ignore(512, '\n');
		}
	}
}

int main()
{
	readAll();
	cout<<"\nPress Enter to continue...";
	cin.get();
	system("clear");//change this to "cls" if using visual studio c++.
	int choice;
	while(1)
	{
	cout<<"\033[0;94m"; 
	cout<<"\n||====================================================================================================================||";
	cout<<"\n||                                              D I C T I O N A R Y                                                   ||";
	cout<<"\n||====================================================================================================================||";
	cout<<"\n||                                                                                                                    ||";
	cout<<"\n||                                     A console based Dictionary Application                                         ||";
	cout<<"\n||                                                                                                                    ||";
	cout<<"\n||     Created by :           CyberPhoenix                                                                            ||";
	cout<<"\n||                                                                                                                    ||";
	cout<<"\n||     Date Created :         10:50pm 24 Jan 2019                                                                     ||";
	cout<<"\n||                                                                                                                    ||";
	cout<<"\n||     This code is created and compiled using G++ on LINUX Platform, running this program on Visual Studio           ||";
	cout<<"\n||     will require some Minor Changes which are already given in the source code.                                    ||";
	cout<<"\n||     CAUTION : This Program will never work on TurboC++/TurboC/Borland C++. ;-P                                     ||";
	cout<<"\n||                                                                                                                    ||";
	cout<<"\n||====================================================================================================================||";
	cout<<"\n||     1. Word Lookup                                                                                                 ||";
	cout<<"\n||     2. View Search history                                                                                         ||";
	cout<<"\n||     3. Exit                                                                                                        ||";
	cout<<"\n========================================================================================================================";
	cout<<"\033[0;96m";
	cout<<"\n  Enter your choice : ";
	cout<<"\033[0;91m";
	choice = inputInteger("Please Enter a Valid Integer : ");
	cout<<"\033[0m";
	string input;
	switch(choice)
	{
	case 1:
			int decision;
			do
			{   
				cout<<"\033[0;92m";
				cout<<"\n\n Enter your word : ";
				cout<<"\033[0m";
				cin>>input;
				saveHistory(input);
				cout<<endl;
				if(search(input))
				{
					cout<<"\033[0;92m";
					cout<<"\n===================================  W O R D    F O U N D    S U C C E S S F U L L Y  ==================================";
					cout<<"\033[0m";
				}
				else
				{
					cout<<"\033[0;91m";
					cout<<"\n===========================================  W O R D    N O T    F O U N D  ============================================";
					cout<<"\033[0m";
				}
				cout<<"\033[0;96m";
				cout<<"\nSearch Again ? [1/0] :";
				decision = inputInteger("Please Enter a Valid Integer : ");
				cout<<"\033[0m";
			}while(decision == 1);
			break;
	case 2: 
			int flag;
			cout<<"\033[0;93m";
			cout<<"\n||====================================================================================================================||";
			cout<<"\nYou Have searched the following words."<<endl;
			if(history())
			{
				cout<<"\nDo you want to clear your history ? [1/0]: ";
				flag = inputInteger("Please Enter a Valid Number !!!");
				if(flag==1)
				{
					clearHistory();
				}
			}
			else
			{
				cout<<"\nSorry There are No Recent Searches.\n";
				cin.get();
				cin.get();
			}
			cout<<"\033[0m";
			break;
	case 3: exit(0);
			break;
	default: cout<<"Invalid choice !!!";
				cin.get();
				cin.get();
	}
	}
	return 0;
}