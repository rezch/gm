cmake_minimum_required(VERSION 3.23)
project(gm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(dist/json)
include_directories(include)
include_directories(include/json)

add_executable(gm
        dist/json/json-forwards.h
        dist/json/json.h
        dist/jsoncpp.cpp
        include/json/allocator.h
        include/json/assertions.h
        include/json/config.h
        include/json/forwards.h
        include/json/json.h
        include/json/json_features.h
        include/json/reader.h
        include/json/value.h
        include/json/version.h
        include/json/writer.h
        allitems.h
        consoleapp.h
        CREATURES.H
        effects.h
        enemies.h
        items.h
        items_list.h
        itemsdrop.h
        locations.h
        main.cpp
        map.h
        menuoptions.h
        progress_save.h
        pve.h
        trader.h)
