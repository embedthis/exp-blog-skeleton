/*
    Create Scaffold User
 */
#include "esp.h"

static int forward(Edi *db) {
    EdiRec  *rec;
    cchar   *password;

    ediAddTable(db, "user");
    ediAddColumn(db, "user", "id", EDI_TYPE_INT, EDI_AUTO_INC | EDI_INDEX | EDI_KEY);
    ediAddColumn(db, "user", "username", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "user", "password", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "user", "email", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "user", "roles", EDI_TYPE_STRING, 0);

    password = mprMakePassword("PASSWORD", 16, 128);
    rec = ediCreateRec(db, "user");
    ediSetFields(rec, ediMakeJson("{ username: 'USERNAME', password: '%s', email: 'dev@embedthis.com', roles: 'administrator'   }", password));
    ediUpdateRec(db, rec);

    return 0;
}

static int backward(Edi *db) {
    ediRemoveTable(db, "user");
    return 0;
}

ESP_EXPORT int esp_migration_create_scaffold_user(Edi *db)
{
    ediDefineMigration(db, forward, backward);
    return 0;
}
