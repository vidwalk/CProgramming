#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
# Change component name to change the name of the output
COMPONENT_NAME = TestList
# this works only on this pc, change the path according to where you have cpputest extracted from tar.gz
CPPUTEST_HOME = /home/vidwalk/Desktop/ESWProgramming/cpputest-3.8

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

#---Sources----#
#src of your C files
SRC_DIRS = \
	ApplicationLib
#src of your tests
TEST_SRC_DIRS = \
	AllTests

INCLUDE_DIRS =\
  .\
  ApplicationLib\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

