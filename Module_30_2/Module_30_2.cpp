#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response response = cpr::Get(cpr::Url{"http://httpbin.org/html"}, cpr::Header{{"accept", "text/html"}});
    std::string html = response.text;

    std::string articleTitle;
    std::size_t startPos = html.find("<h1>");
    std::size_t endPos = html.find("</h1>");
    if (startPos != std::string::npos && endPos != std::string::npos) {
        std::size_t titleStartPos = startPos + 4; // length of "<h1>" is 4
        std::size_t titleLength = endPos - titleStartPos;
        articleTitle = html.substr(titleStartPos, titleLength);
    }

    std::cout << "Article Title: " << articleTitle << std::endl;
    return 0;

}
