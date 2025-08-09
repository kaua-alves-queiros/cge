add_executable(engine_test
    main.c
)

target_link_libraries(engine_test PRIVATE engine)