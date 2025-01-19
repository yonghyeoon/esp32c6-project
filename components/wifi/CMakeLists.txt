idf_component_register(SRCS "wifi.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_wifi wpa_supplicant esp_event nvs_flash freertos)