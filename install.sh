#!/bin/bash

# === Настройки ===
PROJECT_NAME="2d-FIRST-pre-alpha-game"
BUILD_DIR="build"
LIBS_DIR="libs"
SFML_VERSION="3.0"  # Укажите нужную версию SFML, например 3.0 или 2.6

# Функция для обработки ошибок
handle_error() {
    echo "❌ Ошибка на этапе $1"
    exit 1
}

# === Создаём структуру проекта ===
mkdir -p $BUILD_DIR $LIBS_DIR || handle_error "создания структуры проекта"

# === Устанавливаем SFML ===
echo "🔧 Установка SFML..."
if [ ! -d "$LIBS_DIR/SFML" ]; then
    git clone --depth=1 https://github.com/SFML/SFML.git $LIBS_DIR/SFML || handle_error "клонирования репозитория SFML"
    cd $LIBS_DIR/SFML || handle_error "перехода в каталог SFML"
    cmake -S . -B build -DCMAKE_INSTALL_PREFIX=../../$LIBS_DIR/SFML-install || handle_error "сборки SFML"
    cmake --build build --target install || handle_error "установки SFML"
    cd ../../ || handle_error "возврата в корневой каталог"
fi

# === Создаём CMakeLists.txt ===
echo "📄 Генерация CMakeLists.txt..."
cat <<EOF > CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project($PROJECT_NAME VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Пути к SFML
set(SFML_DIR "\${CMAKE_SOURCE_DIR}/$LIBS_DIR/SFML-install/lib/cmake/SFML")

# Используем SFML 3.0 или 2.6 в зависимости от переменной SFML_VERSION
if (\${SFML_VERSION} STREQUAL "3.0")
    find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED)
elseif (\${SFML_VERSION} STREQUAL "2.6")
    find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
else()
    message(FATAL_ERROR "Unsupported SFML version: \${SFML_VERSION}")
endif()

add_executable($PROJECT_NAME 
    game/main.cpp 
    game/Player.cpp 
    game/Enemy.cpp 
    game/Fireball.cpp
)

target_include_directories($PROJECT_NAME PRIVATE game $LIBS_DIR/SFML-install/include)
target_link_libraries($PROJECT_NAME PRIVATE sfml-graphics sfml-window sfml-system)

EOF
if [ $? -ne 0 ]; then
    handle_error "генерации CMakeLists.txt"
fi

# === Компиляция проекта ===
echo "⚙️ Компиляция проекта..."

cd $BUILD_DIR || handle_error "перехода в каталог сборки"

cmake .. || handle_error "инициализации CMake"
cmake --build . || handle_error "сборки проекта"

cd .. || handle_error "возврата в корневой каталог"

echo "✅ Проект собран! Запуск: ./$BUILD_DIR/$PROJECT_NAME"
