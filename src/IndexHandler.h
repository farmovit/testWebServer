#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include "FileHandler.h"

class IndexHandler : public FileHandler
{
public:
    IndexHandler(const std::string &root, CivetServer *server);
    bool handlePost(CivetServer *server, mg_connection *conn) override;
};

#endif // INDEXHANDLER_H
