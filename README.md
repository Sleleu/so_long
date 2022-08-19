# so_long

![so_long](https://user-images.githubusercontent.com/93100775/185695087-91a9f101-d4e8-40fd-aafa-f4625fa6d755.jpg)

This is a project from 42 school, aiming to become familiar with some notions such as **window management, event handling, colors, textures, and so forth**.

For this small 2D game, we need to use the **MiniLibX**, a school graphical library. This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

The other goals are similar to every first projects of the common core of 42 : being rigorous, improving skills in C programming, use basic algorithms, do some information research, and so forth.

## The game

The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.

It's possible to move the main character with **W,A,S,D**, the player cannot move into walls, and a number of mouvements is displayed in the shell>

## Installation

### Clone the repository

```shell
git clone git@github.com:Sleleu/so_long.git
cd so_long
```

### Install the minilibx library

In the ./so_long folder :

```shell
git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
make
```
### Play

Example :

```shell
./so_long maps/map2.ber
```

4 maps are present in the maps file.

### Create your own maps

It is possible to create your own maps following the rules imposed by the project. Here is a simple valid map :

```shell
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

The map can be composed of only these 5 characters :
- `0` for an empty space,
- `1` for a wall
- `C` for a collectible
- `E` for a map exit
- `P` for the player's starting position

The map must be rectangular, closed by walls, and constain at least **1 exit, 1 collectible and 1 starting position**.
