#include "isroseok/Rose.h"

#include <iostream>
#include <sstream>
#include <string>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

namespace Rose {
	static std::string toLower(std::string_view view) {
		std::string out;
		out.reserve(view.size());
		for (const char character: view)
			out.push_back(toupper(character));
		return out;
	}

	bool isOK() {
		std::ostringstream oss;

		curlpp::Cleanup cleanup;
		oss << curlpp::Options::Url("https://sus.190n.org/isroseok/");
		
		std::string response = oss.str();
		std::string_view view = response;

		const size_t h1_start = view.find("<h1>");
		if (h1_start == std::string_view::npos)
			throw std::runtime_error("Couldn't find <h1>");
		
		view.remove_prefix(h1_start + 4);

		const size_t h1_end = view.find("</h1>");
		if (h1_end == std::string_view::npos)
			throw std::runtime_error("Couldn't find </h1>");

		const std::string lower = toLower(view.substr(0, h1_end));
		return lower == "yes";
	}
}
