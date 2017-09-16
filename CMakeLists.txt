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

set(testdelegate_SRCS
    "${PROJECT_SOURCE_DIR}/src/testdelegate.cpp"
)

# add the binary tree to the search path for include files
include_directories (
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
     )

# add the executable
add_executable(HopterUrus ${HopterUrus_SRCS})
add_executable(Hopter ${Hopter_SRCS})
add_executable(testdelegate ${testdelegate_SRCS})

add_custom_command(TARGET HopterUrus
                   POST_BUILD
                   COMMAND ${PROJECT_BINARY_DIR}/HopterUrus ${PROJECT_SOURCE_DIR}/include/FastFunctor.hxx ${PROJECT_SOURCE_DIR}/FastFunctor.h)

add_custom_command(TARGET Hopter
                   POST_BUILD
                   COMMAND ${PROJECT_BINARY_DIR}/Hopter ${PROJECT_SOURCE_DIR}/include/FastDelegate.hxx ${PROJECT_SOURCE_DIR}/FastDelegate.h)

install(TARGETS Hopter HopterUrus testdelegate
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install)
