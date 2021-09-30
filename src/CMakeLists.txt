set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/include/ -Wall -O2 -fPIC -DUNIVERSAL -g")

add_library (light_pcapng SHARED
    light_compression.c
    light_null_compression.c
    light_zstd_compression.c
    light_io.c
    light_pcapng.c
    light_pcapng_cont.c
    light_platform.c
    light_manipulate.c
    light_internal.c
    light_alloc.c
    light_advanced.c
    light_option.c
    light_pcapng_ext.c
    )

add_library (light_pcapng_static STATIC
    light_compression.c
    light_null_compression.c
    light_zstd_compression.c
    light_io.c
    light_pcapng.c
    light_pcapng_cont.c
    light_platform.c
    light_manipulate.c
    light_internal.c
    light_alloc.c
    light_advanced.c
    light_option.c
    light_pcapng_ext.c
    )

add_subdirectory(tests)
