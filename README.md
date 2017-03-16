# COSMOS
Cosmos Demo Application for C++ 11/14 Migration

This is a very simple program as a start to mirgate from C++ 98/03 to C++ 11/14.

## Dependencies
- MySQL
- MySQL Connector/C (libmysqlclient) (x86, 32-bit)

## Development Software
This program was created with Microsoft Visual Studio 2013 Express. However it should be able to be built without any problem with any other standard C++ 11/14 compilers.

## How to use
Assume all the software mentioned are installed, to build and run the program properly, the following steps need to be followed.

1. Run cosmos.systems.sql to import the database schema and sample data
2. Modify the DataSource.cpp to supply correct HOST, USER, PASSWORD and PORT
3. Modify C++ Include Directories settings to include the include path of MySQL Connector/C
4. Modify C++ Library Directories settings to include the lib path of MySQL Connector/C
