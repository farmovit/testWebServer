#include "FileHandler.h"
#include <fstream>
#include <iostream>

FileHandler::FileHandler(std::string fileName, std::string root, CivetServer *server)
    : mFileName(std::move(fileName)),
      mRoot(std::move(root)) {
    registerHandler(server);
}

void FileHandler::registerHandler(CivetServer *server) {
    if (server == nullptr) {
        return;
    }
    const auto url = std::string("/") + mFileName;
    server->addHandler(url, this);
    std::cout << "Url " << url << " was registred" << std::endl;
}

bool FileHandler::handleGet(CivetServer *server, mg_connection *conn) {
    auto file = mRoot + "/" + mFileName;
    if (!std::ifstream(file)) {
        mg_printf(conn,
                  "HTTP/1.1 200 OK\r\nContent-Type: "
                  "text/html\r\nConnection: close\r\n\r\n");
        mg_printf(conn, "<html><body>\r\n");
        mg_printf(conn,
                  "<h2>This page has been deleted</h2>\r\n");
        mg_printf(conn, "</body></html>\r\n");

    } else {
        mg_send_file(conn, file.c_str());
    }
    return true;
}

bool FileHandler::handlePost(CivetServer *server, mg_connection *conn) {
    mg_printf(conn,
              "HTTP/1.1 200 OK\r\nContent-Type: "
              "text/html\r\nConnection: close\r\n\r\n");
    mg_printf(conn, "<html><body>\r\n");
    mg_printf(conn,
              "<h2>post requests is not supported for this type of handler</h2>\r\n");
    mg_printf(conn, "</body></html>\r\n");
    return true;
}
