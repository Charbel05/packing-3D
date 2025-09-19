import matplotlib.pyplot as plt

def desenhar_quadrado(lado=30, linhas_tracejadas=None, mostrar_eixos=True, quadrados_internos=None):
    fig, ax = plt.subplots()

    # Quadrado principal
    ax.fill_between([0, lado], 0, lado, color="gray", alpha=0.5)
    ax.plot([0, lado, lado, 0, 0], [0, 0, lado, lado, 0], color="black", linewidth=1)

    # Quadrados internos
    if quadrados_internos:
        for (x, y, w, h, cor) in quadrados_internos:
            # Se a cor estiver em formato RGB (0-255), normaliza para (0-1)
            if isinstance(cor, tuple) and len(cor) == 3:
                cor = tuple(c/255 for c in cor)

            ax.fill_between([x, x+w], y, y+h, color=cor, alpha=0.5)
            ax.plot([x, x+w, x+w, x, x], [y, y, y+h, y+h, y], color=cor, linewidth=1)

    # Linhas tracejadas
    if linhas_tracejadas:
        for x in linhas_tracejadas:
            ax.plot([0, lado], [x, x], linestyle="--", color="black", linewidth=2)

    # Grid
    ax.set_xticks(range(0, lado+1, 10))
    ax.set_yticks(range(0, lado+1, 10))
    ax.grid(True, which="both", linestyle="-", linewidth=0.5, alpha=0.5)

    # Eixos
    if not mostrar_eixos:
        ax.axis("off")
    else:
        ax.axhline(0, color="black", linewidth=1)
        ax.axvline(0, color="black", linewidth=1)

    ax.set_aspect('equal', adjustable='box')
    plt.show()


# Exemplo com RGB
desenhar_quadrado(
    lado=10,
    linhas_tracejadas=[],
    mostrar_eixos=True,
    quadrados_internos=[
        (9, 7, 7, 1, (255, 0, 0)),    # vermelho
        (4, 5, 5, 5, (0, 255, 0)),    # verde
        (1, 3, 3, 3, (0, 0, 255)),    # azul
        (11, 6, 4, 4, (0, 110, 155)),  # azul petróleo
        (10, 2, 7, 1, (255, 0, 0)),    # vermelho
    ]
)
