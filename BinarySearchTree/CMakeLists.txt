file(GLOB SOURCE_LIB
        "src/*.h"
        "src/*.cpp"
        )

add_library(mapTemplate STATIC ${SOURCE_LIB})