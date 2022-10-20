#pragma once

#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>


namespace fxwiz {

class state {
public:
  state(const std::vector<std::string>& c) : rates(c.size(), std::vector<std::pair<double, double>>(c.size(), {1.f, 1.f})) {
    int i = 0;
    for (auto& s : c)
    {
      currencies_indices[s] = i++;
    }
  }

  ~state() {
  }

  void update_rate(const std::string& key1, const std::string& key2, const double bid, const double ask) {
    int idx1 = currencies_indices[key1];
    int idx2 = currencies_indices[key2];
    rates[idx1][idx2] = {bid, ask};
  }

  void show_rates() const {
    int n = currencies_indices.size();
    for (int i = 0 ; i < n ; ++ i)
    {
      for (int j = 0 ; j < n ; ++ j)
      {
        printf("%f %f", rates[i][j].first, rates[i][j].second);
      }
      printf("\n");
    }
  }

private:
  std::unordered_map<std::string, int> currencies_indices;
  std::vector<std::vector<std::pair<double, double>>> rates;
};

}
