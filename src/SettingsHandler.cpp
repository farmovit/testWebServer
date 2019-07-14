#include "SettingsHandler.h"

namespace {
std::string fileName = "settings.html";
} // namespace

SettingsHandler::SettingsHandler(const std::string &root, CivetServer *server)
    : FileHandler(fileName, root, server) {
}

bool SettingsHandler::handlePost(CivetServer *server, mg_connection *conn) {
    // TODO
    return FileHandler::handlePost(server, conn);
}
