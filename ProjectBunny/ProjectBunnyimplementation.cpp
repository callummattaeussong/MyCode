#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
#include "bunny.h"
using namespace std;

void Bunny::setSex(int sex_code)  //setfunction
{sex = sex_code;}

int Bunny::getSex() //get function
{return sex;}

void Bunny::setColor (string color_desc) //setfunction
{color = color_desc;}

string Bunny::getColor() //get function
{return color;}

void Bunny::setAge (int aging) //setfunction
{age = aging;}

int Bunny::getAge()  //get function
{return age;}

void Bunny::setName (string nameGiven) //setfunction
{name = nameGiven;}

string Bunny::getName() //get function
{return name;}

void Bunny::setAliveDead (int doa_flag) //setfunction
{alive_dead = doa_flag;}

int Bunny::getAliveDead () //get function
{return alive_dead;}

void Bunny::setMutant(int newmutant)
{mutant = newmutant;}

int Bunny::getMutant()
{return mutant;}

void Bunny::setYearBorn(int yearborn)
{year_born = yearborn;}

int Bunny::getYearBorn()
{return year_born;}