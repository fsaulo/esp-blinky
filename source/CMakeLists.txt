set(SOURCES "blink.cpp")
set(DIRECTORIES "." "include")

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${DIRECTORIES}
    REQUIRES freertos esp_common pthread spi_flash hal
)
