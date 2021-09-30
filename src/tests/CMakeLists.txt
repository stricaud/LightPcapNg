add_executable (test_read.test
    test_read.c
    )
target_link_libraries(test_read.test light_pcapng_static)

add_executable (test_read_write.test
    test_read_write.c
    )
target_link_libraries(test_read_write.test light_pcapng_static)

add_executable (test_mem.test
    test_mem.c
    )
target_link_libraries(test_mem.test light_pcapng_static)

add_executable (test_histogram.test
    test_histogram.c
    )
target_link_libraries(test_histogram.test light_pcapng_static)

add_executable (test_subcapture.test
    test_subcapture.c
    )
target_link_libraries(test_subcapture.test light_pcapng_static)

add_executable (test_feature.test
    test_feature.c
    )
target_link_libraries(test_feature.test light_pcapng_static)

add_executable (test_flow.test
    test_flow.c
    )
target_link_libraries(test_flow.test light_pcapng_static)

add_executable (test_feature_advanced.test
    test_feature_advanced.c
    )
target_link_libraries(test_feature_advanced.test light_pcapng_static dl)

add_executable (test_read_packets.test
    test_read_packets.c
    )
target_link_libraries(test_read_packets.test light_pcapng_static)

add_executable (test_read_write_packets.test
    test_read_write_packets.c
    )
target_link_libraries(test_read_write_packets.test light_pcapng_static)

