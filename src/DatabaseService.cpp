#include "DatabaseService.h"
#include <stdio.h>

sqlite3 *db = nullptr;

int connect_database() {
    int rc = sqlite3_open("./database/lirio_azul_database.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    return 0;
}

void fecharBanco() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}
