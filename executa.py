import os, re, pandas as pd

def parse_solution_file(filepath):
    results = []
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    # Divide pelo marcador "Morrendo" (fim de cada execução)
    blocks = content.strip().split("Morrendo")
    
    for block in blocks:
        block = block.strip()
        if not block:
            continue

        # Captura TIME e STATUS
        time_match = re.search(r"TIME:\s*([\d.]+)", block)
        status_match = re.search(r"STATUS:\s*(\d+)", block)

        time_val = float(time_match.group(1)) if time_match else None
        status_val = int(status_match.group(1)) if status_match else None
        
        results.append({
            "TIME": time_val,
            "STATUS": status_val,
        })

    return results


nome_teste = 'resultados_comDominio'
comando = os.path.join('x64', 'Release', 'packing-3D.exe') + ' $instance' + ' 2'

instance_folder = 'instances3D/'
instances_names = ['inst01.txt', 'inst02.txt', 'inst03.txt', 'inst03B.txt', 'inst04.txt', 'inst04B.txt', 'inst04C.txt', 'inst04D.txt', 'inst05.txt', 'inst05B.txt', 'inst06.txt', 'inst07.txt']
# instances_names = ['toy.txt']

# Criando diretório dos resultados
if not os.path.exists(nome_teste):
    os.makedirs(nome_teste)

# Executa as instâncias
for i in instances_names:
    cmd = comando.replace("$instance", instance_folder + i)
    cmd = cmd + ' > ' + os.path.join(nome_teste, i + '.sol')
    os.system(cmd)

print('Instance\tStatus\tSolution\tTime(s)')

all_results = []

for inst in instances_names:
    arquivo_path = os.path.join(nome_teste, inst + ".sol")
    dados = parse_solution_file(arquivo_path)
    for d in dados:
        d["INSTANCE"] = inst  
        all_results.append(d)

df = pd.DataFrame(all_results)
saida_csv = "resultados_comDominio.csv"
df.to_csv(saida_csv, index=False, encoding="utf-8")

print(f"✅ Resultados extraídos e salvos em '{saida_csv}'")
print(df)
