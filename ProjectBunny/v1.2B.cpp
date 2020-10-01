//
//1904 Project Bunny X
//28th Jun 2019
//Class Bunny
// ver 1 release 2B
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
#include "bunny.h"
using namespace std;

void spawn(Bunny judyHops[4000], int &leftoff, int bunnyYear); //function declaration aka prototype
void dump_bunniesObj(Bunny clone[4000]); //function declaration for object content dump
void clone_bunnies(Bunny object[4000]); //function declaration for initialization of bunny object
void increment_age(Bunny object[4000]); // increment by 1 year
void extinction_check(bool &JDGMNT_DAY, Bunny judyHops[4000], int &year,int &leftoff); // check for if all bunnies have died
void outToFile(); // display content of output.txt
int populationCount(Bunny judyHops[4000]); // object bunny population count
void population_cull(Bunny judyHops[4000],int alivePopulation, int &leftoff, int &dead); //
void plague_cull(Bunny judyHops[4000], int alivePopulation, int &leftoff);
void life_death (Bunny judyHops[4000], int bunnyYear, int &dead);
void bunnycounter(int &);
void adameve(Bunny judyHops[4000]);
void increment_age(Bunny object[4000], int &current_year);

int main ()
{	ofstream file;
	int leftoff = 4;
	Bunny judyHops[4000]; // instantiating Bunny class judyHops object
	bool JDGMNT_DAY = false;  // all_bunny_dead check flag
	int bunnyYear = 1; // bunny year starting point
	clone_bunnies(judyHops); //initialize Bunny class object
	int alivePopulation=0;
	srand(time(0));
	adameve(judyHops);
	int dead = 0;

	while (JDGMNT_DAY==false)
	//for (int i=0; i<15; i++)
	{
		outToFile();// list of bunny events - Lihann
		alivePopulation = populationCount(judyHops);
		//cout << "Bunny population at Bunny year " << bunnyYear << ":" << alivePopulation << " bunnies" << endl;
		file.open("output.txt",ios::app);
		//file << endl;
		file << "Bunny population at Bunny Year " << bunnyYear << ":" << alivePopulation << " bunnies" << endl;
		//file << "Bunny year: " << bunnyYear << endl;
		file.close();
		spawn(judyHops,leftoff, bunnyYear); // with exception to vampire bunnies do not spawn - Callum
		life_death(judyHops, bunnyYear, dead); // old age attrition including vampire bunnies life span at 50 - Zhang
		population_cull(judyHops, alivePopulation, leftoff, dead); // food shortage at POPULATION THRESHOLD and kills half of bunny population - Joshua
		plague_cull(judyHops, alivePopulation, leftoff); // Vampire bunnies infecting healthy bunny - Joshua
		file.open("output.txt", ios::app);
		file<< dead<< " bunnies have died"<< endl;
		file.close();
		dead = 0;
		extinction_check(JDGMNT_DAY,judyHops, bunnyYear, leftoff); // check if all bunnies dies
		increment_age(judyHops, bunnyYear); // increase living bunnies age by 1 at the of bunny year cycle for next coming 'year' - Kuan Yew //complete v1.0 29/6/19
		bunnyYear++; //bunny year increase by 1
		//cout << "Leftoff value is : " << leftoff << endl;  // bunny population marker
		//dump_bunniesObj(judyHops);   // testing and dump of bunny object content
		if(bunnyYear==3999)
		{
			JDGMNT_DAY=true;
			file.open("output.txt", ios::app);
			cout << "*** Doomsday ***" << endl;
			file.close();
		}
		cout << endl;
	}
	cout << "Bunny Run Ends" << endl;
	//dump_bunniesObj(judyHops);  // data read and write check function - testing only [placeholder]
}

void spawn(Bunny judyHops[4000], int &leftoff, int bunnyYear)
{	int numberoffemales=0, maleexistence = 0;
	ofstream file;
	int stop = leftoff;
	for(int i = 0;i<4000;i++)
	{
		if(judyHops[i].getSex() == 1 && judyHops[i].getAliveDead()==1)
			numberoffemales++;
		else if(judyHops[i].getSex() == 0 && judyHops[i].getAliveDead()==1)
			maleexistence = 1;
	}

	//file.open("output.txt",ios::app);
	//file << numberoffemales << endl;
	//file.close();
	cout << endl;
	if(maleexistence == 1)
	{
		for(int x = stop+1;x<stop+numberoffemales+1;x++)
			{	int color = (rand()%3), vampiredecision =(1 + rand()%100);
				bunnycounter(leftoff);
				judyHops[x].setYearBorn(bunnyYear);
				judyHops[x].setAliveDead(1);
				if(color == 0)
					judyHops[x].setColor("Black");
				else if(color == 1)
					judyHops[x].setColor("White");
				else if(color == 2)
					judyHops[x].setColor("Brown");
				else if(color == 3)
					judyHops[x].setColor("Spotted");

				if(vampiredecision == 1 || vampiredecision == 2)
				{	judyHops[x].setMutant(1);
					judyHops[x].setAliveDead(0);
					file.open("output.txt", ios::app);
					file<<"Radioactive mutant vampire bunny "<<judyHops[x].getName()<<" was born"<< endl;
					file.close();
				}
				else
				{	judyHops[x].setMutant(0);
					file.open("output.txt", ios::app);
					file<<"Bunny "<<judyHops[x].getName()<<" was born"<< endl;
					file.close();
				}
			}
	}
}

void clone_bunnies (Bunny clone[4000])
{	char str[20];
	int sex; // 0 = male, 1 = female;

	fstream inputStream;
	inputStream.open("names_sex.txt");

	for (int i=0; i<4000; i++)
	{
		inputStream >> sex;
		inputStream >> str;
		clone[i].setSex(sex);
		clone[i].setColor("");
		clone[i].setAge(0);
		clone[i].setMutant(0);
		clone[i].setName(str);
		clone[i].setAliveDead(0);
	}

	inputStream.close();

}

