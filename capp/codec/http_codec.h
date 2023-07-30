#pragma once
#include <netpoll/core.h>

#include "http_request.h"


namespace capp{
class HttpCodec
{
public:
   enum RequestParseState {
      kExpectRequestLine,
      kExpectHeaders,
      kExpectBody,
      kGotAll,
   };

   // Returns false if protocol resolution fails
   bool parse_request(const netpoll::MessageBuffer* buffer);

   bool parse_ok() { return state_ == kGotAll; }

   Request& request() { return request_; }

   void reset()
   {
      state_   = kExpectRequestLine;
      request_ = Request{};
   }

private:
   bool process_request_line(netpoll::StringView const& text);

   RequestParseState state_{kExpectRequestLine};
   Request           request_;
};
}