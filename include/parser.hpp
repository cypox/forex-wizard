#pragma once

#include "state.hpp"


namespace fxwiz {

class parser {
public:
  parser(const std::vector<std::string>& c) : current_rates(c) {
  }

  ~parser () {
  }

  const state& get_state() const {
    return current_rates;
  }

  void parse_content(const std::string& content) {
    std::cout << content << std::endl;
  }

private:
  state current_rates;
};

}
