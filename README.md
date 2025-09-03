<p align="center">
  <img src="/extras/header.webp" alt="OpenDB logo">
</p>

# Open Material DB

Open Material DB is a lightweight SQLite-based database of engineering materials.
It is designed to be simple, extensible, and easy to integrate with tools written in [C3](https://c3-lang.org).

---

## Installation

### Install SQLite

```sh
# Debian/Ubuntu
sudo apt install sqlite3

# Fedora/Rocky
sudo dnf install sqlite3
```

### Download the Database

Download the latest release from GitHub:
[Open Material DB Releases](https://github.com/floating-gates/open-material-db/releases)

This provides a `.db` SQLite3 database containing all available material records.

---

## Building the Database

To generate the database from material records, the [C3 compiler](https://c3-lang.org) must be installed on your system.

```sh
make
```

This will compile and assemble the SQLite database from the JSON material records.

---

## Adding a New Material

To add a new material, create a JSON file under `material-records/`:

**Example:** `material-records/aluminum-6061.json`

```json
{
    "denomination": "EN AW-6061 (ISO AlMg1SiCu)",
    "display_name": "Aluminum - 6061",
    "type": "solid",
    "density": 2.70,
    "youngs_modulus": 6.9e10,
    "poisson_ratio": 0.33,
    "yield_strength": 2.4e8,
    "ultimate_tensile_strength": 3.1e8,
    "thermal_conductivity": 167
}
```

After adding the file, regenerate the database:

```sh
make
```

---

## Project Structure

```
extras/             # Documentation and assets
material-records/   # JSON definitions for individual materials
src/                # Source files for database generation
Makefile            # Build rules
```

---

## Usage

You can query the database with SQLite3:

```sh
sqlite3 materials.db "SELECT * FROM materials WHERE type='solid';"
```

---

## License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.
