# Octree OpenGL test
Тест рендера вокселями с помощью октодеревьев
Графика отрисовывается через OpenGL (glew + glfw)

Компилируется только под linux. Для других осей придётся изменить флаги в Makefile.

# Зависимости
Компилятор - g++
Сборка - make
Библиотеки - GLEW, GLFW

# Компиляция
Компиляция происходит через Makefile

Release:
`make`
Debug:
`make debug`
Test (debug версия, которая сразу запускается)
`make test`

# Запуск
Запускать из корневой папки проекта.

Release:
`./build/main`
Debug:
`./debug_build/main`

# Управление
W/S/A/D/Q/E - Вперёд/Назад/Влево/Вправо/Вверх/Вниз
Мышь - вращать камеру
ЛКМ/ПКМ - ставить/стирать куб
Колесо мыши - менять размеры куба, который будем ставить
1/2 - показать/спрятать куб, который показывает, куда поставится после ЛКМ
