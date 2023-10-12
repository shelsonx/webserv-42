#pragma once

#include "AContext.hpp"
#include "StringUtils.hpp"
#include "VectorUtils.hpp"
#include "MapUtils.hpp"
#include "DirectivesCreator.hpp"
#include "LocationContextCreator.hpp"

class ServerContext : public AContext
{
public:
    ServerContext();
    ServerContext(ServerContext const & other);
    ~ServerContext();

    ServerContext& operator=(ServerContext const & other);
    bool ParseContext(std::string &content);
};