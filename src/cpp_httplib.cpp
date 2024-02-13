#include <exception>
#include <print>
// Not needed probably thanks to the installation with vcpkg
//#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>


int main() {
  // const auto host = "https://api.github.com";
  const auto host = "jsonplaceholder.typicode.com";
  httplib::SSLClient client(host, 443); 

  const httplib::Headers headers {
    { "User-Agent", "cpp-httplib" }
  };
  // const auto response = client.Get("/repos/rust-lang-nursery/rust-cookbook/stargazers", headers);
  const auto response = client.Get("/posts", headers);
  if (response) {
    std::println("Status: {0}\nBody: {1}", response->status, response->body);
  } else {
    std::println("HTTP error: {}", httplib::to_string(response.error()));
  }

}
