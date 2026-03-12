//------------------------------------------------------------------------------
// PlanetX : derived class definition, base class GameSpace
//------------------------------------------------------------------------------
#include "PlanetX.h"

#include <iostream>

// constructor
PlanetX::PlanetX()
{
	//new name and description to fit with futurama theme
	name = "Chapek 9";
	description = "A small featureless planet that is home to human-hating robots";

	// BEGIN Don't change these!
	addEntity({ "Rover 1 explorer drone", -10 });	// mech Entity, don't rescue
	addEntity({ "Mysterious vapor being", 10 });	// living bio, do rescue
	addEntity({ "Aquarium fish", 0 });				// non-living bio, don't rescue
	// END Don't change these!

	// add your own occupants here
	addEntity({ "BenderBot Factory Machine", -10 }); // Futurama Bender!
	addEntity({ "Nibbler The Great", 0 });			 // Futurama Nibbler (hope you've seen the show)
	addEntity({ "Delivery-boy Philip Fry", 10 });	 // Yet another Futurama character

	// mech Entities have a negative health value.
	// non-living biological Entities have a health value of 0.
	// living biological Entities have a positive health value.
}

// display status and occupant list 
void PlanetX::print()
{
	size_t eCount = getEntityCount();

	std::cout << name << " has " << eCount << " occupants:\n";

	for (int i = 0; i < eCount; i++)
	{
		Entity ent = getEntity(i);
		std::cout << "\t" << ent.name;
		
		if (ent.health > 0)
			std::cout << " is alive!\n";
		else if (ent.health == 0)
			std::cout << " has been killed :(\n";
		else
			std::cout << " is a robot ally\n";
	}
	std::cout << "\n";
}

// display message, then status and occupant list 
void PlanetX::print(const std::string& message)
{
	std::cout << name << " is a " << description << ".\n";
	print();
}

