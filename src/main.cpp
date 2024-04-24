#include "pages.h"

using Pistache::Http::Endpoint;

int main(int argc, char* argv[]) {
  unsigned long port = 9080;
  if (argc > 1) {
    port = std::stoul(argv[1]);
  }
  auto opts = Endpoint::options().flags(Pistache::Tcp::Options::ReuseAddr);
  Pistache::Address addr(Pistache::IP::any(), Pistache::Port(port));

  Pistache::Rest::Router router;
  Pages::CreateRoutes(router);

  Endpoint server(addr);
  server.init(opts);
  server.setHandler(router.handler());
  server.serve();
}
