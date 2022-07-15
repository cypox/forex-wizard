# forex-wizard
Gets latest forex rates and find the best route to trade a given pair (either direct exchange or exchange through a set of other currencies).

Steps:
1. Parse market data and create the exchange matrix for a given set of currencies.
2. Use APSP to compute all earnings/losses for all possible exchanges.
3. Generate the list of buy/sell orders for the best route.

Test cases:
1. Historical forex data
2. Crypto currency on binance and integrate with API
