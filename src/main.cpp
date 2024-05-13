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

/*
Copyright (C) 2024 Sudospective

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
