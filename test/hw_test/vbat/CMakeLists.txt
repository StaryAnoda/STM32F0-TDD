cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE Toolchain-arm-gcc.cmake)

# Allow assembler
enable_language(ASM)

project(vbat_hw_test)

set(INCLUDE_DIRS
    external/stm32
    external/cmsis
	
	src
    
    ../..
    ../../../src
)

set(C_SRCS
    src/app/output/output.c
    src/hw/startup/system_stm32f0xx.c
   
    src/hw/uart/uart.c
	
	src/main.c

    src/vbat_test.c
    src/vbat_test_runner.c

    ../../../src/vbat.c

    ../../unity/core/unity.c
	../../unity/fixture/unity_fixture.c
)

set(ASM_SRCS
    src/hw/startup/startup_stm32f030x6.s
)

set(GLOBAL_DEFINES
    -DSTM32F030x6
    -DUNITY_INCLUDE_CONFIG_H
)

set(LINKED_LIBS

)

link_directories(

)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

include(compiler_flags.cmake)

# generate elf file
add_arm_executable(${CMAKE_PROJECT_NAME} ${C_SRCS} ${ASM_SRCS})

arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})
