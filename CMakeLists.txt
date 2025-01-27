# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.
cmake_minimum_required(VERSION 3.16)

project(PRG1_Recueil_Exercices)

set(CMAKE_CXX_STANDARD 20)

# Compilation options for warnings and errors
add_compile_options(-Wall -Wextra -Wpedantic -g)

# Add each exercise as a separate executable
# add_executable(ex3 "01 - Introduction/ex04.cpp")
# add_executable(ex4 "01 - Introduction/ex04_b.cpp")
add_executable(ex5 "02 - Elements de base/bouteille.cpp")
add_executable(ex6 "02 - Elements de base/piedsMiles.cpp")
add_executable(lab2 "quadraticSolver.cpp")
add_executable(ppmc "03 - Structures de Controle/ppmc.cpp")
add_executable(postch "03 - Structures de Controle/lieferungCHF.cpp")
add_executable(starry "03 - Structures de Controle/starryChrismas.cpp")
add_executable(pyra "04 - Fonctions/pyramideRectangulaire.cpp")
add_executable(borne2be "04 - Fonctions/bornes.cpp")
add_executable(bank "04 - Fonctions/bank.cpp")
add_executable(toFile "05 - Flux/fileText.cpp")
add_executable(pangram "04 - Fonctions/charTest.cpp")
add_executable(vektor "09 - Tableaux/vectorCalc.cpp")
add_executable(stack "09 - Tableaux/stack.cpp")
add_executable(matrix "11 - Classes/Matrix.cpp")
add_executable(carnet "10 - Surcharge et Genericite/carnet.cpp")
add_executable(surSpec "10 - Surcharge et Genericite/surSpec.cpp")
add_executable(counter "12 - iterator - algorithm - numeric/counter.cpp")
add_executable(genClass "13 - classe generique/genClass.cpp")
add_executable(genClassDot "13 - classe generique/genClassDot.cpp")
add_executable(quadDot "13 - classe generique/quadDot.cpp")
add_executable(naval "13 - classe generique/toucheCoule.cpp")
add_executable(self "13 - classe generique/selfExercise.cpp")
add_executable(remplacer "08 - Chaines de caracteres/remplacerMot.cpp")