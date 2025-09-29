// Table creation SQL
#define CREATE_MATERIALS_TABLE_SQL "CREATE TABLE IF NOT EXISTS materials( \
    id INTEGER PRIMARY KEY AUTOINCREMENT,  \
    testing_standards TEXT UNIQUE, \
    display_name TEXT, \
    type TEXT, \
    density REAL, \
    youngs_modulus REAL, \
    poisson_ratio REAL, \
    yield_strength REAL, \
    ultimate_tensile_strength REAL, \
    thermal_conductivity REAL)"

#define INSERT_MATERIAL_SQL                                                        \
  "INSERT OR IGNORE INTO materials                                                \
   (testing_standards, display_name, type, density, youngs_modulus,                \
   poisson_ratio, yield_strength, ultimate_tensile_strength, thermal_conductivity) \
   VALUES ('%s','%s','%s',%f,%f,%f,%f,%f,%f)"
