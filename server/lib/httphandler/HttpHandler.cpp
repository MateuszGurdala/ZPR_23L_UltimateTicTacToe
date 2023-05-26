#include "../../include/http/HttpHandler.hpp"


HttpResponse
HttpHandler::handle(const std::shared_ptr<HttpRequest> &request) {
  switch (request->getMethod()) {
  case OPTIONS:
    return handleOPTIONSRequest();
    break;
  case GET:
    return handleGETRequest(request);
    break;
  // case POST:
  // return handlePOSTRequest(request);
  // break;
  default:
    return HttpResponse::ERRORResponse("400", "INVALID REQUEST");
    break;
  }
}

HttpResponse HttpHandler::handleGETRequest(
    const std::shared_ptr<HttpRequest> &request) {

  const std::string endpoint = request->getEndpoint();

  /* Board State */
  if (endpoint == "/BoardState") {
    if(gameHandler)
    {
      return HttpResponse::GETResponse(gameHandler->BoardStateAsJson());
    }
    return HttpResponse::ERRORResponse("400", "Game not yet created");
  }
  /* Game State */
  else if (endpoint == "/GameState") {
    /*
        0 - Ready
        1 - Waiting
        2 - Ongoing
        3 - PlayerSolo
        4 - PlayerX
        5 - PlayerO
        6 - Unknown
    */
    if(gameHandler)
    {
      return HttpResponse::GETResponse(gameHandler->GameStateAsJson());
    }
    return HttpResponse::GETResponse("0");
  }
  /* Game Stage */
  else if (endpoint == "/GameStage") {
    /*
        "Your Turn",
        "Enemy Turn",
        "Pick Next Segment",
        "Enemy is Choosing Next Segment",
        "Game is Finished",
        "Unknown",
    */
    // TODO: Krystian
    // return HttpResponse::GETResponse(R"("Unknown")"); // State must be inside
    return HttpResponse::ERRORResponse("501", "NOT IMPLEMENTED");
  }
  /* Server Status */
  else if (endpoint == "/ServerStatus") {
    return HttpResponse::GETResponse(R"(true)");
  }
  /* End Game */
  else if (endpoint == "/EndGame") {
    if (verifyPlayer(request)) {
      std::string player = extractCookieValue(request);
      // TODO: Krystian
      // return HttpResponse::GETResponse(R"(true)");
      return HttpResponse::ERRORResponse("501", "NOT IMPLEMENTED");
    } else {
      return HttpResponse::ERRORResponse("401", "UNAUTHORIZED");
    }
  } else if (endpoint == "/MakeMove") {
    if (verifyPlayer(request)) {
      std::string player = extractCookieValue(request);
      std::string boardId = (request->queryParams)["boardId"];
      std::string segmentId = (request->queryParams)["segmentId"];
      // TODO: Krystian
      // return HttpResponse::GETResponse(R"(true)");
      return HttpResponse::ERRORResponse("501", "NOT IMPLEMENTED");
    } else {
      return HttpResponse::ERRORResponse("401", "UNAUTHORIZED");
    }
  }
  /* Pick Segment */
  else if (endpoint == "/PickSegment") {
    if (verifyPlayer(request)) {
      std::string player = extractCookieValue(request);
      std::string segmentNumber = (*request->headers)["segmentNumber"];
      // TODO: Krystian
      // return HttpResponse::GETResponse(R"(true)");
      return HttpResponse::ERRORResponse("501", "NOT IMPLEMENTED");
    } else {
      return HttpResponse::ERRORResponse("401", "UNAUTHORIZED");
    }
  }
  /* Create Game */
  else if (endpoint == "/CreateGame") {
    if (verifyPlayer(request)) {
      return HttpResponse::GETResponse(gameHandler->CreateGameAsJson(false));
    } else {
      std::string gameMode = (request->queryParams)["gameMode"];
      std::string playerSign = (request->queryParams)["playerSign"];
      std::string boardSize = (request->queryParams)["boardSize"];
      bool isPlayerVsComputer = false;
      char playerSignAsChar = playerSign.c_str()[0];
      if(playerSignAsChar != 'X' && playerSignAsChar != 'O')
      {
          return HttpResponse::ERRORResponse("400", "Invalid player "
                                                  "figure while creating game.");
      }
      if(gameMode == "Player")
      {
          isPlayerVsComputer = true;
      }
    gameHandler = std::make_unique<GameHandler>(std::stoi(boardSize), playerSignAsChar, isPlayerVsComputer);
    return HttpResponse::GETResponse(gameHandler->CreateGameAsJson(true));
    }
  }
  /* Invalid Endpoint */
  else {
    return HttpResponse::ERRORResponse("400", "BAD REQUEST");
  }
}

// HttpResponse HttpHandler::handlePOSTRequest(
//     const std::shared_ptr<HttpRequest> &request) const {

//   const std::string endpoint = request->getEndpoint();

//   ///* Make Move */
//   // if (endpoint == "/MakeMove")
//   //{
//   //	return HttpResponse::ERRORResponse("400", "NOT IMPLEMENTED");
//   // }
//   ///* Pick Segment */
//   // else if (endpoint == "/PickSegment")
//   //{
//   //	return HttpResponse::ERRORResponse("400", "NOT IMPLEMENTED");
//   // }
//   ///* Create Game */
//   // else if (endpoint == "/CreateGame")
//   //{
//   //	if (!verifyPlayer(request))
//   //	{
//   //		return HttpResponse::ERRORResponse("469", "UNAUTHORISED");
//   //	}
//   //	return HttpResponse::POSTResponse(R"(false)");;//Only true/false
//   // }
//   ///* Invalid Endpoint */
//   // else
//   //{
//   return HttpResponse::ERRORResponse("500", "NOT IMPLEMENTED");
//   //}
// }

HttpResponse HttpHandler::handleOPTIONSRequest() const {
  return HttpResponse::OPTIONSResponse();
}

bool HttpHandler::verifyPlayer(
    const std::shared_ptr<HttpRequest>& request) const {
  try {
    extractCookieValue(request);
    return true;
  } catch (const std::exception &) {
    return false;
  }
}

std::string HttpHandler::extractCookieValue(
    const std::shared_ptr<HttpRequest>& request) const {
  size_t p;
  std::string rawCookie;
  std::string cookie;
  std::string value;

  rawCookie = (*request->headers)["Cookie"];
  std::cout << rawCookie << "\n";

  if (!rawCookie.empty() && (p = rawCookie.find('=')) != std::string::npos) {
    cookie = rawCookie.substr(0, p);
    value = rawCookie.substr(p + 1, rawCookie.size());
  } else {
    throw std::exception();
  }

  if (cookie == "player" && std::find(std::begin(config::playerCookies),
                                      std::end(config::playerCookies), value) !=
                                std::end(config::playerCookies)) {
    return value;
  } else {
    throw std::exception();
  }
}
