#include <curl/curl.h>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>

void press_a() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=A");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_b() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=B");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_start() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Start");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_select() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Select");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_up() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Up");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_down() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Down");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_left() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Left");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_right() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=Right");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_l() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=L");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

void press_r() {
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5000/mgba-http/button/tap?key=R");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Enable POST
    CURLcode res = curl_easy_perform(curl);
    printf("Response: %d\n", res);
    curl_easy_cleanup(curl);
  }
}

int main() {
  press_right();
  Sleep(200);
  press_right();
  Sleep(200);
  press_right();
  Sleep(200);
  press_right();
  Sleep(200);
  press_right();
  Sleep(200);
  press_up();
  Sleep(200);
  press_up();
  Sleep(200);
  press_up();
  Sleep(200);
  press_up();
  Sleep(200);
  press_up();
  Sleep(200);
  press_left();
  Sleep(200);
  press_left();
  Sleep(200);
  press_left();
  Sleep(200);
  press_left();
  Sleep(200);
  press_left();
  Sleep(200);
  press_down();
  Sleep(200);
  press_down();
  Sleep(200);
  press_down();
  Sleep(200);
  press_down();
  Sleep(200);
  press_down();
  Sleep(200);
  return 0;
}