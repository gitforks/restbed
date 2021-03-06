/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <thread>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <functional>

//Project Includes
#include <restbed>
#include "http.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::thread;
using std::string;
using std::function;
using std::make_pair;
using std::shared_ptr;
using std::make_shared;

//Project Namespaces
using namespace restbed;

//External Namespaces

void xml_method_handler( const shared_ptr< Session > session )
{
    session->close( 1 );
}

void json_method_handler( const shared_ptr< Session > session )
{
    session->close( 2 );
}

SCENARIO( "resource method filters", "[resource]" )
{
    auto resource = make_shared< Resource >( );
    resource->set_path( "/resource" );
    resource->set_method_handler( "GET", { { "Content-Type", "application/xml" } }, xml_method_handler );
    resource->set_method_handler( "GET", { { "Content-Type", "application/json" } }, json_method_handler );
    
    auto settings = make_shared< Settings >( );
    settings->set_port( 1984 );
    settings->set_default_header( "Connection", "close" );
    
    shared_ptr< thread > worker = nullptr;
    
    Service service;
    service.publish( resource );
    service.set_ready_handler( [ &worker ]( Service & service )
    {
        worker = make_shared< thread >( [ &service ] ( )
        {
            GIVEN( "I publish a resource with 'Content-Type' header filters of 'application/json' and 'application/xml'" )
            {
                WHEN( "I perform a HTTP 'GET' request to '/resource' with header 'Content-Type: application/xml'" )
                {
                    Http::Request request;
                    request.port = 1984;
                    request.host = "localhost";
                    request.path = "/resource";
                    request.headers.insert( make_pair( "Content-Type", "application/xml" ) );
                    
                    auto response = Http::get( request );
                    
                    THEN( "I should see a '1' (XML) status code" )
                    {
                        REQUIRE( 1 == response.status_code );
                    }
                }
                
                WHEN( "I perform a HTTP 'GET' request to '/resource' with header 'Content-Type: application/json'" )
                {
                    Http::Request request;
                    request.port = 1984;
                    request.host = "localhost";
                    request.path = "/resource";
                    request.headers.insert( make_pair( "Content-Type", "application/json" ) );
                    
                    auto response = Http::get( request );
                    
                    THEN( "I should see a '2' (JSON) status code" )
                    {
                        REQUIRE( 2 == response.status_code );
                    }
                }
                
                service.stop( );
            }
        } );
    } );
    
    service.start( settings );
    worker->join( );
}
