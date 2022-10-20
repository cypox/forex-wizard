#include "retriever.hpp"
#include "parser.hpp"
#include "state.hpp"

#include <iostream>


int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " URL" << std::endl;
    return 0;
  }

  fxwiz::retriever r;
  std::string res = r.fetch(argv[1]);

  //fxwiz::parser p;
  //p.parse_content(res);

  //const fxwiz::state& s = p.get_state();
  //s.show_rates();

  fxwiz::state test_state({"EUR", "USD", "GBP"});
  test_state.update_rate("EUR", "USD", 0.97825, 0.97842);
  test_state.update_rate("EUR", "GBP", 0.87155, 0.87173);
  test_state.update_rate("USD", "EUR", 1.12200, 1.12245);
  test_state.update_rate("USD", "GBP", 0.89094, 0.89114);
  test_state.update_rate("GBP", "EUR", 1.14700, 1.14725);
  test_state.update_rate("GBP", "USD", 1.12216, 1.12241);
  test_state.show_rates();
  test_state.optimize();
  test_state.show_rates();

  return 0;
}
