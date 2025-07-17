#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <sqlite3.h>

extern sqlite3 *db;

int connect_database();
void fecharBanco();


#endif // DATABASESERVICE_H
