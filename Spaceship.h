/*******************************************************************************
	* Spaceship.h
	* Author: Barb Allen
/******************************************************************************/

#include "GameSpace.hpp"
#include "PlanetX.h"

class Spaceship : public GameSpace
{
private:
	int speed;
	bool inOrbit;
public:
	Spaceship();

	bool getOrbitStatus() const;  
	int getSpd() const;

	/*******************************************************************************
		* I don't really need setters, but I like to have them for future design 
		* changes in case it becomes a UX input console app. 
	/******************************************************************************/
	void setSpd(int&);
	void setOrbitStat(bool&); 

	/*******************************************************************************
		* member function for depart status
	/******************************************************************************/
	void departureStatus();

	/*******************************************************************************
		* member function for travel
	/******************************************************************************/
	void travelTo(GameSpace& destination);

	/*******************************************************************************
		* function to rescue!
	/******************************************************************************/
	
	void rescue(PlanetX& location);

	/*******************************************************************************
		* function to leave orbit and update ship + planet status using desc
	/******************************************************************************/
	void leaveOrbit(PlanetX& location);

	/*******************************************************************************
		* storytelling with description and print ship status
	/******************************************************************************/
	
	void resolutionStatus();

	/*******************************************************************************
		* Print functions
	/******************************************************************************/
	void print();
	void print(const std::string& message);
};

