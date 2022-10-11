set(SOURCES "hal_gpio.cpp")
set(DIRECTORIES "include" ".")

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${DIRECTORIES}
    REQUIRES esp8266
)

