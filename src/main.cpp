#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <cstdlib>

int main() {
	namespace http = boost::beast::http;

    try {
          boost::asio::io_context context;
          boost::asio::ip::tcp::resolver resolver{context};
          boost::beast::tcp_stream stream{context};

          const auto host = "https://api.github.com";
          const auto endpoint =
              "/repos/rust-lang-nursery/rust-cookbook/stargazers";
          boost::asio::ip::tcp::resolver::query query{host, "http"};
          const auto results = resolver.resolve(query);

          stream.connect(results);

          http::request<http::string_body> request{http::verb::get, endpoint,
                                                   11};
          request.set(http::field::host, host);
          request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

          http::write(stream, request);

          boost::beast::flat_buffer buffer;

          http::response<http::dynamic_body> result;

          http::read(stream, buffer, result);

          std::cout << result << std::endl;

          boost::beast::error_code ec;
          stream.socket().shutdown(boost::asio::ip::tcp::socket::shutdown_both,
                                   ec);

          if (ec && ec != boost::beast::errc::not_connected) {
            throw boost::beast::system_error{ec};
          }
    } catch (const std::exception& e) {
          std::cerr << "Error: " << e.what() << std::endl;
          return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}

