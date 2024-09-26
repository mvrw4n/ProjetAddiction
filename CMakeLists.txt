cmake_minimum_required(VERSION 3.14)
project(ProjetAddiction)

# Trouver la bibliothèque Matplot++
find_package(Matplot++ REQUIRED)

# Ajouter l'exécutable
add_executable(my_target main.cpp UnePersonne.cpp)

# Lier Matplot++ à l'exécutable
target_link_libraries(my_target PRIVATE Matplot++::matplot)
