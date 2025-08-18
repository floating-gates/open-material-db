![Logo](/src/header.svg)

# Install SQLite

``` shell
sudo apt install sqlite3 
# OR sudo dnf install sqlite3 
```

# Download the DB

Use the github version: https://github.com/floating-gates/open-material-db/releases
It will give you a .db file, a sqlite3 database with all materials in its internals.

# Generate the database

``` shell
./c3c compile src/main -l sqlite3 
```

# Add a material to the database

Add a new file in ```material-records/xxx.json```

``` json
{
    "denomination": "EN AW-6061 (ISO AlMg1SiCu)",
    "display_name": "Aluminum - 6061",
    "type": "solid",
    "density": 2.70,
    "youngs_modulus": 69e9,
    "poisson_ratio": 0.33,
    "yield_strength": 240e6,
    "ultimate_tensile_strength": 310e6,
    "thermal_conductivity": 167
}
```
