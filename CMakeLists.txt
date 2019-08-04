cmake_minimum_required(VERSION 3.10)

project(vm LANGUAGES C VERSION 0.1.0)

# Compile Application

set(SOURCES "src/main.c"
            "src/execute.c"
            "src/signal.c")

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE c_std_99)

# Install Application

install(TARGETS ${PROJECT_NAME}
        DESTINATION bin)