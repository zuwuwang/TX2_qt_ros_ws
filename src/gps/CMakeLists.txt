cmake_minimum_required(VERSION 2.8.3)
project(gps)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

link_directories(${${PROJECT_NAME}_SOURCE_DIR}/lib)

catkin_package(
)

include_directories(
  include/${PROJECT_NAME}
  ${catkin_INCLUDE_DIRS}
)
add_executable(gps_response src/gps.cpp)


target_link_libraries(
   gps_response
   ${catkin_LIBRARIES} 
 )


