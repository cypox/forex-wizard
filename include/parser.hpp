#pragma once

#include "state.hpp"


namespace fxwiz {

class parser {
public:
  parser() : current_rates({"EUR", "USD"}) {
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
