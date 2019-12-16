cmake_minimum_required(VERSION 3.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(quizz)			# Название проекта

set(SOURCE_EXE quizz_main.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB quizz_library.cpp)			# Тоже самое, но для библиотеки

add_library(quizz_library STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(quizz_main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(quizz_main quizz_library)		# Линковка программы с библиотекой