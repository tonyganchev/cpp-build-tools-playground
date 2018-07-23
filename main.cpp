#include "server_config.hpp"

#include <iostream>

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/asyncrt_utils.h>
#include <cpprest/uri.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class server {
public:
	server(uri endpoint_uri) : listener_(endpoint_uri) {
		listener_.support(methods::GET, std::bind(&server::handle_get, this, std::placeholders::_1));
	}
	void start() {
		listener_.open().wait();
	}
	void stop() {
		listener_.close().wait();
	}
private:
	void handle_get(http_request req) {
		req.reply(status_codes::OK, "Sample REST response.");
	}
	http_listener listener_;
};

int main() {

	auto endpoint_uri = U("http://localhost:8080/sample-api");
	server srv(endpoint_uri);

	srv.start();
	std::wcout << U("Listeing on: ") << endpoint_uri << U(". Press ENTER to end process.") << std::endl;
	std::cin.get();
	srv.stop();

	return 0;
}
