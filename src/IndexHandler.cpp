#include "IndexHandler.h"

namespace {
std::string fileName = "index.html";
} // namespace

IndexHandler::IndexHandler(const std::string &root, CivetServer *server)
    : FileHandler(fileName, root, server) {
}

bool IndexHandler::handlePost(CivetServer *server, mg_connection *conn) {
    mg_printf(conn,
              "HTTP/1.1 200 OK\r\nContent-Type: "
              "text/html\r\nConnection: close\r\n\r\n");
    mg_printf(conn, "<html><body>\r\n");
    mg_printf(conn,
              "<h2>INDEX POST HANDLER!</h2>\r\n");
    mg_printf(conn, "</body></html>\r\n");
    return true;
}
