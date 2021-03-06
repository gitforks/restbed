# Copyright (c) 2013, 2014, 2015 Corvusoft

find_path( catch_INCLUDE catch.hpp HINTS "${CMAKE_SOURCE_DIR}/dependency/catch/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

if ( catch_INCLUDE )
    set( CATCH_FOUND TRUE )

    message( STATUS "${Green}Found Catch include at: ${catch_INCLUDE}${Reset}" )
else ( )
    message( FATAL_ERROR "${Red}Failed to locate Catch dependency.${Reset}" )
endif ( )
