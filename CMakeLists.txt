cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(IP_PROJECT_NAME        "IP_xlsx_creator")

# Преобразование каждого небуквенно-циферного символа на входе в символ подчеркивания
string(MAKE_C_IDENTIFIER ${IP_PROJECT_NAME} IP_PROJECT_NAME)
# Изменение регистра на (ПРОПИСНЫЕ)
string(TOUPPER           ${IP_PROJECT_NAME} IP_PROJECT_NAME)

# -------------- Определяет является ли данные проект подпроектом --------------
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(${IP_PROJECT_NAME}_SUBPROJECT ON)
endif()
# ------------------------------------------------------------------------------
project(${IP_PROJECT_NAME} DESCRIPTION "Консольное приложение для создания счёта на оплату")

set(SOURCES src/main.cpp)                               # Исходные файлы


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME}      PROPERTIES
    CXX_STANDARD                                   17   # CXX - стандарт
    CXX_STANDARD_REQUIRED                          ON   # Обязательная поддержка стандарта
)

# ------------ Подведение итогов настроек, напечатанных при сборке -------------
message(STATUS "===== Окончательный обзор для ${PROJECT_NAME} =====")
message(STATUS "  Description:   ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "  Compiler:      ${CMAKE_CXX_COMPILER}")
# ------------------------------------------------------------------------------