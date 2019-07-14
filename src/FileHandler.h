#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "CivetServer.h"
#include <string>

class FileHandler : public CivetHandler
{
public:
    FileHandler(std::string fileName, std::string root, CivetServer *server);
    bool handleGet(CivetServer *server, mg_connection *conn) override;
    bool handlePost(CivetServer *server, mg_connection *conn) override;
private:
    void registerHandler(CivetServer *server);
private:
    std::string mFileName;
    std::string mRoot;
};

#endif // FILEHANDLER_H
