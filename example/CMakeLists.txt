# Copyright (c) 2013, 2014, 2015 Corvusoft

project( "examples" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/example"  )

#
# Build
#
add_executable( basic_authentication basic_authentication/source/example.cpp )
target_link_libraries( basic_authentication ${CMAKE_PROJECT_NAME} )

add_executable( authentication authentication/source/example.cpp )
target_link_libraries( authentication ${CMAKE_PROJECT_NAME} )

add_executable( custom_status_codes custom_status_codes/source/example.cpp )
target_link_libraries( custom_status_codes ${CMAKE_PROJECT_NAME} )

add_executable( digest_authentication digest_authentication/source/example.cpp )
target_link_libraries( digest_authentication ${CMAKE_PROJECT_NAME} )

add_executable( error_handling error_handling/source/example.cpp )
target_link_libraries( error_handling ${CMAKE_PROJECT_NAME} )

add_executable( logging logging/source/example.cpp )
target_link_libraries( logging ${CMAKE_PROJECT_NAME} )

add_executable( path_parameters path_parameters/source/example.cpp )
target_link_libraries( path_parameters ${CMAKE_PROJECT_NAME} )

add_executable( publishing_resources publishing_resources/source/example.cpp )
target_link_libraries( publishing_resources ${CMAKE_PROJECT_NAME} )

add_executable( custom_methods custom_methods/source/example.cpp )
target_link_libraries( custom_methods ${CMAKE_PROJECT_NAME} )

add_executable( publishing_multipath_resources publishing_multipath_resources/source/example.cpp )
target_link_libraries( publishing_multipath_resources ${CMAKE_PROJECT_NAME} )

add_executable( resource_filtering resource_filtering/source/example.cpp )
target_link_libraries( resource_filtering ${CMAKE_PROJECT_NAME} )

add_executable( serving_html serving_html/source/example.cpp )
target_link_libraries( serving_html ${CMAKE_PROJECT_NAME} )

add_executable( transfer_encoding_request transfer_encoding_request/source/example.cpp )
target_link_libraries( transfer_encoding_request ${CMAKE_PROJECT_NAME} )

add_executable( transfer_encoding_response transfer_encoding_response/source/example.cpp )
target_link_libraries( transfer_encoding_response ${CMAKE_PROJECT_NAME} )

add_executable( persistent_connection persistent_connection/source/example.cpp )
target_link_libraries( persistent_connection ${CMAKE_PROJECT_NAME} )

add_executable( compression compression/source/example.cpp )
target_link_libraries( compression ${CMAKE_PROJECT_NAME} )

add_executable( http_service http_service/source/example.cpp )
target_link_libraries( http_service ${CMAKE_PROJECT_NAME} )

add_executable( service_ready_handler service_ready_handler/source/example.cpp )
target_link_libraries( service_ready_handler ${CMAKE_PROJECT_NAME} )

add_executable( session_data session_data/source/example.cpp )
target_link_libraries( session_data ${CMAKE_PROJECT_NAME} )

add_executable( rules_engine rules_engine/source/example.cpp )
target_link_libraries( rules_engine ${CMAKE_PROJECT_NAME} )

add_executable( multithreaded_service multithreaded_service/source/example.cpp )
target_link_libraries( multithreaded_service ${CMAKE_PROJECT_NAME} )

add_executable( schedule_work_on_service_runloop schedule_work_on_service_runloop/source/example.cpp )
target_link_libraries( schedule_work_on_service_runloop ${CMAKE_PROJECT_NAME} )

add_executable( bind_service_address bind_service_address/source/example.cpp )
target_link_libraries( bind_service_address ${CMAKE_PROJECT_NAME} )

add_executable( session_manager session_manager/source/example.cpp )
target_link_libraries( session_manager ${CMAKE_PROJECT_NAME} )

if ( PAM_FOUND )
    add_executable( pam_authentication pam_authentication/source/example.cpp )
    target_link_libraries( pam_authentication ${CMAKE_PROJECT_NAME} pam )
endif ( )

if ( SYSLOG_FOUND )
    add_executable( syslog_logging syslog_logging/source/example.cpp )
    target_link_libraries( syslog_logging ${CMAKE_PROJECT_NAME} )
endif ( )

if ( BUILD_SSL )
    add_executable( https_service https_service/source/example.cpp )
    target_link_libraries( https_service ${CMAKE_PROJECT_NAME} )
endif ( )

#
# Install
#
install( DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/example" DESTINATION ${CMAKE_INSTALL_PREFIX} FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE )
install( FILES "${CMAKE_SOURCE_DIR}/example/serving_html/resource/index.html" DESTINATION "resource" )
install( FILES "${CMAKE_SOURCE_DIR}/example/compression/resource/data.zlib" DESTINATION "resource" )
install( FILES "${CMAKE_SOURCE_DIR}/example/transfer_encoding_request/resource/request.txt" DESTINATION "resource" )
