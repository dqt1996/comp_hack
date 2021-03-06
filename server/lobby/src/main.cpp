/**
 * @file server/lobby/src/main.cpp
 * @ingroup lobby
 *
 * @author COMP Omega <compomega@tutanota.com>
 *
 * @brief Main lobby server file.
 *
 * This file is part of the Lobby Server (lobby).
 *
 * Copyright (C) 2012-2016 COMP_hack Team <compomega@tutanota.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// lobby Includes
#include "LoginWebHandler.h"
#include "LobbyServer.h"

// libcomp Includes
#include <Log.h>

// Civet Includes
#include <CivetServer.h>

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    libcomp::Log::GetSingletonPtr()->AddStandardOutputHook();

    std::vector<std::string> options;
    options.push_back("listening_ports");
    options.push_back("10999");

    CivetServer webServer(options);
    webServer.addHandler("/", new lobby::LoginHandler);

    LOG_INFO("COMP_hack Lobby Server v0.0.1 build 1\n");
    LOG_INFO("Copyright (C) 2010-2016 COMP_hack Team\n\n");

    lobby::LobbyServer server("any", 10666);

    return server.Start();
}
