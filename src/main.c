#include "material.h"
#include "json.h"
#include "sql.h"

int main( int argc, char *argv[]) {
  
  char* jsonText = loadFile(argv[1]);
  char* db_name = "materials.db";
  sqlite3* DB;

  // Check if filename is provided
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <path_to_json>\n", argv[0]);
    return 1;
  }


  int status_connection = sqlite3_open(db_name, &DB);

  if (status_connection) {
    printf("Error opening DB %s\n", sqlite3_errmsg(DB));
    return -1;
  } else {
    printf("Opened Database Successfully!\n");
  }

  // Create table
  char *messageError;
  status_connection = sqlite3_exec(DB, CREATE_MATERIALS_TABLE_SQL, NULL, 0, &messageError);

  if (status_connection != SQLITE_OK) {
    printf("SQL error: %s\n", messageError);
    sqlite3_free(messageError);
  } else {
    printf("Table created successfully!\n");
  }

  
  if (!jsonText) {
    printf("File not found\n");
    return 1;
  }

  const char* p = jsonText;

  JsonValue* material = readValue(&p);
    
  JsonValue* testing_standards = getValue(material, "testing_standards");
  JsonValue* display_name = getValue(material, "display_name");
  JsonValue* type = getValue(material, "type");
  JsonValue* density = getValue(material, "density");
  JsonValue* youngs_modulus = getValue(material, "youngs_modulus");
  JsonValue* poisson_ratio = getValue(material, "poisson_ratio");
  JsonValue* yield_strength = getValue(material, "yield_strength");
  JsonValue* ultimate_tensile_strength = getValue(material, "ultimate_tensile_strength");
  JsonValue* thermal_conductivity = getValue(material, "thermal_conductivity");
  
  Material mat = {
    .testing_standards = testing_standards->stringValue,
    .display_name = display_name->stringValue,
    .type = type->stringValue,
    .density = density->numberValue,
    .youngs_modulus = youngs_modulus->numberValue,
    .poisson_ratio = poisson_ratio->numberValue,
    .yield_strength = yield_strength->numberValue,
    .ultimate_tensile_strength = ultimate_tensile_strength->numberValue,
    .thermal_conductivity = thermal_conductivity->numberValue
  };

  load_mat_in_db(DB, &mat);

  sqlite3_close(DB);
  
  free(jsonText);
  return 0;
}
