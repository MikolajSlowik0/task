cmake_minimum_required(VERSION 3.6.0)

project(TietoGra VERSION 1.0.0)

add_executable(TietoGra
    commands.cpp
    game.cpp
    production.cpp
    status.cpp
    map.cpp
    main.cpp
)

target_include_directories(TietoGra
    PRIVATE
        ${TietoGra_SOURCE_DIR}
)

target_compile_features(TietoGra
    PRIVATE
        cxx_std_17
)