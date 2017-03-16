#include "Common.h"
#include "CosmosQuery.h"

CosmosQuery::CosmosQuery(CosmosQueryServiceFactory &serviceFactory)
	: _serviceFactory(serviceFactory)
{
}

void CosmosQuery::StartQuerySession()
{
	bool terminateSession = false;

	while (!terminateSession)
	{
		PrintQueryMenu();
		std::cout << "QUERY > ";

		std::string option;
		std::getline(std::cin, option);

		std::cout << std::endl;

		HandleQueryOption(option, terminateSession);
	}
}

void CosmosQuery::HandleQueryOption(const std::string &option, bool &terminateSession)
{
	if (option == "1")
	{
		PerformStructureQuery();
	}
	else if (option == "2")
	{
		PerformMembershipQuery();
	}
	else
	{
		std::cout << "SESSION TERMINATED." << std::endl;
		terminateSession = true;
	}
}

void CosmosQuery::PerformStructureQuery()
{
	std::cout << "ENTER SYSTEM NAME TO QUERY SUBSYSTEMS (EMPTY TO ABORT):" << std::endl;

	std::string name;
	std::getline(std::cin, name);

	if (name.empty())
		return;

	std::cout << std::endl;
	std::cout << "QUERYING..." << std::endl;

	CosmosQueryService *service = _serviceFactory.GetQueryService();
	Entity *tree = service->QuerySystemStructure(name);

	if (!tree)
	{
		std::cout << "QUERY FAILED." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "RESULT" << std::endl;
		std::cout << "========" << std::endl;
		std::cout << std::endl;

		PrintEntityTree(*tree, 0);
		std::cout << std::endl;

		delete tree;
	}

	Pause();
	delete service;
}

void CosmosQuery::PerformMembershipQuery()
{
	std::cout << "ENTER SYSTEM NAME TO QUERY MEMBERSHIP (EMPTY TO ABORT):" << std::endl;
	
	std::string name;
	std::getline(std::cin, name);

	if (name.empty())
		return;

	std::cout << std::endl;
	std::cout << "QUERYING..." << std::endl;

	CosmosQueryService *service = _serviceFactory.GetQueryService();
	Entity *tree = service->QuerySystemMembership(name);

	if (!tree)
	{
		std::cout << "QUERY FAILED." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "RESULT" << std::endl;
		std::cout << "========" << std::endl;
		std::cout << std::endl;

		PrintEntityTree(*tree, 0);
		std::cout << std::endl;

		delete tree;
	}

	Pause();
	delete service;
}

void CosmosQuery::PrintEntityTree(const Entity &entity, int level)
{
	for (int i = 0; i < level * 2; i++)
		std::cout << ' ';

	std::cout << entity.Name() << std::endl;

	const Entity::EntityArray &subEntities = entity.SubEntities();
	for (Entity::EntityArray::const_iterator it = subEntities.begin(); it != subEntities.end(); ++it)
		PrintEntityTree(**it, level + 1);
}

void CosmosQuery::PrintQueryMenu()
{
	for (int i = 0; i < 100; i++)
		std::cout << std::endl;

	std::cout << "COSMOS QUERY" << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl;
	std::cout << "1 - QUERY SYSTEM STRUCTURE" << std::endl;
	std::cout << "2 - QUERY SYSTEM MEMBERSHIP" << std::endl;
	std::cout << std::endl;
	std::cout << "ENTER AN INVALID OPTION TO QUIT." << std::endl;
	std::cout << std::endl;
}

void CosmosQuery::Pause()
{
	std::cout << "PRESS ENTER TO CONTINUE..." << std::endl;

	std::string line;
	std::getline(std::cin, line);
}
