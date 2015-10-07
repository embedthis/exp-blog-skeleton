/*
    Create Scaffold Comment
 */
#include "esp.h"

static int forward(Edi *db) {
    ediAddTable(db, "comment");
    ediAddColumn(db, "comment", "id", EDI_TYPE_INT, EDI_AUTO_INC | EDI_INDEX | EDI_KEY);
    ediAddColumn(db, "comment", "url", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "comment", "date", EDI_TYPE_DATE, 0);
    ediAddColumn(db, "comment", "name", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "comment", "email", EDI_TYPE_STRING, 0);
    ediAddColumn(db, "comment", "message", EDI_TYPE_TEXT, 0);
    ediAddColumn(db, "comment", "approved", EDI_TYPE_BOOL, 0);
    return 0;
}

static int backward(Edi *db) {
    ediRemoveTable(db, "comment");
    return 0;
}

ESP_EXPORT int esp_migration_create_scaffold_comment(Edi *db)
{
    ediDefineMigration(db, forward, backward);
    return 0;
}
