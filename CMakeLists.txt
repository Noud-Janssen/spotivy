cmake_minimum_required(VERSION 3.16)
project(spotivy LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# --- Fetch SFML --------------------------------------------------------------


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
# ------------------------------------------------------------------------------



# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCES
  src/controller/music.cpp
  src/model/song.cpp
  src/debug_client.cpp
  src/driver/audio_base.cpp
  src/driver/audio_wav.cpp
  src/model/song_list_base.cpp
  src/model/playlist.cpp
  src/model/album.cpp
  src/model/artist.cpp
  src/model/queue.cpp
  src/model/user.cpp
)

set(TEST_SOURCES
  test/model/song.cpp
  test/model/album.cpp
  test/model/queue.cpp
  test/model/user.cpp
)

add_executable(spotivy src/main.cpp ${SOURCES})
target_include_directories(spotivy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(spotivy 
PRIVATE sfml-audio 
PRIVATE ftxui::screen
PRIVATE ftxui::dom
PRIVATE ftxui::component
)
target_compile_features(spotivy PRIVATE cxx_std_17)

add_executable(spotivy_test ${SOURCES} ${TEST_SOURCES})
target_include_directories(spotivy_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(spotivy_test
  PRIVATE sfml-audio 
  GTest::gtest_main
)
target_compile_features(spotivy_test PRIVATE cxx_std_17)


install(TARGETS spotivy)