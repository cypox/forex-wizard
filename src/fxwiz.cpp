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

  fxwiz::parser p;
  p.parse_content(res);

  const fxwiz::state& s = p.get_state();
  s.show_rates();

  return 0;
}
