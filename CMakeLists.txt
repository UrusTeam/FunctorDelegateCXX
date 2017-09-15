set(CMAKE_LEGACY_CYGWIN_WIN32 0)

cmake_minimum_required (VERSION 2.6)
project (Hopter)

add_definitions(-DNUMARGS=${COUNTARGS})

set(Hopter_SRCS
    "${PROJECT_SOURCE_DIR}/src/Hopter.cpp"
)

set(HopterUrus_SRCS
    "${PROJECT_SOURCE_DIR}/src/HopterUrus.cpp"
)

# add the binary tree to the search path for include files
include_directories (
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}"
    )

# add the executable
add_executable(Hopter ${Hopter_SRCS})
add_executable(HopterUrus ${HopterUrus_SRCS})

install(TARGETS Hopter HopterUrus
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install)
