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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/939751984/Game.o \
	${OBJECTDIR}/_ext/939751984/GameLevel.o \
	${OBJECTDIR}/Prop.o \
	${OBJECTDIR}/src/Frame.o \
	${OBJECTDIR}/src/Tile.o \
	${OBJECTDIR}/src/TileMap.o \
	${OBJECTDIR}/src/TileSet.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dunkelheld ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/939751984/Game.o: /home/siapran/Programming/C++/SFML/Donker\ Held/src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939751984
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939751984/Game.o /home/siapran/Programming/C++/SFML/Donker\ Held/src/Game.cpp

${OBJECTDIR}/_ext/939751984/GameLevel.o: /home/siapran/Programming/C++/SFML/Donker\ Held/src/GameLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939751984
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939751984/GameLevel.o /home/siapran/Programming/C++/SFML/Donker\ Held/src/GameLevel.cpp

${OBJECTDIR}/Prop.o: Prop.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prop.o Prop.cpp

${OBJECTDIR}/src/Frame.o: src/Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Frame.o src/Frame.cpp

${OBJECTDIR}/src/Tile.o: src/Tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Tile.o src/Tile.cpp

${OBJECTDIR}/src/TileMap.o: src/TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TileMap.o src/TileMap.cpp

${OBJECTDIR}/src/TileSet.o: src/TileSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TileSet.o src/TileSet.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/tinyXML/tinystr.o: src/tinyXML/tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinystr.o src/tinyXML/tinystr.cpp

${OBJECTDIR}/src/tinyXML/tinyxml.o: src/tinyXML/tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxml.o src/tinyXML/tinyxml.cpp

${OBJECTDIR}/src/tinyXML/tinyxmlerror.o: src/tinyXML/tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxmlerror.o src/tinyXML/tinyxmlerror.cpp

${OBJECTDIR}/src/tinyXML/tinyxmlparser.o: src/tinyXML/tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tinyXML
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyXML/tinyxmlparser.o src/tinyXML/tinyxmlparser.cpp

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
