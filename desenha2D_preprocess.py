import matplotlib.pyplot as plt
import re
import random

# 🔍 Parser das posições: "Item[0]: X Y"
def parse_positions(raw_text):
    positions = {}
    for line in raw_text.strip().splitlines():
        match = re.match(r"Item\[(\d+)\]:\s*(\d+)\s+(\d+)", line)
        if match:
            idx, x, y = map(int, match.groups())
            positions[idx] = (x, y)
    return positions

# 🔍 Parser das dimensões: "Item[0]: W, H, L" (usaremos apenas W e H para 2D)
def parse_dimensions(raw_text):
    dimensions = {}
    for line in raw_text.strip().splitlines():
        match = re.match(r"Item\[(\d+)\]:\s*(\d+),\s*(\d+),\s*(\d+)", line)
        if match:
            idx, w, h, _ = map(int, match.groups())
            dimensions[idx] = (w, h)
    return dimensions

# 🎨 Plota empacotamento 2D
def plot_2d_packing(items, container_size, duplicar_x=1):
    fig, ax = plt.subplots()
    
    # Container
    ax.set_xlim(0, container_size[0] * duplicar_x)
    ax.set_ylim(0, container_size[1])
    ax.set_aspect('equal')
    
    # Itens
    for item in items:
        x, y = item["x"], item["y"]
        w, h = item["w"], item["h"]
        color = item["color"]
        
        rect = plt.Rectangle((x, y), w, h, facecolor=color, edgecolor="black", alpha=0.6)
        ax.add_patch(rect)
        ax.text(x + w/2, y + h/2, f'{item["id"]}', ha="center", va="center", fontsize=8)
    
    # Grid
    ax.set_xticks(range(0, container_size[0]*duplicar_x + 1, 5))
    ax.set_yticks(range(0, container_size[1] + 1, 5))
    ax.grid(True, linestyle="--", linewidth=0.5, alpha=0.5)
    
    plt.title(f"Empacotamento 2D (X duplicado {duplicar_x}x)")
    plt.show()

# Junta posições e dimensões
def merge_items(positions, dimensions):
    items = []
    all_ids = sorted(set(positions) & set(dimensions))
    for idx in all_ids:
        x, y = positions[idx]
        w, h = dimensions[idx]
        color = (random.random(), random.random(), random.random())
        items.append({"id": idx, "x": x, "y": y, "w": w, "h": h, "color": color})
    return items


# 🔧 Exemplo de uso
raw_positions = """
Item[0]:9 7
Item[1]:4 5
Item[2]:1 3
Item[3]:11 6
Item[4]:10 2
"""

raw_dimensions = """
W 10 H 10 L 10
Item[0]:1, 1, 0
Item[1]:5, 5, 0
Item[2]:3, 3, 0
Item[3]:4, 4, 0
Item[4]:1, 1, 0
"""

container = (10, 10)  # largura e altura do container 2D
duplicar_x = 2        # número de vezes que o eixo X deve ser repetido

# 🚀 Execução
if __name__ == "__main__":
    positions = parse_positions(raw_positions)
    dimensions = parse_dimensions(raw_dimensions)
    items = merge_items(positions, dimensions)
    plot_2d_packing(items, container, duplicar_x)
