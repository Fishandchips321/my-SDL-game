#pragma once
#include <string>

namespace TCP_IP
{
	enum protocols
	{
		echo,
		handshake//used to establish connection. TCP/UDP decided here (as i can't be bothered implementing it here :P)
	};

	class MAC
	{
	public:
		void operator=(std::string address);
		void operator=(MAC address);
		bool operator==(MAC eq);
		unsigned char MACaddress[6];
	};

	class IPv4
	{
	public:
		void operator=(std::string address);
		void operator=(IPv4 address);
		bool operator==(IPv4 eq);
		unsigned char IPv4address[4];
	};

	class packet
	{
	public:
		packet();
		bool encapsulate(std::string data, IPv4 source, IPv4 dest, unsigned int protocol);
		void unencapsulate(std::string* data, IPv4* source, IPv4* dest, int* ttl, int* protocol, int* DLength);
		IPv4 source, destination;
		std::string data;
		unsigned char *BPacket;
		/*
		Source - 4 bytes
		destination address - 4 bytes
		ttl - 1 byte
		length of data - 1 bytes
		data - 1 to 255 bytes
		*/
	};

	class frame
	{
	public:
		frame();
		bool encapsulate(packet PData, MAC sourceAdd, MAC destAdd);
		void unencapsulate(packet* PData, MAC* source, MAC* dest);
		MAC source, dest;
		packet data;
		unsigned char *BFrame;
		/*
		source - 6 bytes
		dest - 6 bytes
		length of data - 2 bytes - unsigned char pointer. if greater than 2 bytes (65535) drop packet.
		packet - 11 - 266 bytes
		*/
	};
};