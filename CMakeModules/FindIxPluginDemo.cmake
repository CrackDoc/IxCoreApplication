SET(IxPluginDemo_DIR ${CMAKE_INSTALL_PREFIX}/IxPluginDemo CACHE STRING "settting IxPluginDemo_DIR path" FORCE)

#SET(IxPluginDemo_DIR "" CACHE PATH "Location of IxPluginDemo")

FIND_PATH(IxPluginDemo_INCLUDE_DIR IxPluginDemoExport.h
	${IxPluginDemo_DIR}/include
    "${IxPluginDemo_DIR}/Public Headers"
    "$ENV{IxPluginDemo_PATH}/Public Headers"
    $ENV{IxPluginDemo_PATH}
    $ENV{IxPluginDemo_DIR}/include
    $ENV{IxPluginDemo_DIR}
    /usr/local/include
	/usr/local/IxPluginDemo/include
    /usr/include
	/usr/IxPluginDemo/include
	/opt/include
    /opt/local/IxPluginDemo/include
    /opt/IxPluginDemo/include
    "C:/IxPluginDemo/include"
	"C:/Program Files/IxPluginDemo/include"
)
MACRO(FIND_IxPluginDemo_LIBRARY MYLIBRARY MYLIBRARYNAME )

FIND_LIBRARY(${MYLIBRARY}
    NAMES
        ${MYLIBRARYNAME}
PATHS
	${IxPluginDemo_DIR}/lib
    $ENV{IxPluginDemo_PATH}
    $ENV{IxPluginDemo_DIR}/lib
    $ENV{IxPluginDemo_DIR}
    /usr/local/lib
	/usr/local/IxPluginDemo/lib
    /usr/lib
	/usr/IxPluginDemo/lib
	/opt/lib
    /opt/local/IxPluginDemo/lib
    /opt/IxPluginDemo/lib
    "C:/IxPluginDemo/lib"
	"C:/Program Files/IxPluginDemo/lib"
)
ENDMACRO(FIND_IxPluginDemo_LIBRARY LIBRARY LIBRARYNAME)

FIND_IxPluginDemo_LIBRARY(IxPluginDemo_LIBRARY IxPluginDemo )
FIND_IxPluginDemo_LIBRARY(IxPluginDemo_LIBRARY_DEBUG IxPluginDemod)

SET(IxPluginDemo_FOUND FALSE)
IF (IxPluginDemo_INCLUDE_DIR AND IxPluginDemo_LIBRARY)
   SET(IxPluginDemo_FOUND TRUE)
ENDIF (IxPluginDemo_INCLUDE_DIR AND IxPluginDemo_LIBRARY)
