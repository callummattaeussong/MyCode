//
//1904 Project Bunny X
//14th Jun 2019
// Class Bunny
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
using namespace std;

class Bunny //class definition
{
	public:
		void setSex(int sex_code);  //setfunction
		int getSex(); //get function

		void setColor (string color_desc); //setfunction
		string getColor(); //get function

		void setAge (int aging); //setfunction
		int getAge();  //get function

		void setName (string nameGiven); //setfunction
		string getName(); //get function

		void setAliveDead (int doa_flag); //setfunction
		int getAliveDead (); //get function

		void setMutant(int newmutant);
		int getMutant();

		void setYearBorn(int yearborn);
		int getYearBorn();
	private:
		int sex;
		string color;
		int age;
		int mutant;
		string name;
		int alive_dead;
		int year_born;
};
