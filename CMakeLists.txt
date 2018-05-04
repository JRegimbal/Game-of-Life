project(Game-of-Life)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB source *.cpp *.h)
add_executable(gameoflife ${source})
