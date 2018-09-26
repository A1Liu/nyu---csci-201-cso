import os
from os.path import join,dirname,abspath

labname = 'lab1'

README = 'README.md'
ASSIGN = 'assign.md'
MAIN = 'main.c'

def getLines(file, dirname = None):
	if dirname is not None:
		file = join(dirname,file)
	file = open(file,'r')
	lines = file.readlines()
	file.close()
	return lines

def mkfile(file, lines, dirname = None):
	if dirname is not None:
		file = join(dirname, file)
	file = open(file,'a')
	file.writelines(lines)
	file.close()

filedir = dirname(abspath(__file__))
labdir = join(filedir,labname)
srcdir = join(labdir,'src')
tempdir = join(filedir,'template')

readme_text = getLines(README,tempdir)
assign_text = getLines(ASSIGN,tempdir)
main_text = getLines(MAIN,join(tempdir,'src'))


os.mkdir(labdir)
os.mkdir(srcdir)
os.mkdir(join(labdir,'in'))
os.mkdir(join(labdir,'out'))
mkfile(MAIN,main_text,srcdir)
mkfile(README,readme_text,labdir)
mkfile(ASSIGN,assign_text,labdir)
