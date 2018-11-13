cmake_minimum_required(VERSION 2.6)
set (PROJECT_NAME "algorithms")
project(${PROJECT_NAME})

message(STATUS platform )
message(STATUS ${PLATFORM} )

set( SOURCE_ROOT "src" )

include_directories( "${SOURCE_ROOT}/include" )

file( GLOB SOURCES "${SOURCE_ROOT}/source/*.cpp" )

add_library( 
	${PROJECT_NAME} STATIC 
	${SOURCES}
)

target_link_libraries(
	${PROJECT_NAME}
	kernel32.lib
	gdiplus.lib
)
