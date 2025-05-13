cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
project(FullBuild VERSION 1.0.0)

# Add subdirectories for Valkron and Sandbox
add_subdirectory(Valkron)
add_subdirectory(Sandbox)