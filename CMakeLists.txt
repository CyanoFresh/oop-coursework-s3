cmake_minimum_required(VERSION 3.15)
project(coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(coursework
        main.cpp
        Date.cpp Date.h
        Customer.cpp Customer.h
        Product.cpp Product.h
        Order.cpp Order.h
        DailyReport.cpp DailyReport.h
        ValidationException.h
        ./table/Appearance.cpp
        ./table/Appearance.h
        ./table/ATable.h
        ./table/Cell.cpp
        ./table/Cell.h
        ./table/Column.cpp
        ./table/Column.h
        ./table/ConstColumn.cpp
        ./table/ConstColumn.h
        ./table/DefaultAppearance.h
        ./table/DefaultCells.h
        ./table/Object.cpp
        ./table/Object.h
        ./table/SimpleColumn.cpp
        ./table/SimpleColumn.h
        ./table/Table.cpp
        ./table/Table.h
        ./table/TableExceptions.h
        Array.h
        table/ATable.h)