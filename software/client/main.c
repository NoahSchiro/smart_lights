#include "network.h"
#include "lightbulb.h"

static const char*    server_ip   = "192.0.0.1";
static const uint16_t server_port = 6969;

int main() {

	lbCommand(255, 255, 255);
	lbCommand(255, 255, 0);
	lbCommand(255, 0, 0);
	lbCommand(0, 0, 0);

	netSetup(server_ip, server_port);

	return 0;
}