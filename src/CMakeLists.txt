add_executable(test)

target_link_libraries(test PRIVATE sqlpp11::postgresql)
include_directories(${pistache_SOURCE_DIR}/include)

target_sources(test
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/users.h
)
