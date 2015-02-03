#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Actor.o \
	${OBJECTDIR}/src/Controller.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/GameLevel.o \
	${OBJECTDIR}/src/GameObject.o \
	${OBJECTDIR}/src/Paintable.o \
	${OBJECTDIR}/src/Prop.o \
	${OBJECTDIR}/src/Tile.o \
	${OBJECTDIR}/src/TileMap.o \
	${OBJECTDIR}/src/TileSet.o \
	${OBJECTDIR}/src/Trigger.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/tinyXML/tinystr.o \
	${OBJECTDIR}/src/tinyXML/tinyxml.o \
	${OBJECTDIR}/src/tinyXML/tinyxmlerror.o \
	${OBJECTDIR}/src/tinyXML/tinyxmlparser.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib `pkg-config --libs sfml-all`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Actor.o: src/Actor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Actor.o src/Actor.cpp

${OBJECTDIR}/src/Controller.o: src/Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Controller.o src/Controller.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/GameLevel.o: src/GameLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameLevel.o src/GameLevel.cpp

${OBJECTDIR}/src/GameObject.o: src/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameObject.o src/GameObject.cpp

${OBJECTDIR}/src/Paintable.o: src/Paintable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Paintable.o src/Paintable.cpp

${OBJECTDIR}/src/Prop.o: src/Prop.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Prop.o src/Prop.cpp

${OBJECTDIR}/src/Tile.o: src/Tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Tile.o src/Tile.cpp

${OBJECTDIR}/src/TileMap.o: src/TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TileMap.o src/TileMap.cpp

${OBJECTDIR}/src/TileSet.o: src/TileSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TileSet.o src/TileSet.cpp

${OBJECTDIR}/src/Trigger.o: src/Trigger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Trigger.o src/Trigger.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/tinyXML/tinystr.o: src/tinyXML/tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinystr.o src/tinyXML/tinystr.cpp

${OBJECTDIR}/src/tinyXML/tinyxml.o: src/tinyXML/tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxml.o src/tinyXML/tinyxml.cpp

${OBJECTDIR}/src/tinyXML/tinyxmlerror.o: src/tinyXML/tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxmlerror.o src/tinyXML/tinyxmlerror.cpp

${OBJECTDIR}/src/tinyXML/tinyxmlparser.o: src/tinyXML/tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include `pkg-config --cflags sfml-all` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxmlparser.o src/tinyXML/tinyxmlparser.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
