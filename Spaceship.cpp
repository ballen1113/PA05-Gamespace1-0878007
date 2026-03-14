
/*******************************************************************************
	* Spaceship.cpp
	* Author: Barb Allen
/******************************************************************************/

#include "Spaceship.h"
#include "PlanetX.h"
#include <iostream>

/*******************************************************************************
	* incl planetX for removeEntities member function
/******************************************************************************/


/*******************************************************************************
	* The coding standard used this, so I figured it was okay :thumbs_up:
/******************************************************************************/
using std::cout;


//Constructor
Spaceship::Spaceship()
{
	/*******************************************************************************
		* Introductory UX. Chapek 9 actually appears in Futurama episode Season 1 Ep 
		* 5, which features a delivery to the planet that inhabits robot supremacists 
		* that kill humans on sight. I've taken some creative liberty to fit it with 
		* the assignment description. In the show, the robot judge puts robots on 
		* trial, and being a human results in a death sentence.
	/******************************************************************************/
	name = "Planet Express";
	description = "------------------------------------------------------------------------------------------------ \nThe Planet Express is a delivery vessel designed to transport cargo from Earth \nto across the entire galaxy. Today, the crew is heading to Chapek 09 in response to\na mayday signal sent by their crewmates Bender and Fry, who have been held captive\nwhile awaiting their hearing with the Robot Judge.";

	/*******************************************************************************
		* Apparently in a reddit thread, some math nerds calculated that the Planet 
		* Express from Futurama goes at 900,000 * the speed of light.
		* This happened because in the show canon, the speed of light was increased 
		* in year 2208. Cool!
	/******************************************************************************/
	speed = 900000;
	inOrbit = false;

	/*******************************************************************************
		*Pre-existing entities I've added
	/*******************************************************************************/
    addEntity({ "Captain Turanga Leela", 10 });

	/*******************************************************************************
		* I honestly really don't care about being the captain. I feel like I'd be a good 
		* intern tho. More on brand for me :) 
	/*******************************************************************************/
    addEntity({ "Delivery Intern Barb", 10 });
    addEntity({ "Dr. Zoidberg", 10 });
};

/*******************************************************************************
	* More intro UX for status
/******************************************************************************/
void Spaceship::departureStatus()
{
	std::string desc = getName() + " and its' crew are now en route to Chapek 09";
	std::string speedDesc = (" at 900,000x the speed of light..." );
	setDescription(desc + speedDesc);
	print("desc");
}

/********************************************************************************
	* getter functions
/*******************************************************************************/
 bool Spaceship::getOrbitStatus() const
{
	return { inOrbit };
}

 int Spaceship::getSpd() const
{
	return { speed };
}

 /********************************************************************************
	* setter functions
 /*******************************************************************************/
void Spaceship::setOrbitStat(bool& flag)
{
	inOrbit = flag;
}

void Spaceship::setSpd(int& spd)
{
	speed = spd;
}

//declaration for travelTo
void Spaceship::travelTo(GameSpace& destination)
{
	/********************************************************************************
		* Print status to user about orbit + spd status
	/*******************************************************************************/
	inOrbit = true;
	speed = 0;

	std::string desc = "Now orbiting " + destination.getName();
	std::string speedDesc = (" at speed 0");
	setDescription(desc + speedDesc);
	print("desc");

	bool orbit = true;
	int spd = 0;

	setOrbitStat(orbit);
	setSpd(spd);
}


void Spaceship::rescue(PlanetX& location)
{
	/*******************************************************************************
		* null entity for spacing, probably not the best way to handle it but I really 
		* couldn't think of anything else without being overtly specific about putting it 
		* between a specific index, which would reduce modifiability 
	/*******************************************************************************/
	addEntity({ "------------------------------------------[Evacuees:]------------------------------------------", 5 });
	/*******************************************************************************
		* health being 5 will be a flag to remove later in future iterations where 
		* the simulation continues, I hope. Since the rest of the entities have health 10.
	/*******************************************************************************/


	/*******************************************************************************
		* add qualifying entities to Spaceship, remove entities that shouldn't be saved
	/******************************************************************************/
	for (int i = location.getEntityCount() - 1; i >= 0; i--)
	{
		Entity ent = location.getEntity(i);
		if (ent.health > 0)
		{
			addEntity(ent);
			location.removeEntity(i);
		}
	}
	
	setDescription("Captain Leela and the crew of the Planet Express rescue all living organisms \nfrom Chapek 9 shortly before the robot judge sentences them to death!");
	location.setDescription("Survivors have been rescued by the crew of the " + getName());
}


/*******************************************************************************
	* Leaveorbit resets ship status, changes description of spaceship and 
	* planetX for display.
/******************************************************************************/ 
void Spaceship::leaveOrbit(PlanetX& location)
{

	bool orbit = false;
	int spd = 900000;
	setOrbitStat(orbit);
	setSpd(spd);

	setDescription("Court adjourned! The Robot Judge has reached his verdict: death! The crew of the " + getName() + " narrowly escapes at 900,000x the speed of light!");
	location.setDescription("With the verdict, all robots on Chapek 09 have their functions overwritten: \ncarry out the death sentence at all costs.\nThe planet's inhabitants are in a frenzied manhunt looking for your recent evacuees..");
}

void Spaceship::resolutionStatus()
{
	setDescription("On the Planet Express, everyone is safe at last! The rescued survivors huddle together in \nrelief as the " + getName() + " blasts through the stars toward Earth. Fry promises to buy \neveryone dinner, which is likely freezer pizza and cheap beer. The crew lands at Planet Express \nHQ -- battered, exhausted, and ready for their next mission: rescue Bender.");
}

/*******************************************************************************
	* print functions
/******************************************************************************/
void Spaceship::print()
{

	/*******************************************************************************
		*Spaceship specific output: lists vector entities within spaceship 
	/******************************************************************************/
    size_t eCount = getEntityCount();

	
	cout << name << " has " << eCount << " passengers:\n";

	for (int i = 0; i < eCount; i++)
	{
		Entity ent = getEntity(i);
		cout << "\n" << ent.name;
	}
	cout << "\n";
	cout << "-----------------------------------------------------------------------------------------------\n";
  
}

/*******************************************************************************
	* Overload print to display description
/******************************************************************************/
void Spaceship::print(const std::string& message)
{
    
	cout << description << "\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
 
}
