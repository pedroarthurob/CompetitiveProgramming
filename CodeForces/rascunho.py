import numpy as np
import matplotlib.pyplot as plt
import random

def initialize_maze(width, height):
    """ Inicializa o labirinto com células não visitadas. """
    maze = np.zeros((height, width), dtype=int)
    return maze

def get_neighbors(x, y, width, height):
    """ Obtém as coordenadas dos vizinhos válidos. """
    neighbors = []
    if x > 1:
        neighbors.append((x - 2, y))
    if x < width - 2:
        neighbors.append((x + 2, y))
    if y > 1:
        neighbors.append((x, y - 2))
    if y < height - 2:
        neighbors.append((x, y + 2))
    return neighbors

def recursive_traverse(x, y, maze):
    """ Implementa a função recursiva para gerar o labirinto. """
    maze[y, x] = 1
    neighbors = get_neighbors(x, y, maze.shape[1], maze.shape[0])
    random.shuffle(neighbors)
    for (nx, ny) in neighbors:
        if maze[ny, nx] == 0:
            maze[(ny + y) // 2, (nx + x) // 2] = 1
            recursive_traverse(nx, ny, maze)

def generate_maze(width, height):
    """ Gera o labirinto usando o algoritmo Recursive Backtracker. """
    maze = initialize_maze(width, height)
    start_x, start_y = 1, 1
    recursive_traverse(start_x, start_y, maze)
    return maze

def plot_maze(maze):
    """ Plota o labirinto usando matplotlib. """
    plt.figure(figsize=(10, 10))
    plt.imshow(maze, cmap='gray')
    plt.axis('off')
    plt.show()

# Parâmetros do labirinto
width, height = 51, 51
maze = generate_maze(width, height)
plot_maze(maze)
