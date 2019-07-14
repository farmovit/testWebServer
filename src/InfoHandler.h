#ifndef INFOHANDLER_H
#define INFOHANDLER_H

#include "FileHandler.h"

class InfoHandler : public FileHandler
{
public:
    InfoHandler(const std::string &root, CivetServer *server);
    bool handlePost(CivetServer *server, mg_connection *conn) override;
};

#endif // INFOHANDLER_H