void extinction_check(bool &flag, Bunny obj[4000], int &year,int &leftoff)
{	for (int i=0; i<leftoff; i++)
	{
		if(obj[i].getAliveDead() == 1) //test if all bunnies are dead "2"
		{flag = false;}
		else
		{flag = true;}
	}
	if (flag == true)
	{	ofstream file;
		file.open("output.txt", ios::app);
		cout<<"All the bunnies have died" << endl;
		file.close();
	}
}

void outToFile()
{
	string line;
	ifstream myfile("output.txt");
	myfile.is_open();
	while (getline(myfile, line))
		{
			cout << line << endl;
		}
	myfile.close();

	ifstream myfile1;
	myfile1.open("output.txt", ifstream::out | ifstream::trunc);
	myfile1.close();
}



void dump_bunniesObj(Bunny object[4000])
{ 	// data write check
		for (int i=0; i<50; i++)
		{
			cout << object[i].getSex() << " " << object[i].getAge() << " " << object[i].getMutant() << " " << object[i].getName() << " " << object[i].getAliveDead() << "  " << object[i].getAge() << endl;
		}
}

void population_cull(Bunny judyHops[4000], int alivePopulation, int &leftoff, int &dead)
{	int half = 0, random = 0, i = 0;
	ofstream file;
	half = alivePopulation/2;

	if(alivePopulation >= 250)
	{
		file.open("output.txt", ios::app);
		//file<< "1"<< endl;
		//file<< half<< endl;
		file << "*** Over bunny population! ***" << endl;
		file.close();
		for(i = 0; i < half; i++)
		{
			file.open("output.txt", ios::app);
			random = rand()%(leftoff-1);
			if(judyHops[random].getAliveDead() == 0)
			{
				i--;
			}
			else if(judyHops[random].getAliveDead() == 1)
			{
				judyHops[random].setAliveDead(0);
				dead++;

				file<< judyHops[random].getName()<<" has died from food shortage"<< endl;
				file.close();
			}
		}
	}
	else
	{
		file<< "0";
		file.close();
	}
}

void plague_cull(Bunny judyHops[4000], int alivePopulation, int &leftoff)
{	ofstream file;
	int random = 0, vampire = 0, i = 0;

	for(i = 0; i < alivePopulation; i++)
	{
		if(judyHops[i].getMutant() == 1)
		{
			vampire++;
		}
	}
	for(i = 0; i < vampire; i++) //changes normal bunnies to vampire bunnies
	{
		random = rand()%(leftoff-1);
		if(judyHops[random].getMutant() == 1 || judyHops[random].getAliveDead() == 0)
		{
			i--;
		}
		else if(judyHops[random].getMutant() == 0 && judyHops[random].getAliveDead()==1)
		{
			//judyHops[random].setAliveDead(0);
			judyHops[random].setMutant(1);
			file.open("output.txt", ios::app);
			file<< "Bunny " << judyHops[random].getName()<<" has turned into a vampire bunny"<<endl;
			file.close();
		}
	}
}

int populationCount(Bunny judyHops[4000])
{	int population=0;
	for (int x = 0;x<4000;x++)
		if(judyHops[x].getAliveDead()==1)
			population++;
	return population;
}

void life_death(Bunny judyHops[4000], int year, int &dead)
{	ofstream file;
	for (int i = 0; i < 4000; i++)
	{
			if(judyHops[i].getAliveDead() == 1 && judyHops[i].getMutant() == 0)
			{
				/*if (year == 10 && judyHops[i].getAge()==10)
				{
					for (int j=0; j<2000; j++)
						if(judyHops[j].getAliveDead()==1)
							cout << judyHops[j].getName() << " is alive with age "  << judyHops[i].getAge() << endl;
				}*/
				if(judyHops[i].getAge() >= 3)
				{
					judyHops[i].setAliveDead(0);
					dead++;
					file.open("output.txt",ios::app);
					file<<"Bunny "<<judyHops[i].getName()<<"has died"<<endl;
					file.close();
				}
			}
			else if(judyHops[i].getMutant() == 1)
			{
				if(judyHops[i].getAge() >= 6)
				{
					file.open("output.txt",ios::app);
					file<<"Radioactive Mutant Vampire Bunny "<<judyHops[i].getName()<<"has died"<<endl;
					file.close();
					dead++;
				}
			}
		}
}

void bunnycounter(int &leftoff)
{	leftoff++;
}

void adameve(Bunny judyHops[4000])
{	// initialize first 5 bunnies
	ofstream file;
	file.open("output.txt", ios::app);
	file<<"Bunny Year: 0" << endl;
	file.close();
	for(int x = 0;x<5;x++)
	{
		int color = (rand()%3), vampiredecision =(1 + rand()%100);
		judyHops[x].setAliveDead(1);
		if(color == 0)
			judyHops[x].setColor("Black");
		else if(color == 1)
			judyHops[x].setColor("White");
		else if(color == 2)
			judyHops[x].setColor("Brown");
		else if(color == 3)
			judyHops[x].setColor("Spotted");

		judyHops[x].setMutant(0);
		file.open("output.txt", ios::app);
		file << "Bunny " << judyHops[x].getName() << " was Immaculately Conceived"<< endl;
		file.close();
	}
	file.open("output.txt", ios::app);
	file << endl;
	file.close();
}

void increment_age(Bunny object[4000], int &current_year)
{	for(int i=0; i<4000; i++)
		if(object[i].getAliveDead()==1)
			object[i].setAge(current_year - object[i].getYearBorn() + 1); //increase living bunny age by 1
}
