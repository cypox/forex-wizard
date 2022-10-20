#include <curl/curl.h>

#include <stdexcept>
#include <cstring>
#include <sstream>
#include <iostream>


namespace fxwiz {

class retriever {
public:
  retriever() {
    curl = curl_easy_init();
    if (!curl)
    {
      throw std::runtime_error("cannot initialize curl!\n");
    }
  }

  ~retriever() {
    // Cleanup
    curl_easy_cleanup(curl);
  }

  std::string& fetch(const std::string& url) const {
    response_buffer.clear();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Write result into the buffer
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_buffer);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);

    return response_buffer;
  }

private:
  static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
  {
    size_t realsize = size * nmemb;
    std::string *s = (std::string*)userp;
    s->append((char*)contents, realsize);
    return realsize;
  }

  CURL* curl;
  mutable std::string response_buffer;
};

}
