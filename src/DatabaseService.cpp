#include "DatabaseService.h"
#include <stdio.h>

sqlite3 *db = NULL;

int connect_database() {
    int rc = sqlite3_open("./database/lirio_azul_database.db", &db); // Abre o banco de dados, agora a variável db está concetada com o banco

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Não deu pra abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stderr, "Abriu o banco corretamente\n");
    }

    return 0;
}

void fecharBanco() {
    if (db != NULL) {
        sqlite3_close(db);
        db = NULL;
    }
}
