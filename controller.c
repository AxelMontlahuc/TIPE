#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=A");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");  // Empty data, or add "key=value" if needed
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
  return 0;
}