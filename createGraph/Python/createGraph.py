import sys
import os

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
	#TODO
	file.close()

if __name__=='__main__':
	if len(sys.argv)==5:
		createGraph(int(searchParameter('-t', sys.argv[1:])), searchParameter('-p', sys.argv[1:]))
	else:
		help()