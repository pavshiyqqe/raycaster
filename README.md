# Cub3D

Cub3D is a small raycasting engine inspired by the early Wolfenstein‑style renderers. The project focuses on learning how simple 3D projection works, how to manage a rendering loop, and how to handle input and window management using MiniLibX.

---

##  Overview

The goal is to create a minimal first‑person view where walls are rendered using vertical slices based on ray‑wall intersections. The program reads a configuration file, loads textures, sets the initial player position, and continuously draws the scene according to the player’s movement.

---

##  Project Objectives

* Implement a basic raycasting engine.
* Parse and validate a `.cub` configuration file.
* Render walls with correct height and texture alignment.
* Handle player movement, rotation, and collision.
* Use MiniLibX for window creation, images, and event handling.

---

##  Map File (.cub)

A valid `.cub` file includes:

* Paths to textures for each wall direction (NO, SO, WE, EA)
* Floor and ceiling colors (RGB)
* A closed map layout made of `1`, `0`, and a single player start (`N`, `S`, `E`, `W`)

Basic checks include:

* No duplicated identifiers
* Map must be fully enclosed by walls
* Only one player spawn
* No invalid characters

---

## 🔧 How It Works

### 1. Raycasting

For each vertical column on the screen:

* A ray is cast at a specific angle based on the player’s direction.
* The ray is moved step by step until it hits a wall.
* The distance to the wall determines how tall the wall slice will appear.
* A texture is sampled vertically to draw that slice.

### 2. Player Movement

Supported actions:

* Move forward/backward
* Strafe left/right
* Rotate left/right or with the mouse

Collision checks prevent the player from walking into walls.

### 3. Rendering Loop

Each frame:

* Clear or redraw the background
* Cast rays for every screen column
* Draw wall slices with textures
* Display the final image to the window

---

## Building and Running

```
make mlx
make
./cub3d map.cub
```

---

##  Project Structure

* `src/parsing/` — map and parameter validation
* `src/raycast/` — core rendering logic
* `src/mlx/` — MiniLibX wrappers
* `src/utils/` — helpers
* `textures/` — wall textures

---

##  Controls

* **W / S** — move forward / backward
* **A / D** — strafe left / right
* **Left / Right arrow** — rotate
* **ESC** — exit

---

## 📝 Notes

Cub3D is not a true 3D engine; it simulates 3D using mathematics and projections. The project helps build intuition about vectors, angles, distances, and real‑time rendering.
