/*******************************************************************************
	* PlanetX.cpp
	* Author(s):
	* Code Template: Linda C.
	* Edited by: Barb Allen
/******************************************************************************/
#include "PlanetX.h"
#include <iostream>

// constructor
PlanetX::PlanetX()
{
	
	/*******************************************************************************
		* In-story context. If you've seen the show, you'd know antics like this are
		* VERY typical of Fry and Bender. Not the sharpest tools in the shed.
		* Nibbler got roped into it. Who knows.
	/******************************************************************************/
	name = "Chapek 09";
	description = "Chapek 9 is a planet inhabited entirely by robots who are violently opposed to humans -- \nessentially a robot supremacist society. Bender, Fry, and Nibbler traveled to Chapek 09 over \na week ago in response to a scam casino ad, claiming they would get $1000(equivalent) \neach in free play upon first visit. Their only recent communication has been a cryptic distress \nsignal";

	// BEGIN Don't change these!
	addEntity({ "Rover 1 explorer drone", -10 });	// mech Entity, don't rescue
	addEntity({ "Mysterious vapor being", 10 });	// living bio, do rescue
	addEntity({ "Aquarium fish", 0 });				// non-living bio, don't rescue
	// END Don't change these!

	/*******************************************************************************
		* My entities
	/******************************************************************************/
	addEntity({ "BenderBot Factory Machine", -10 }); // Futurama Bender!
	addEntity({ "Nibbler The Great", 0 });			 // Futurama Nibbler (hope you've seen the show)
	addEntity({ "Delivery-boy Philip Fry", 10 });	 // Yet another Futurama character

	// mech Entities have a negative health value.
	// non-living biological Entities have a health value of 0.
	// living biological Entities have a positive health value.
}

/*******************************************************************************
	* display status and occupant list
/******************************************************************************/
void PlanetX::print()
{
	size_t eCount = getEntityCount();

	std::cout << name << " has " << eCount << " occupants:\n\n";

	for (int i = 0; i < eCount; i++)
	{
		Entity ent = getEntity(i);
		
		/*******************************************************************************
			* didn't like the visual aesthetic of the indentations, so I got rid of them
		/******************************************************************************/
		std::cout << ent.name;
		
		if (ent.health > 0)
			std::cout << " is alive!\n";
		else if (ent.health == 0)
			std::cout << " has already served their sentence!\n";
		else
			std::cout << " is a robot ally\n";
	}
	std::cout << "-----------------------------------------------------------------------------------------------\n";
}

/*******************************************************************************
	* Print planet description
/******************************************************************************/
void PlanetX::print(const std::string& message)
{
	
	std::cout << description << ".\n";
	std::cout << "-----------------------------------------------------------------------------------------------\n";
	
}

