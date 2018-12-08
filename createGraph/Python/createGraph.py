import sys
import os
import random

def createFile(filePath):
	fileName=filePath.split('/')[len(filePath.split('/'))-1]
	if not os.path.exists(filePath.replace(fileName, '')):
		os.makedirs(filePath.replace(fileName, ''))
	file=open(filePath, 'w')
	return file

def searchParameter(parameter, args):
	flag=False
	for i in args:
		if flag==True:
			return i
		elif i==parameter:
			flag=True
	help()

def help():
	if sys.argv[0]=='createGraph.py':
		print('{0} -t <tam_graph> -p <path_dir>\tor\tcreateGraph(<tam_graph>, <path_dir>) in another python3 file\ntam_graph min = 13'.format(sys.argv[0]))
	else:
		print('createGraph(<tam_graph>, <path_dir>)\ntam_graph min = 13')
	exit(0)

def createGraph(t, p):
	if t<13:
		help()
	file=createFile(p)
	fileStrings=''
	fileTam=0
	graph=[]
	dic={}
	for i in range(t):
		graph.append(i)
	for i in range(1, int(t/3)):
		fileStrings+=(''.join('{0} {1} {2} {3}\n'.format(0, i, random.randint(1, 20), random.randint(1, 20))))
		fileTam+=1
	graph.pop(0)
	for i in range(int(t/3), int(2*(t/3))):
		fileStrings+=(''.join('{0} {1} {2} {3}\n'.format(1, i, random.randint(1, 20), random.randint(1, 20))))
		fileTam+=1
	graph.pop(0)
	for i in range(int(2*(t/3)), t):
		fileStrings+=(''.join('{0} {1} {2} {3}\n'.format(2, i, random.randint(1, 20), random.randint(1, 20))))
		fileTam+=1
	graph.pop(0)
	tamAux=int(len(graph)/2)
	for i in range(tamAux):
		i1=random.randint(0, len(graph)-1)
		i2=random.randint(0, len(graph)-1)
		c=random.randint(1, 20)
		adj=''.join('{0} {1} {2} {3}\n'.format(graph[i1], graph[i2], c, random.randint(1, 20)))
		if not ''.join('{0} {1}\n'.format(graph[i1], graph[i2])) in dic and not ''.join('{1} {0}\n'.format(graph[i1], graph[i2])) in dic and not i1==i2:
			dic[''.join('{0} {1}\n'.format(graph[i1], graph[i2]))]=True
			dic[''.join('{1} {0}\n'.format(graph[i1], graph[i2]))]=True
			fileStrings+=(adj)
			fileTam+=1
			graph.pop(i1)
	for i in range(t):
		if len(graph)==0:
			continue
		i1=random.randint(0, len(graph)-1)
		i2=random.randint(0, len(graph)-1)
		c=random.randint(1, 20)
		adj=''.join('{0} {1} {2} {3}\n'.format(graph[i1], graph[i2], c, random.randint(1, 20)))
		if not ''.join('{0} {1}\n'.format(graph[i1], graph[i2])) in dic and not ''.join('{1} {0}\n'.format(graph[i1], graph[i2])) in dic and not i1==i2:
			dic[''.join('{0} {1}\n'.format(graph[i1], graph[i2]))]=True
			dic[''.join('{1} {0}\n'.format(graph[i1], graph[i2]))]=True
			fileStrings+=(adj)
			fileTam+=1
	file.write('{0} {1}\n'.format(t, fileTam))
	file.write(fileStrings)
	file.close()

if __name__=='__main__':
	if len(sys.argv)==5:
		createGraph(int(searchParameter('-t', sys.argv[1:])), searchParameter('-p', sys.argv[1:]))
	else:
		help()