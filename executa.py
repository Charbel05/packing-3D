import os

nome_teste = 'resultados'
# $instance será substituido pelo nome da instancia
#ARGUMENTO 1 = INSTANCIA
comando = os.path.join('x64', 'Release', 'packing-3D.exe') + ' $instance'

instance_folder = 'instances3D/'
instances_names = ['inst07.txt']

def levalor(texto,arquivo):
  pin = arquivo.find(texto)
  if pin == -1:
    return ""
  pfin = arquivo.find('\n',pin)
  tamanho = len(texto)
  return  arquivo[pin+tamanho:pfin]
    
#Criando diretorio dos resultados
if not os.path.exists(nome_teste):
  #print("Criando folder " + nome_teste)
  os.makedirs(nome_teste)
  
for i in instances_names:
  cmd = comando.replace("$instance", instance_folder + i)
  #não tenho certeza se esse ">" funciona no windows
  cmd = cmd + ' > ' + os.path.join(nome_teste, i + '.sol')
  #print('Executando: ' + cmd)
  os.system(cmd)
  
#print()
print('Instance\tStatus\tSolution\tTime(s)')

for i in instances_names:
  solution_file_name = nome_teste + '/' + i + '.sol'
  file_ins = open(solution_file_name, "r")
  f = file_ins.read()
  sta = levalor("STATUS: ", f)
  sol = levalor("NBINS: ", f)
  tim = levalor("TIME: ", f)
  print(i + '\t' + sta + '\t' + sol + '\t' + tim)