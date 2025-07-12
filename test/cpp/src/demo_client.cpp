#include <memory>

#include "gen-cpp/Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using std::shared_ptr;

int main(int argc, char** argv) {
  std::shared_ptr<TSocket> socket(new TSocket("localhost", 9090)); //注意此处的ip和端口
  std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  transport->open();

  // 我们的代码写在这里
  //********添加部分***********
  Student s;
  s.sno = 123;
  s.sname = "xiaoshe";
  s.ssex = 1;
  s.sage = 30;
  ServClient client(protocol);
  client.put(s);

  s.sno = 456;
  client.put(s);
  //********添加部分***********

  transport->close();
  return 0;
}
