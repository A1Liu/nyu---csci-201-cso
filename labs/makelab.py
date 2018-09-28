import os
from os.path import join,dirname,abspath
import argparse

labname = 'lab name'

README = 'README.md'
ASSIGN = 'assign.md'
MAIN = 'main.c'
TEMPLATE = 'template'

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

def format_line(string):
	global labname
	return string  \
		.replace('[labname]',labname.capitalize())

parser = argparse.ArgumentParser()
parser.add_argument('labname',default = labname,nargs='?')
args = parser.parse_args()
labname = args.labname

filedir = dirname(abspath(__file__))
labdir = join(filedir,labname.replace(' ',''))
srcdir = join(labdir,'src')
tempdir = join(filedir,TEMPLATE)

readme_text = map(format_line,getLines(README,tempdir))
assign_text = map(format_line,getLines(ASSIGN,tempdir))
main_text = getLines(MAIN,join(tempdir,'src'))

os.mkdir(labdir)
os.mkdir(srcdir)
os.mkdir(join(labdir,'in'))
os.mkdir(join(labdir,'out'))
mkfile(MAIN,main_text,srcdir)
mkfile(README,readme_text,labdir)
mkfile(ASSIGN,assign_text,labdir)
