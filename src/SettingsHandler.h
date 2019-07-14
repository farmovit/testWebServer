#ifndef SETTINGSHANDLER_H
#define SETTINGSHANDLER_H

#include "FileHandler.h"

class SettingsHandler : public FileHandler
{
public:
    SettingsHandler(const std::string &root, CivetServer *server);
    bool handlePost(CivetServer *server, mg_connection *conn) override;
};

#endif // SETTINGSHANDLER_H
