include(FetchContent)

set(BUILD_POSTGRESQL_CONNECTOR ON)
FetchContent_Declare(sqlpp11
  GIT_REPOSITORY  https://github.com/rbock/sqlpp11
  GIT_TAG         0.64
)

add_subdirectory(sqlpp11)
