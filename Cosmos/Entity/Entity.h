#ifndef ENTITY_H
#define ENTITY_H

#include "../Common.h"

class Entity
{
public:
	typedef std::vector<Entity*> EntityArray;

	Entity(const std::string &name);
	virtual ~Entity();

	const std::string& Name() const;

	void AppendSubEntity(Entity *entity);
	const EntityArray& SubEntities() const;

private:
	Entity(const Entity&);
	Entity& operator=(const Entity&);

private:
	std::string _name;
	EntityArray _subEntities;
};

#endif
