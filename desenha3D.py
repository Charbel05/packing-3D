import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import re
import random

# 🎨 Desenha uma caixa 3D
def draw_box(ax, x, y, z, dx, dy, dz, color):
    vertices = [
        [x,     y,     z],
        [x+dx,  y,     z],
        [x+dx,  y+dy,  z],
        [x,     y+dy,  z],
        [x,     y,     z+dz],
        [x+dx,  y,     z+dz],
        [x+dx,  y+dy,  z+dz],
        [x,     y+dy,  z+dz]
    ]
    faces = [
        [vertices[0], vertices[1], vertices[2], vertices[3]],
        [vertices[4], vertices[5], vertices[6], vertices[7]],
        [vertices[0], vertices[1], vertices[5], vertices[4]],
        [vertices[2], vertices[3], vertices[7], vertices[6]],
        [vertices[1], vertices[2], vertices[6], vertices[5]],
        [vertices[4], vertices[7], vertices[3], vertices[0]],
    ]
    box = Poly3DCollection(faces, alpha=0.7, facecolor=color, edgecolor="k")
    ax.add_collection3d(box)

# 🔍 Converte texto de posições: "Item[0]: X Y Z"
def parse_positions(raw_text):
    positions = {}
    for line in raw_text.strip().splitlines():
        match = re.match(r"Item\[(\d+)\]:\s*(\d+)\s+(\d+)\s+(\d+)", line)
        if match:
            idx, x, y, z = map(int, match.groups())
            positions[idx] = (x, y, z)
    return positions

# 🔍 Converte texto de dimensões: "Item[0]: W, H, D"
def parse_dimensions(raw_text):
    dimensions = {}
    for line in raw_text.strip().splitlines():
        match = re.match(r"Item\[(\d+)\]:\s*(\d+),\s*(\d+),\s*(\d+)", line)
        if match:
            idx, w, h, d = map(int, match.groups())
            dimensions[idx] = (w, h, d)
    return dimensions

# 🔍 Converte texto de cores: "Item[0]: R, G, B"
def parse_colors(raw_text):
    colors = {}
    for line in raw_text.strip().splitlines():
        match = re.match(r"Item\[(\d+)\]:\s*(\d+),\s*(\d+),\s*(\d+)", line)
        if match:
            idx, r, g, b = map(int, match.groups())
            colors[idx] = (r/255, g/255, b/255)  # Normaliza para 0-1
    return colors

# Junta tudo
def merge_items(positions, dimensions, colors=None):
    items = []
    all_ids = sorted(set(positions) & set(dimensions))
    for idx in all_ids:
        x, y, z = positions[idx]
        w, h, d = dimensions[idx]
        color = colors.get(idx) if colors and idx in colors else (random.random(), random.random(), random.random())
        items.append({"id": idx, "x": x, "y": y, "z": z, "w": w, "h": h, "d": d, "color": color})
    return items

# 📦 Plota o empacotamento
def plot_3d_packing(items, container_size):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.set_box_aspect([1, 1, 1])

    for item in items:
        draw_box(ax, item["x"], item["y"], item["z"], item["w"], item["d"], item["h"], item["color"])
        ax.text(item["x"] + item["w"] / 2,
                item["y"] + item["d"] / 2,
                item["z"] + item["h"] / 2,
                f'{item["id"]}', ha='center', va='center', fontsize=8)

    ax.set_xlim(0, container_size[0])
    ax.set_ylim(0, container_size[1])
    ax.set_zlim(0, container_size[2])
    ax.set_xlabel('X')
    ax.set_ylabel('Z')
    ax.set_zlabel('Y')
    plt.title("Empacotamento 3D")
    plt.tight_layout()
    plt.show()

# 🔧 Parâmetros
container = (30, 30, 30)

dim_items = """
Item[0]: 14, 21, 10
Item[1]: 7, 15, 15
Item[2]: 7, 9, 13
Item[3]: 9, 7, 5
"""

raw_items = """
Item[0]: 0 0 0
Item[1]: 14 0 0
Item[2]: 21 0 0
Item[3]: 14 0 15
"""

# Cores opcionais (RGB entre 0 e 255). Se não especificar um item aqui, ele terá cor aleatória.
raw_colors = """
Item[0]: 255, 0, 0
Item[1]: 0, 255, 0
Item[2]: 0, 0, 255
Item[3]: 0, 110, 155
"""

# 🚀 Execução
if __name__ == "__main__":
    positions = parse_positions(raw_items)
    dimensions = parse_dimensions(dim_items)
    colors = parse_colors(raw_colors)
    items = merge_items(positions, dimensions, colors)
    plot_3d_packing(items, container)
