#include "network.h"
#include "lightbulb.h"

static const char*    server_ip   = "127.0.0.1";
static const uint16_t server_port = 5005;

int main() {

	netSetup(server_ip, server_port);
	netRead();

	return 0;
}
