/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _RESTBED_DETAIL_RESPONSE_IMPL_H
#define _RESTBED_DETAIL_RESPONSE_IMPL_H 1

//System Includes
#include <map>
#include <memory>
#include <string>

//Project Includes
#include "corvusoft/restbed/byte.hpp"

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    
    namespace detail
    {
        //Forward Declarations
        
        struct ResponseImpl
        {
            Bytes m_body { };
            
            double m_version = 1.1;
            
            int m_status_code = 200;
            
            std::string m_protocol = "HTTP";
            
            std::string m_status_message = "";
            
            std::multimap< std::string, std::string > m_headers { };
        };
    }
}

#endif  /* _RESTBED_DETAIL_RESPONSE_IMPL_H */
