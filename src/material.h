#include <sqlite3.h>
#include <stdio.h>

#include "sql.h"

// Struct for material
typedef struct {
    const char *testing_standards;
    const char *display_name;
    const char *type;
    double density;
    double youngs_modulus;
    double poisson_ratio;
    double yield_strength;
    double ultimate_tensile_strength;
    double thermal_conductivity;
} Material;


// Function to insert a material into DB
int load_mat_in_db(sqlite3 *db, const Material *m) {
    char sql[1024];
    snprintf(sql, sizeof(sql), INSERT_MATERIAL_SQL,
        m->testing_standards,
        m->display_name,
        m->type,
        m->density,
        m->youngs_modulus,
        m->poisson_ratio,
        m->yield_strength,
        m->ultimate_tensile_strength,
        m->thermal_conductivity
    );

    char *errMsg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL insert error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
      printf("Inserted material: %s  successfully!\n", m->display_name);
    }

    return rc;
}
