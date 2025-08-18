extern fn int sqlite3_open (char*, void**);
extern fn int sqlite3_exec (void*, char*, void*,  void*,  char**);
extern fn int sqlite3_close(void*);

import std::io;

fn int main() {
    void* db;
    int rc = sqlite3_open("test.db", &db);

    if (rc != 0) {
      io::print("Can't open database\n");
        return 0;
    }

    String query = "CREATE TABLE IF NOT EXISTS materials(id INTEGER PRIMARY KEY AUTOINCREMENT,  denomination TEXT, display_name TEXT, type TEXT,   density REAL, youngs_modulus REAL, poisson_ratio REAL, yield_strength REAL, ultimate_tensile_strength REAL, thermal_conductivity REAL)";

  char* err = null;
  sqlite3_exec(db, query, null, null, &err);

  io::print("Table created (if not already).\n");

  sqlite3_close(db);
  return 0;
}
