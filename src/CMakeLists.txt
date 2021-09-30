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

add_executable (test_read.test
    tests/test_read.c
    )
target_link_libraries(test_read.test light_pcapng_static)

add_executable (test_read_write.test
    tests/test_read_write.c
    )
target_link_libraries(test_read_write.test light_pcapng_static)

add_executable (test_mem.test
    tests/test_mem.c
    )
target_link_libraries(test_mem.test light_pcapng_static)

add_executable (test_histogram.test
    tests/test_histogram.c
    )
target_link_libraries(test_histogram.test light_pcapng_static)

add_executable (test_subcapture.test
    tests/test_subcapture.c
    )
target_link_libraries(test_subcapture.test light_pcapng_static)

add_executable (test_feature.test
    tests/test_feature.c
    )
target_link_libraries(test_feature.test light_pcapng_static)

add_executable (test_flow.test
    tests/test_flow.c
    )
target_link_libraries(test_flow.test light_pcapng_static)

add_executable (test_feature_advanced.test
    tests/test_feature_advanced.c
    )
target_link_libraries(test_feature_advanced.test light_pcapng_static dl)

add_executable (test_read_packets.test
    tests/test_read_packets.c
    )
target_link_libraries(test_read_packets.test light_pcapng_static)

add_executable (test_read_write_packets.test
    tests/test_read_write_packets.c
    )
target_link_libraries(test_read_write_packets.test light_pcapng_static)
