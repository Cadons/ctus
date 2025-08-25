#ifndef INCLUDE_HTTP_REQUEST_H_
#define INCLUDE_HTTP_REQUEST_H_

/*
 * Copyright (c) 2024 Matteo Cadoni
 * This file is part of libtusclient, licensed under the MIT License.
 * See the LICENSE file in the project root for more information.
 */
#include <string>
#include <map>
#include "ctus.h"
#include <functional>
using std::string;
using std::map;
using std::function;


namespace TUS::Http {
    enum class EXPORT_LIBTUSCLIENT HttpMethod {
        _GET,
        _POST,
        _PUT,
        _PATCH,
        _DELETE,
        _HEAD,
        _OPTIONS
    };

    /**
     * @brief Represents a HTTP request
     */
    class EXPORT_LIBTUSCLIENT Request {
    public:
        using SuccessCallback = std::function<void(std::string header, std::string data)>;
        using ErrorCallback = std::function<void(std::string header, std::string data)>;

        Request();

        explicit Request(std::string url);

        Request(std::string url, std::string body);

        Request(std::string url, std::string body, HttpMethod method);

        Request(std::string url, std::string body, HttpMethod method, map<string, string> headers);

        Request(std::string url, std::string body, HttpMethod method, map<string, string> headers,
                SuccessCallback onSuccessCallback);

        Request(std::string url, std::string body, HttpMethod method, map<string, string> headers,
                SuccessCallback onSuccessCallback, ErrorCallback onErrorCallback);

        /**
         * @brief Copy constructor
         */
        Request(const Request &request);

        Request &operator=(const Request &request);

        /**
         * @brief Add a header to the request
         * @param header The header to be added
         */
        void addHeader(const std::string &key, const std::string &value);

        /**
         * @brief Add the Authorization header to the request
         * @param berearToken The token to be added to the header
         */
        void autorizationHeader(const std::string &berearToken);

        [[nodiscard]] std::string getUrl() const;

        [[nodiscard]] std::string getBody() const;

        [[nodiscard]] HttpMethod getMethod() const;

        [[nodiscard]] map<string, string> getHeaders() const;

        void setOnSuccessCallback(SuccessCallback onSuccessCallback);

        void setOnErrorCallback(ErrorCallback onErrorCallback);

        [[nodiscard]] SuccessCallback getOnSuccessCallback() const;

        [[nodiscard]] ErrorCallback getOnErrorCallback() const;

    private:
        std::string url;
        std::string body;
        HttpMethod method;
        map<string, string> headers;
        SuccessCallback m_onSuccessCallback;
        ErrorCallback m_onErrorCallback;


        static SuccessCallback defaultSuccessCallback();

        static ErrorCallback defaultErrorCallback();
    };
}


#endif  // INCLUDE_HTTP_REQUEST_H_
