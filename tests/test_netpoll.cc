#define ENABLE_ELG_LOG
#include <elog/logger.h>
#include <netpoll/core.h>

struct server
{
   NETPOLL_TCP_CONNECTION(conn)
   {
      if (conn->connected())
      {
         conn->send("connect ok!");
         ELG_INFO("connected:{}", conn->peerAddr().toIpPort());
      }
      else { ELG_INFO("disconnected:{}", conn->peerAddr().toIpPort()); }
   }
   NETPOLL_TCP_MESSAGE(conn, buffer)
   {
      auto msg = buffer->readAll();
      ELG_INFO("recv:{}", msg);
      conn->send(msg);
   }
};

int main()
{
   elog::GlobalConfig::Get().setLevel(elog::kTrace);
   auto loops    = netpoll::NewEventLoop();
   auto listener = netpoll::tcp::Listener::New({8888});
   listener.bind<server>();
   listener.enableKickoffIdle(2);
   loops.serve(listener);
}
