cmake_minimum_required(VERSION 3.0.2)
project(Events)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("Include")

SET (EVENTS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Include CACHE STRING "Events Include Directory")

#file(GLOB_RECURSE EVENT_FILES "Source/*.cpp")

add_executable(ObjectDemo Demo/ObjectDemo.cpp)
add_executable(CommandDemo Demo/CommandDemo.cpp)
add_executable(AdvancedDemo Demo/AdvancedCommands.cpp)
add_executable(EventHandlers Demo/EventHandlerDemo.cpp)