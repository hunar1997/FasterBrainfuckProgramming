import glob

env = Environment()

env.Program(source=glob.glob('*.cpp'),
	target = 'bin/FBP',
	CXX = 'clang++-4.0',
	CXXFLAGS=['-g', '-std=c++11'])

