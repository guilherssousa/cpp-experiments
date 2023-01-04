#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include "string_utils.h"

class url_search_params {
    public:
        url_search_params(std::string& params_str) {
            std::string::size_type pos = params_str.find("?");
            if (params_str.find("?") != std::string::npos) {
                params_str = params_str.substr(pos + 1);
            }

            std::vector<std::string> params_list = split(params_str, '&');

            // print params_list
            for (auto& param : params_list) {
                std::vector<std::string> key_value_pair = split(param, '=');
                _params[key_value_pair.at(0)] = key_value_pair.at(1);
            }
        }
        url_search_params(std::unordered_map<const char*, const char*> params) {
            for (auto& param : params) {
                _params[param.first] = param.second;
            }
        }
        void add(const char& key, const char& value) {
            std::string str1(1, key);
            std::string str2(1, value);
            _params[str1] = str2;
        }
        void remove(const char& key) {
            std::string str1(1, key);
            _params.erase(str1);
        }
        std::string get(const char& key) {
            std::string str1(1, key);
            return _params[str1];
        }
        bool has(const char& key) {
            std::string str1(1, key);
            return _params.find(str1) != _params.end();
        }
        std::string toString() {
            std::string params_str = "";
            unsigned int i = 0;
            for (auto& param : _params) {
                if(i > 0) {
                    params_str += "&";
                }
                params_str += param.first + "=" + param.second;
                ++i;
            }
            return params_str;
        }
        void clear() {
            _params.clear();
        }
    private:
        // Params should not be acessible directly, so we use a private member.
        std::unordered_map<std::string, std::string> _params;
};

int main() {
    url_search_params p = url_search_params({
        std::make_pair("name", "John"),
        std::make_pair("age", "30"),
    });

    std::cout << p.toString() << std::endl;

    return 0;
}