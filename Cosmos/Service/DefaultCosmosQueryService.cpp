#include "../Common.h"
#include "DefaultCosmosQueryService.h"

DefaultCosmosQueryService::DefaultCosmosQueryService(MYSQL *dataSource)
	: _dataSource(dataSource)
{
}

Entity* DefaultCosmosQueryService::QuerySystemStructure(const std::string &name)
{
	IdentifiedEntity *root = QueryEntity(name);
	
	if (!root)
		return NULL;
	
	if (!QuerySubEntities(*root))
	{
		delete root;
		return NULL;
	}

	return root;
}

Entity* DefaultCosmosQueryService::QuerySystemMembership(const std::string &name)
{
	IdentifiedEntity *entity = QueryEntity(name);

	if (!entity)
		return NULL;

	Entity *top = NULL;
	int nextId = entity->ID();
	delete entity;

	while (nextId >= 0)
	{
		std::stringstream ss;
		ss << "SELECT NAME, PARENT FROM SYSTEMS WHERE ID=" << nextId;

		if (mysql_query(_dataSource, ss.str().c_str()) != 0)
			break;

		MYSQL_RES *res = mysql_store_result(_dataSource);
		if (!res)
			break;

		MYSQL_ROW row = mysql_fetch_row(res);
		if (!row)
		{
			mysql_free_result(res);
			break;
		}

		std::string name = row[0];
		nextId = row[1] ? atoi(row[1]) : -1;
		
		mysql_free_result(res);

		Entity *superEntity = new Entity(name);

		if (top)
			superEntity->AppendSubEntity(top);

		top = superEntity;
	}

	return top;
}

IdentifiedEntity* DefaultCosmosQueryService::QueryEntity(const std::string &name)
{
	if (name.find('\'') != std::string::npos)
		return NULL;

	std::stringstream ss;
	ss << "SELECT ID FROM SYSTEMS WHERE NAME='" << name << "'";

	if (mysql_query(_dataSource, ss.str().c_str()) != 0)
		return NULL;

	MYSQL_RES *res = mysql_store_result(_dataSource);
	if (!res)
		return NULL;

	MYSQL_ROW row = mysql_fetch_row(res);
	if (!row)
	{
		mysql_free_result(res);
		return NULL;
	}

	int id = atoi(row[0]);
	mysql_free_result(res);

	return new IdentifiedEntity(id, name);
}

bool DefaultCosmosQueryService::QuerySubEntities(IdentifiedEntity &root)
{
	std::stringstream ss;
	ss << "SELECT ID, NAME FROM SYSTEMS WHERE PARENT=" << root.ID();

	if (mysql_query(_dataSource, ss.str().c_str()) != 0)
		return false;

	MYSQL_RES *res = mysql_store_result(_dataSource);
	if (!res)
		return false;

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		int id = atoi(row[0]);
		std::string name = row[1];

		IdentifiedEntity *entity = new IdentifiedEntity(id, name);
		root.AppendSubEntity(entity);

		if (!QuerySubEntities(*entity))
		{
			mysql_free_result(res);
			return false;
		}
	}

	mysql_free_result(res);
	return true;
}
