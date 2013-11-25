/*
 * TestEpollerServer.cc
 *
 *  Created on: Nov 21, 2013
 *      Author: lvanlv
 */

#include <boost/bind.hpp>

#include <EventLoop.h>
#include <InetAddress.h>
#include <TcpServer.h>

using namespace netlib::net;

class TestServer
{
public:
	TestServer(EventLoop* loopPtr, const InetAddress& addr)
		: loopPtr_(loopPtr),
		  server_(loopPtr_, addr, "test")
	{
		server_.setConnetionCallback(boost::bind(&TestServer::onConnection, this, _1));
		server_.setThreadNum(0);
	}

	void start()
	{
		server_.start();
	}

private:
	void  onConnection(const TcpConnectionPtr& conn)
	{
		conn->send("changjiang  changjiang  wo shi huang he \n");
	}

	void message()
	{

	}

private:
	EventLoop* loopPtr_;
	TcpServer server_;
};

int main(int argc, char* argv[])
{
	InetAddress listenAddress("127.0.0.1", 6886);
	EventLoop loop;


}


