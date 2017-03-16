#include "../Common.h"
#include "DataSource.h"

namespace
{
	const char HOST[] = "localhost";
	const char USER[] = "root";
	const char PASSWORD[] = "1qaz@WSX";
	const char SCHEMA[] = "cosmos";
	const unsigned int PORT = 3306u;
}

MYSQL* ConnectDataSource()
{
	MYSQL *conn;

	conn = mysql_init(NULL);
	if (!conn)
		return NULL;

	if (!mysql_real_connect(conn, HOST, USER, PASSWORD, SCHEMA, PORT, NULL, 0))
	{
		mysql_close(conn);
		return NULL;
	}

	return conn;
}
