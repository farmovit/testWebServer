#include <CivetServer.h>
#include "IndexHandler.h"
#include "InfoHandler.h"
#include "SettingsHandler.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>

using namespace std::literals;

namespace {
constexpr auto blockTimeout = 100ms;
constexpr auto port = 8081;
std::string root = "/media/wrk/HttpServer/html";
std::vector<std::string> options = {"document_root", root, "listening_ports", std::to_string(port)};
} // namespace

bool isInterrupted = false;

int main(int argc, char *argv[]) {
    try {
        signal(SIGINT, [](int sig) { isInterrupted = true; });
        signal(SIGTERM, [](int sig) { isInterrupted = true; });
        CivetServer server(options);
        IndexHandler h_index(root, &server);
        InfoHandler h_info(root, &server);
        SettingsHandler h_settings(root, &server);
        server.addHandler("", h_index);
        while (!isInterrupted) {
            std::this_thread::sleep_for(blockTimeout);
        }
        return 0;
    } catch (const CivetException &exception) {
        std::cerr << "Got Civet exception: " << exception.what() << std::endl;
        return 1;
    } catch (const std::exception &exception) {
        std::cerr << "Got exception: " << exception.what() << std::endl;
        return 2;
    } catch (...) {
        std::cerr << "Got undined exception" << std::endl;
        return 3;
    }
}
