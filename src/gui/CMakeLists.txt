project(cbGUI)

set(Cerebra_LIBRARIES ${Cerebra_LIBRARIES} ${PROJECT_NAME} PARENT_SCOPE)
set(INCLUDE_OUTPUT_PATH ${INCLUDE_OUTPUT_PATH} ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

# CMake version requirements
cmake_minimum_required(VERSION 2.8)

# Mandatory policy setting
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

# use what QVTK built with
set(QT_MOC_EXECUTABLE ${VTK_QT_MOC_EXECUTABLE} CACHE FILEPATH "")
set(QT_QMAKE_EXECUTABLE ${VTK_QT_QMAKE_EXECUTABLE} CACHE FILEPATH "")

# The library name, dependencies, and source files
set(LIB_NAME ${PROJECT_NAME})
set(LIB_DEPS
  ${ITK_LIBRARIES}
  ${QT_LIBRARIES}
  QVTK
  vtkCommon
  vtkRendering
  vtkToolCursor
  cbView
  cbData
  vtkToolCursor
  cbVTK
  )

set(LIB_SRCS
  qvtkViewToolCursorWidget.cxx
  cbMainWindow.cxx
  cbApplicationController.cxx
  cbStage.cxx
  cbStageManager.cxx
)

set(CEREBRA_QT_HEADER
  qvtkViewToolCursorWidget.h
  cbMainWindow.h
  cbApplicationController.h
  cbStage.h
  cbStageManager.h
 )

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${MAINFOLDER}/src/view"
  "${MAINFOLDER}/src/data"
  "${MAINFOLDER}/thirdparty/toolcursor"
)

# Create a list of header files (source files that end in .h)
set(LIB_HDRS)
foreach(source_file ${LIB_SRCS})
  get_filename_component(file_extension ${source_file} EXT)
  if("${file_extension}" STREQUAL ".h")
    set(LIB_HDRS ${LIB_HDRS} ${source_file})
  endif()
endforeach()

# Let CMake know which sources have .h without a .cxx
if(LIB_HDRS)
  set_source_files_properties(${LIB_HDRS} HEADER_FILE_ONLY)
endif()

# Use moc to generate the Qt signals and slots
qt4_wrap_cpp(MOCSrcs ${CEREBRA_QT_HEADER})
source_group("Generated" FILES ${MOCSrcs})

# Create the library
add_library(${LIB_NAME} ${LIB_SRCS} ${MOCSrcs})
target_link_libraries(${LIB_NAME} ${LIB_DEPS})

export(TARGETS ${LIB_NAME}
  APPEND FILE "${CONFIGURE_OUTPUT_PATH}/CerebraTargets.cmake")
