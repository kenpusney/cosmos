#include "../Common.h"
#include "Entity.h"

Entity::Entity(const std::string &name)
	: _name(name)
{
}

Entity::~Entity()
{
	for (EntityArray::iterator it = _subEntities.begin(); it != _subEntities.end(); ++it)
		delete *it;
}

const std::string& Entity::Name() const
{
	return _name;
}

void Entity::AppendSubEntity(Entity *entity)
{
	_subEntities.push_back(entity);
}

const Entity::EntityArray& Entity::SubEntities() const
{
	return _subEntities;
}
