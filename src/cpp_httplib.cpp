#include <print>
// Not needed probably thanks to the installation with vcpkg
//#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>


void handleRequest(const auto& response) {
  if (response) {
    std::println("Status: {0}\nBody: {1}", response->status, response->body);
  } else {
    std::println("HTTP error: {}", httplib::to_string(response.error()));
  }
}


int main() {
  // const auto host = "https://api.github.com";
  const auto host = "jsonplaceholder.typicode.com";
  httplib::SSLClient client{host}; 

  std::println("====== GET request test ======");
  const httplib::Headers headers {
    { "User-Agent", "cpp-httplib" }
  };
  // const auto response = client.Get("/repos/rust-lang-nursery/rust-cookbook/stargazers", headers);
  handleRequest(client.Get("/posts", headers));

  std::println("====== PUT request test ======");
  const httplib::Headers headers2 {
    { "User-Agent", "cpp-httplib" },
    { "Content-type", "application/json; charset=UTF-8"}
  };
  handleRequest(client.Put("/posts/1", headers, "{\n \"id\": 1,\n \"title\": \"foo\",\n \"body\": \"bar\",\n \"userId\": 1\n}", "application/json"));
}

