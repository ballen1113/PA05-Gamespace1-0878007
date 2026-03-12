//------------------------------------------------------------------------------
// GameSpace.hpp : base class with Entity vector
//------------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <vector>

class Entity
//------------------------------------------------------------------------------
{
public:
	std::string name;
	int health;

	// default constructor
	Entity() : name("default mech"), health(-1)
	{ }

	// overload constructor
	Entity(const std::string& nameStr, int healthPts)
		: name(nameStr) 
		, health(healthPts)
	{ }

	// copy constructor
	//Entity(Entity& rhsEnt)
	//{
	//	name = rhsEnt.name;
	//	health = rhsEnt.health;
	//}
};

class GameSpace
//------------------------------------------------------------------------------
{
protected:
	std::string name;
	std::string description;
	std::vector<Entity> vEntities;

public:
	GameSpace() { }

	const std::string& getName() const { return name; }
	void setName(const std::string& nameStr) { description = nameStr; }

	const std::string& getDescription() const { return description; };
	void setDescription(const std::string& descStr) { description = descStr; }

	void addEntity(Entity ent) { vEntities.push_back(ent); }
	size_t getEntityCount() { return vEntities.size(); }
	Entity& getEntity(size_t index) { return vEntities.at(index); }

	virtual void print() = 0;

	void print(const std::string& messageStr)
	{
		std::cout << messageStr;
	}
};


