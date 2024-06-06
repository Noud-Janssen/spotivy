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

set(SOURCES
  src/main.cpp
  src/model/song.cpp
  src/driver/audio_base.cpp
  src/driver/audio_wav.cpp
  src/model/song_list_base.cpp
  src/model/playlist.cpp
  src/model/album.cpp
)

add_executable(spotivy ${SOURCES})
target_include_directories(spotivy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(spotivy 
    PRIVATE sfml-audio 
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)
target_compile_features(spotivy PRIVATE cxx_std_17)

install(TARGETS spotivy)