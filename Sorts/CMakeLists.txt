project(Sorts)

set(HEADER_FILES
        sortsPointers.h
        sortsRegular.h
        )

set(SOURCE_FILES
        sortsRegular.cpp
        )

add_library(Sorts STATIC ${SOURCE_FILES} ${HEADER_FILES})