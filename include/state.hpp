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
    rates[idx2][idx1] = {bid, ask}; // invert to have rows corresponding to "from" and columns to "to"
  }

  void optimize() {
    // apsp on the rates matrix to update the costs
    int n = currencies_indices.size();
    for (int k = 0 ; k < n ; ++ k)
    {
      for (int i = 0 ; i < n ; ++ i)
      {
        for (int j = 0 ; j < n ; ++ j)
        {
          //if (i == j || i == k || k == j) continue;
          double new_bid_price = rates[i][k].first * rates[k][j].first;
          rates[i][j].first = std::min(rates[i][j].first, new_bid_price);
          double new_ask_price = rates[i][k].second * rates[k][j].second;
          rates[i][j].second = std::max(rates[i][j].second, new_ask_price);
        }
      }
    }
  }

  void show_rates() const {
    int n = currencies_indices.size();
    printf("     ");
    for (auto& k: currencies_indices)
      printf("     %s     ", k.first.c_str());
    printf("\n");
    auto it = currencies_indices.begin();
    for (int i = 0 ; i < n ; ++ i)
    {
      printf(" %s ", (it++)->first.c_str());
      for (int j = 0 ; j < n ; ++ j)
      {
        printf(" [%.2f %.2f] ", rates[i][j].first, rates[i][j].second);
      }
      printf("\n");
    }
  }

private:
  std::unordered_map<std::string, int> currencies_indices;
  std::vector<std::vector<std::pair<double, double>>> rates;
  std::vector<std::vector<std::pair<double, double>>> shortest_paths;
};

}
