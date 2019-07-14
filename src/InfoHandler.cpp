#include "InfoHandler.h"

namespace {
std::string fileName = "info.html";
} // namespace

InfoHandler::InfoHandler(const std::string &root, CivetServer *server)
    : FileHandler(fileName, root, server) {
}

bool InfoHandler::handlePost(CivetServer *server, mg_connection *conn) {
    mg_printf(conn,
              "HTTP/1.1 200 OK\r\nContent-Type: "
              "text/html\r\nConnection: close\r\n\r\n");
    mg_printf(conn, "<html><body>\r\n");
    mg_printf(conn,
              "<h2>INFO POST HANDLER!</h2>\r\n");
    mg_printf(conn, "</body></html>\r\n");
    return true;
}
