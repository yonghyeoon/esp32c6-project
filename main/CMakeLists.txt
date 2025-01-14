file(GLOB SRC_FILES 
  main.c
  ap/src/*.c
  bsp/src/*.c
  hw/drivers/src/*.c
  hw/drivers/led/src/*.c
)

# file(GLOB_RECURSE SRC_FILES_RECURSE
#   common/*.c
# )

set(requires 
   "led_strip" 
   "vfs"
   "nvs_flash"
)

idf_component_register(
    SRCS ${SRC_FILES}
    INCLUDE_DIRS "ap/include"
    INCLUDE_DIRS "bsp/include"
    INCLUDE_DIRS "common"
    INCLUDE_DIRS "hw/include"
    INCLUDE_DIRS "hw/drivers/led/include"
    )
