import sys

def searchParameter(parameter, args):
	flag=False
	for i in args:
		if flag==True:
			return i
		elif i==parameter:
			flag=True
	help()

def help():
	print('{0} -t <tam_graph> -p <path_dir>\ntam_graph min = 13'.format(sys.argv[0]))
	exit(0)

def createGraph(t, p):
	if t<13:
		help()
	pass

if __name__=='__main__':
	if len(sys.argv)==5:
		createGraph(int(searchParameter('-t', sys.argv[1:])), searchParameter('-p', sys.argv[1:]))
	else:
		help()