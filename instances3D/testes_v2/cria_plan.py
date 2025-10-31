import pandas as pd

def ler_instancia(nome_arquivo):
    with open(nome_arquivo, 'r') as f:
        linhas = [linha.strip() for linha in f.readlines() if linha.strip()]
    
    # Linha 1: número da instância e seed (ignoramos a seed)
    _, _ = linhas[0].split()
    
    # Linha 2: dimensões do contêiner
    largura, altura, profundidade = map(int, linhas[1].split())
    volume_container = largura * altura * profundidade

    # Linha 3: número de tipos de itens
    n_tipos = int(linhas[2])

    # Linhas seguintes: tipos de itens
    itens = []
    for i in range(3, 3 + n_tipos):
        dados = list(map(int, linhas[i].split()))
        tipo = dados[0]
        largura_item = dados[1]
        altura_item = dados[3]
        profundidade_item = dados[5]
        quantidade = dados[7]
        volume_item = largura_item * altura_item * profundidade_item * quantidade

        itens.append({
            "Tipo": tipo,
            "Largura": largura_item,
            "Altura": altura_item,
            "Profundidade": profundidade_item,
            "Quantidade": quantidade,
            "Volume (total do tipo)": volume_item
        })

    # DataFrame de itens
    df_itens = pd.DataFrame(itens)
    volume_total_itens = df_itens["Volume (total do tipo)"].sum()

    preenchimento = volume_total_itens / volume_container

    resumo = {
        "Largura contêiner": largura,
        "Altura contêiner": altura,
        "Profundidade contêiner": profundidade,
        "Volume contêiner": volume_container,
        "Volume total itens": volume_total_itens,
        "Preenchimento total": preenchimento
    }

    return df_itens, resumo


def gerar_planilha():
    writer = pd.ExcelWriter("analise_instancias.xlsx", engine="openpyxl")

    resumos = []

    for i in range(1, 15):
        nome_arquivo = f"inst{i:02d}.txt"
        try:
            df_itens, resumo = ler_instancia(nome_arquivo)
            resumo["Instância"] = f"inst{i:02d}"
            resumos.append(resumo)

            # Salva a planilha da instância
            df_itens.to_excel(writer, sheet_name=f"Inst{i:02d}", index=False)
        except FileNotFoundError:
            print(f"Arquivo {nome_arquivo} não encontrado. Pulando...")

    # Adiciona um resumo geral
    df_resumo = pd.DataFrame(resumos)
    df_resumo.to_excel(writer, sheet_name="Resumo Geral", index=False)

    writer.close()
    print("Arquivo 'analise_instancias.xlsx' criado com sucesso!")


if __name__ == "__main__":
    gerar_planilha()
