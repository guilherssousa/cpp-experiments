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
                _params[key_value_pair[0]] = key_value_pair[1];
            }
        }
        void add(std::string& key, std::string& value) {
            _params[key] = value;
        }
        void remove(std::string& key) {
            _params.erase(key);
        }
        std::string get(std::string& key) {
            return _params[key];
        }
        bool has(std::string& key) {
            return _params.find(key) != _params.end();
        }
        std::string toString() {
            std::string params_str = "";
            for (auto& param : _params) {
                params_str += param.first + "=" + param.second + "&";
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
    std::string params = "?a=1&b=2&c=3";
    url_search_params p = url_search_params(params);

    return 0;
}